GCC = gcc
FLAGS = -g -Wall -O0
OBJS = alloc.o qsort.o read.o main.o


all: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o sort
qsort.o alloc.o read.o main.o: definitions.h
#read.o: qsort.o definitions.h
#	gcc -c qsort.o read.c

.PHONY:clean
clean:
	rm sort $(OBJS)

