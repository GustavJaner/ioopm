CFLAGS=-Wall -g

all: db

clean:
	rm -f db cat utils

db: db.c utils.c
	gcc -o $@ -Wall -g -std=c11 db.c utils.c
