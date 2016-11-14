GCC = gcc
OBJECTS = main.o hello.o world.o test.o

all: $(OBJECTS)
	@$(GCC) $^ -o hello

#main.o:main.c
#	gcc -c main.c
#hello.o:hello.c
#	gcc -c hello.c
#world.o:world.c
#	gcc -c world.c

test:hello.c world.c
	echo $^
	echo $<
	echo $@
install:
	cp hello /usr/bin/ -f
uninstall:
	rm /usr/bin/hello -f
clean:
	rm *.o hello -f


