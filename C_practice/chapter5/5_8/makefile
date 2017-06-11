GCC = gcc
FLAGS = -Wall -g -O0
OBJS = main.o day.o

all: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o day
day.o main.o: day.h

.PHONY: clean
clean:
	rm day $(OBJS)
