// #--------- spinlock_module.c ---------#
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int __init spinlock_module_init(void) {
	printk("simple module"); return 0;
}

void __exit spinlock_module_cleanup(void) {
        printk("Bye Module!\n");
}

module_init(spinlock_module_init); 
module_exit(spinlock_module_cleanup); 
MODULE_LICENSE("GPL");
