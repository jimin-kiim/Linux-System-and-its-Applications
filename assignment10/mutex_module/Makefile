obj-m          :=  mutex_module_final.o 
mutex_module_final-y := mutex_module.o linked_list_impl.o ../calclock.o
KERNEL_DIR      := /lib/modules/$(shell uname -r)/build
PWD             := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean               
