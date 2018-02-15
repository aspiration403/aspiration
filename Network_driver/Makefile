INSTALLDIR=modules
ifneq ($(KERNELRELEASE),)
	obj-m := Network_driver.o
	Network_driver-objs :=	init.o	exit_module.o	

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
	rm -rf *.o
	rm -rf modules.order
	rm -rf Module.symvers
endif

