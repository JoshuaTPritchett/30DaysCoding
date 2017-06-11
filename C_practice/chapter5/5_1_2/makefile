GCC = gcc
FLAGS = -g -Wall -O0
OBJS = pointer_functions.o example1.o conio.o
HEADERS = test.h

all: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o pointers
pointer_functions.o: $(HEADERS)
	$(GCC) $(FLAGS) -c pointer_functions.c
conio.o: $(HEADERS) 
example1.o: $(HEADERS)
	$(GCC) $(FLAGS) -c example1.c

.PHONY: clean

clean:
	rm $(OBJS)
