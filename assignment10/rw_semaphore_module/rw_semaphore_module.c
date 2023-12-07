// #--------- rw_semaphore_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/atomic.h>
#include <linux/delay.h>
#include <linux/rwsem.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include "calclock.h"

#define NUM_THREADS 4
static struct task_struct *threads[NUM_THREADS];

struct rw_semaphore lock;

struct node {
        struct list_head list;
        unsigned int data;
};

struct list_head list;

unsigned long long count_insert, count_search, count_delete;
unsigned long long time_insert, time_search, time_delete;


void *add_to_list(int thread_id, int range_bound[]) {
        struct timespec localclock[2];
        struct node *first = NULL;

        int i;
        down_write(&lock);
        for (i = range_bound[0]; i < range_bound[1] + 1; i++) {
                struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
                new->data = i;

                getrawmonotonic(&localclock[0]);

                list_add(&new->list, &list);

                getrawmonotonic(&localclock[1]);

                calclock(localclock, &time_insert, &count_insert);
                if (first == NULL) first = new;
        }
        up_write(&lock);

        printk(KERN_INFO "thread #%d range: %d ~ %d\n",thread_id, range_bound[0], range_bound[1]);
        return first;
}

int search_list(int thread_id, void *data, int range_bound[]) {
        struct timespec localclock[2];
        struct node *cur = (struct node *) data, *tmp;
        down_read(&lock);

        list_for_each_entry_safe(cur, tmp, &list, list) {
                if (range_bound[0] <= cur->data && cur->data <= range_bound[1]) {
                        getrawmonotonic(&localclock[0]);
                        getrawmonotonic(&localclock[1]);
                        calclock(localclock, &time_search,&count_search);
                }
        };
        up_read(&lock);
        return 0;
}
int delete_from_list(int thread_id, int range_bound[2]) {
        struct node *cur, *tmp;
        struct timespec localclock[2];
        down_write(&lock);
        list_for_each_entry_safe(cur, tmp, &list, list) {
                getrawmonotonic(&localclock[0]);
                list_del(&cur->list);
                kfree(cur);

                getrawmonotonic(&localclock[1]);
                calclock(localclock, &time_delete, &count_delete);


        };
        up_write(&lock);
        return 0;
}

void set_iter_range(int thread_id, int range_bound[2]) {
        range_bound[0] = thread_id * 250000;
        range_bound[1] = range_bound[0] + 249999;
}
static int work_fn(void *data)
{
        int range_bound[2];
        int thread_id = *(int*) data;
        set_iter_range(thread_id, range_bound);

        void *ret = add_to_list(thread_id, range_bound);
        search_list(thread_id, ret, range_bound);
        delete_from_list(thread_id, range_bound);

        while(!kthread_should_stop()) {
                msleep(500);
        }

        printk(KERN_INFO "thread #%d stopped!\n", thread_id);
        return 0;
}

int __init rw_semaphore_module_init(void) {
        printk("Entering RW Semaphore  Module!\n");
        INIT_LIST_HEAD(&list);
        init_rwsem(&lock);

        int i;
        for (i = 0; i < NUM_THREADS; i++) {
                int* arg = (int*)kmalloc(sizeof(int), GFP_KERNEL);
                *arg = i;
                threads[i] = kthread_run(work_fn, (void*)arg, "thread%d", i);
        }
        return 0;
}

void __exit rw_semaphore_module_cleanup(void) {
        printk(KERN_INFO"%s: RW Semaphore linked list insert time: %llu ms, count: %llu", __func__, time_insert, count_insert);
        printk(KERN_INFO"%s: RW Semaphore linked list search time: %llu ms, count: %llu", __func__, time_search, count_search);
        printk(KERN_INFO"%s: RW Semaphore linked list delete time: %llu ms, count: %llu", __func__, time_delete, count_delete);

        int i;
        for(i = 0; i < NUM_THREADS; i++) {
                kthread_stop(threads[i]);
                printk("thread #%d stopped!", i + 1);
        }
        printk(KERN_INFO"%s: Exiting RW semaphore Module!\n", __func__);
}

module_init(rw_semaphore_module_init);
module_exit(rw_semaphore_module_cleanup);
MODULE_LICENSE("GPL");

                                         





