obj-m += device_driver.o
KSRC =/home/user/Workspace/kernel_ws/KSRC

all:
	make -C ${KSRC} M=${PWD} modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
clean:
	make -C ${KSRC} M=${PWD} clean

