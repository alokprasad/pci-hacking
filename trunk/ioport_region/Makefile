obj-m	:= ioport.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)

clean:
	rm -rf *.o *~ core .depend *.ko Module.symvers modules.order ioport.mod.c
