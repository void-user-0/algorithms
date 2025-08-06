CC=gcc
OPTIMIZE_FLAGS=-O2 -march=native
DEBUG_FLAGS=-g -Werror -Wpedantic

all: ll.o

ll.o: linked_list.c
	$(CC) -c $< $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS) -o $@
	
ll_example: ll.o
	$(CC) $< example_usage.c -o $@

clean:
	rm -f ll.o ll_example

.PHONY: clean
