
all:
	arm-linux-gcc -c test.c -o test.o -fno-builtin
	arm-linux-gcc -c basedevice.c -o basedevice.o -fno-builtin
	arm-linux-gcc -c string.c -o string.o -fno-builtin
	arm-linux-gcc -c _divsi3.S -o _divsi3.o -fno-builtin
	arm-linux-gcc -c _udivsi3.S -o _udivsi3.o -fno-builtin
	arm-linux-ld -Ttest.lds *.o -o test
	arm-linux-objcopy -O binary test test.bin

clean:
	rm -rf  test *.o  test.bin
