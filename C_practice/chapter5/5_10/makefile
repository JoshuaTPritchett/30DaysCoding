GCC = gcc
FLAGS = -Wall -g -O0
OBJS = main.o stack.o

expr: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o expr
main.o stack.o: defs.h

.PHONY: clean
clean:
	rm $(OBJS) expr
