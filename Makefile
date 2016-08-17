CFLAGS=-Wall -Wextra -pedantic -std=gnu99 -O2 -s

default: all-the-onions

onion.o: onion.c
	gcc ${CFLAGS} -c $^

all-the-onions: all-the-onions.c onion.o
	gcc ${CFLAGS} -o all-the-onions $^

clean:
	-rm *.o all-the-onions
