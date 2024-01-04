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
#include "../linked_list_impl.h"

#define NUM_THREADS 4
static struct task_struct *threads[NUM_THREADS];

extern unsigned long long count_insert, count_search, count_delete;
extern unsigned long long time_insert, time_search, time_delete;

void set_iter_range(int thread_id, int range_bound[2]) {
	range_bound[0] = thread_id * 250000;
	range_bound[1] = range_bound[0] + 249999;
}

static int work_fn(void *data)
{
	void *ret;
	int range_bound[2];
	int thread_id = *(int*) data;
	set_iter_range(thread_id, range_bound);
	ret = add_to_list(thread_id, range_bound);
	search_list(thread_id, ret, range_bound);
	delete_from_list(thread_id, range_bound);
	
	while(!kthread_should_stop()) {
		msleep(500);
	}
	
	printk(KERN_INFO "thread #%d stopped!\n", thread_id);
	return 0;
}

int __init spinlock_module_init(void) {
	int i;
	
	printk("Entering Spinlock Module!\n");
	INIT_LIST_HEAD(&my_list);
	
	for (i = 0; i < NUM_THREADS; i++) {
		int* arg = (int*)kmalloc(sizeof(int), GFP_KERNEL);
		*arg = i;
		threads[i] = kthread_run(work_fn, (void*)arg, "thread%d", i);
	}
	return 0;
}

void __exit spinlock_module_cleanup(void) {
	int i;

	printk(KERN_INFO"%s: Spinlock linked list insert time: %llu ms, count: %llu", __func__, time_insert, count_insert);
	printk(KERN_INFO"%s: Spinlock linked list search time: %llu ms, count: %llu", __func__, time_search, count_search);
	printk(KERN_INFO"%s: Spinlock linked list delete time: %llu ms, count: %llu", __func__, time_delete, count_delete);
	
	for(i = 0; i < NUM_THREADS; i++) {
		kthread_stop(threads[i]);
		printk("thread #%d stopped!", i + 1);
	}
	printk(KERN_INFO"%s: Exiting Spinlock Module!\n", __func__);
}

module_init(spinlock_module_init); 
module_exit(spinlock_module_cleanup); 
MODULE_LICENSE("GPL");
