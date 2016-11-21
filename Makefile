all: default

default: clean build-lib

clean:
	rm -rf libbarrier.so barrier.o barriers_test
build-lib:
	gcc -c -Wall -Werror -fpic -pthread barrier.c
	gcc -shared -o libbarrier.so barrier.o

test: all
	gcc -L`pwd` -Wall -o barriers_test -g -pthread barriers_test.c -lbarrier -Wl,-rpath=`pwd`
	./barriers_test
