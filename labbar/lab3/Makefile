CFLAGS=-Wall -g

all:


clean:
	rm -f fib funktionsp str utils exp guess

exp: exp.c utils.c
	gcc -o $@ -Wall -std=c11 exp.c utils.c

guess: guess.c utils.c
	gcc -o $@ -Wall -std=c11 guess.c utils.c
