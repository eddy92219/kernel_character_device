obj-m += ioctl.o
KDIR = /lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(shell pwd) modules

	rm -rf *.o .*.cmd *.mod *.mod.c *.symvers *.order

