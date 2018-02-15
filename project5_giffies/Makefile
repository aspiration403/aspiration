INSTALLDIR=modules
ifneq ($(KERNELRELEASE),)
	obj-m := raman.o
	raman-objs :=	init.o	exit_module.o	driver_open.o	driver_release.o driver_write.o driver_read.o	trim_scull.o	driver_lseek.o	driver_ioctl.o	driver_proc.o					

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
endif

