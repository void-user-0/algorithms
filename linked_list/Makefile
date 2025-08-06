CC=gcc
OPTIMIZE_FLAGS=-O2 -march=native
DEBUG_FLAGS=-ggdb3

all: linked_list

linked_list.o: linked_list.c
	$(CC) -c $< $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS) -o $@
linked_list: linked_list.o
	$(CC) $< main.c -o $@

clean:
	rm linked_list.o linked_list

.PHONY: clean
