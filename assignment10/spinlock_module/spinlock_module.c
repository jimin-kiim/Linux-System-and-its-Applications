// #--------- spinlock_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/atomic.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include "../calclock.h"

#define NUM_THREADS 4
static struct task_struct *threads[NUM_THREADS];

spinlock_t my_lock;

struct my_node {
	struct list_head list;
	unsigned int data;
};

struct list_head my_list;

unsigned long long count_insert, count_search, count_delete;
unsigned long long time_insert, time_search, time_delete;


void *add_to_list(int thread_id, int range_bound[]) {
	struct timespec localclock[2];	
	struct my_node *first = NULL;

	int i;
	for (i = range_bound[0]; i <= range_bound[1]; i++) {
		struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);
		new->data = i;

		spin_lock(&my_lock);
		getrawmonotonic(&localclock[0]);

		list_add(&new->list, &my_list);

		getrawmonotonic(&localclock[1]);

		calclock(localclock, &time_insert, &count_insert);
		spin_unlock(&my_lock);
		if (first == NULL) first = new;
	}

	printk(KERN_INFO "thread #%d range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	return first;
}

int search_list(int thread_id, void *data, int range_bound[]) {
	struct timespec localclock[2];
	struct my_node *cur = (struct my_node *) data, *tmp;
	spin_lock(&my_lock);

	list_for_each_entry_safe(cur, tmp, &my_list, list) {
		getrawmonotonic(&localclock[0]);
		getrawmonotonic(&localclock[1]);
		calclock(localclock, &time_search,&count_search);
	};
	spin_unlock(&my_lock);
	return 0;
}

int delete_from_list(int thread_id, int range_bound[]) {
	struct my_node *cur, *tmp;
	struct timespec localclock[2];
	list_for_each_entry_safe(cur, tmp, &my_list, list) {
		spin_lock(&my_lock);
		getrawmonotonic(&localclock[0]);
		list_del(&cur->list);
		kfree(cur);

		getrawmonotonic(&localclock[1]);
		calclock(localclock, &time_delete, &count_delete);
		spin_unlock(&my_lock);
	
	};
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

int __init spinlock_module_init(void) {
	printk("Entering Spinlock Module!\n");
	INIT_LIST_HEAD(&my_list);
	spin_lock_init(&my_lock);
	
	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		int* arg = (int*)kmalloc(sizeof(int), GFP_KERNEL);
		*arg = i;
		threads[i] = kthread_run(work_fn, (void*)arg, "thread%d", i);
	}
	return 0;
}

void __exit spinlock_module_cleanup(void) {
	printk(KERN_INFO"%s: Spinlock linked list insert time: %llu ms, count: %llu", __func__, time_insert, count_insert);
	printk(KERN_INFO"%s: Spinlock linked list search time: %llu ms, count: %llu", __func__, time_search, count_search);
	printk(KERN_INFO"%s: Spinlock linked list delete time: %llu ms, count: %llu", __func__, time_delete, count_delete);
	
	int i;
	for(i = 0; i < NUM_THREADS; i++) {
		kthread_stop(threads[i]);
		printk("thread #%d stopped!", i + 1);
	}
	printk(KERN_INFO"%s: Exiting Spinlock Module!\n", __func__);
}

module_init(spinlock_module_init); 
module_exit(spinlock_module_cleanup); 
MODULE_LICENSE("GPL");
