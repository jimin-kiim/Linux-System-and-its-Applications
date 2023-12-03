// #--------- compare_and_swap_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int __init compare_and_swap_module_init(void) {
	printk("Entering Compare and Swap Module!"); return 0;
}

void __exit compare_and_swap_module_cleanup(void) {
        printk("Exiting Compare and Swap Module!\n");
}

module_init(compare_and_swap_init); 
module_exit(compare_and_swap_cleanup); 
MODULE_LICENSE("GPL");
