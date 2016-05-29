CFLAGS=-Wall -Wextra -pedantic -std=gnu99 -O2 -s

all: all-the-onions

%: %.c
	gcc ${CFLAGS} -o $@ $^

clean:
	-rm allonions
