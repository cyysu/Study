

TARGET=test

OBJS+=test.o  fun.o

${TARGET}:${OBJS}
	gcc	$^ -o $@

%.o:%.c
	gcc	-c $^ -o $@
	
