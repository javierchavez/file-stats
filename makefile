all:
	gcc -Wall -ansi -pedantic pwl.c linkedlist.c stats.c -o pwl

clean:
	rm *o pwl

