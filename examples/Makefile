#obj-m := ex01_module.o

#obj-m := ex02_module.o

#obj-m := ex03_exporting_symbols.o
#obj-m += ex03_using_symbols.o

obj-m := ex04_module_param.o

#obj-m := ex05_char_drv.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean


