

OBJS+=basedevice.o  s3c44b0_rtc.o  string.o  test.o

OBJS+=_divsi3.o  _udivsi3.o
CROSS_COMPILE=arm-linux-
CCFLAG=-fno-builtin
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
	rm -rf ${OBJS} ${TARGET} ${TARGET}.bin




