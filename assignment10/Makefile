obj-m           := compare_and_swap_module.o test_and_set_module.o fetch_and_add_module.o
KERNEL_DIR      := /lib/modules/$(shell uname -r)/build
PWD             := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean               
