CC=gcc
DEBUG_FLAGS=-g -Werror

all: dll_example

dll.o: doubly_linked_list.c
	$(CC) -c $< $(DEBUG_FLAGS) -o $@

dll_example: dll.o
	$(CC) $< example.c $(DEBUG_FLAGS) -o $@

clean:
	rm -f dll.o dll_example

.PHONY: clean
