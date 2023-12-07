obj-m          := spinlock_module_final.o 
spinlock_module_final-y := spinlock_module.o ../calclock.o
mutex_module_final-y := mutex_module.o calclock.o
rw_semaphore_module_final-y := rw_semaphore_module.o calclock.o
KERNEL_DIR      := /lib/modules/$(shell uname -r)/build
PWD             := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean               
