obj-m	:= virtual_pci.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)

clean:
	rm -rf *.o *~ core .depend *.ko
