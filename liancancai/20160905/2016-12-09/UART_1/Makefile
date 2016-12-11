
#项目文件

OBJS+=basedevice.o  _divsi3.o  string.o  test.o  _udivsi3.o
OBJS+=s3c44b0_rtc.o serial_s5p.o serial.o

#交叉编译器
CROSS_COMPILE=arm-linux-
#C标志
CCFLAG=-fno-builtin
#链接脚本
LINK_SCRIPT=test.lds
TARGET=test

${TARGET}.bin:${TARGET}
	${CROSS_COMPILE}objcopy -O binary $^ $@

${TARGET}:${OBJS}
	${CROSS_COMPILE}ld -T${LINK_SCRIPT} $^ -o $@

%.o:%.c
	${CROSS_COMPILE}gcc -c $^ -o $@ ${CCFLAG}
%.o:%.S
	${CROSS_COMPILE}gcc -c $^ -o $@ 


clean:
	rm -rf ${OBJS}  ${TARGET}  ${TARGET}.bin


