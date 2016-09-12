CFLAGS=-Wall -g

all: fib swap utils geo db


clean:
	rm -f fib swap utils geo db

db: db.c utils.c
	gcc -o $@ -Wall -g -std=c11 db.c utils.c
