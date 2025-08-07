CC=gcc
DEBUG_FLAGS=-g -Werror
CFLAGS=-O2 -march=native

all: dll.o

dll.o: doubly_linked_list.c
	$(CC) -c $< $(DEBUG_FLAGS) -o $@

dll_example: dll.o
	$(CC) $< example.c $(DEBUG_FLAGS) $(CFLAGS) -o $@

clean:
	rm -f dll.o dll_example

.PHONY: clean
