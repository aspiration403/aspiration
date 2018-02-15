INSTALLDIR=modules
ifneq ($(KERNELRELEASE),)
	obj-m := pandey.o
#	raman-objs :=	start.o	exit_module.o	request_function.o	transfer_function.o	file_system.o				

else
	KERNDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)
	rm -rf modules.order
	rm -rf Module.symvers
	rm -rf *.o
endif

