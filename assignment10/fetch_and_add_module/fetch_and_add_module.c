// #--------- fetch_and_add_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/atomic.h>
#include <linux/delay.h>

#define NUM_THREADS 4
static struct task_struct *threads[NUM_THREADS];

static int counter = 0;
static int fetch_and_add_function(void *data)
{
        int original;
        while(!kthread_should_stop()) {
                // critical section
		original = __sync_fetch_and_add(&counter, 1);
                // end of the critical section
                printk(KERN_INFO "pid[%u] %s: counter: %d\n", current->pid, __func__, original);
                msleep(500);
        }
        do_exit(0);
}


int __init fetch_and_add_module_init(void) {
        printk("Entering Fetch and Add Module!");
        int i;
	for (i = 0; i < NUM_THREADS; i++) {
                threads[i] = kthread_run(fetch_and_add_function, NULL, "fetch_and_add_function");
        }
        return 0;
}

void __exit fetch_and_add_module_cleanup(void) {
        int i;
       	for (i = 0; i < NUM_THREADS; i++) {
                kthread_stop(threads[i]);
        }
	printk("Exiting Fetch and Add Module!\n");

}

module_init(fetch_and_add_module_init);
module_exit(fetch_and_add_module_cleanup);
MODULE_LICENSE("GPL");

