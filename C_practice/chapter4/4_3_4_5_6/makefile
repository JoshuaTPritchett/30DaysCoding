GCC = gcc
FLAGS = -g -Wall -O0
HEADER = calc.h
OBJS = stack.o getop.o getch.o rpn.o

all: $(OBJS) 
	$(GCC) $(FLAGS) $(OBJS) -o rpn 

# Make can also deduce the recipes of source files
#rpn.o: $(HEADER)
#stack.o: $(HEADER)
#getop.o: $(HEADER)
#getch.o: $(HEADER)

#Even better if can just bind them to obj calls
$(OBJS): $(HEADER)

# PHONY target names
# these will never need to be created
# and will prevent conflicts if there is a
# file with the same name that is created

.PHONY: clean
clean:
	rm $(OBJS) rpn
