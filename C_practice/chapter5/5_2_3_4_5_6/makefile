GCC = gcc
FLAGS = -Wall -g -O0
OBJS = str.o mystdlib.o
HEADER = mystdlib.h

all: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o str


str.o mystdlib.o: $(HEADER) 

.PHONY: clean
clean:
	rm $(OBJS)
	rm strlen
