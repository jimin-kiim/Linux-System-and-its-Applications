// #--------- compare_and_swap_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/atomic.h>
#include <linux/delay.h>

#define NUM_THREADS 4
static struct task_struct *threads[NUM_THREADS];
int counter = 0;


static int compare_and_swap_function(void *data)
{
	int original;
	while(!kthread_should_stop()) {
		// critical section
		original = __sync_val_compare_and_swap(&counter, counter, counter + 1);
		// end of the critical section
		printk(KERN_INFO "pid[%u] %s: counter: %d\n", current->pid, __func__, original);
		msleep(500);
	}
	do_exit(0);
}


int __init compare_and_swap_module_init(void) {
	printk("Entering Compare and Swap Module!"); 
	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		threads[i] = kthread_run(compare_and_swap_function, NULL, "compare_and_swap_function");
	}
	return 0;
}

void __exit compare_and_swap_module_cleanup(void) {
	int i;
	for(i = 0; i < NUM_THREADS; i++) {
		kthread_stop(threads[i]);
	}
	printk("Exiting Compare and Swap Module!\n");
}

module_init(compare_and_swap_module_init); 
module_exit(compare_and_swap_module_cleanup); 
MODULE_LICENSE("GPL");
