#include <stdio.h>
#include <stdlib.h>


int fib(int num);


int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s number\n", argv[0]);
  }

  else {
    int n = atoi(argv[1]);

    if (n < 2)
      printf("fib(%d) = %d\n", n, n);

    else
      printf("fib(%s) = %d\n", argv[1], fib(n));
  }

  return 0;
}

int fib(int num) {
  int sum;

  switch(num) {
    case 0 : return 0;
    case 1 : return 1;
    default : sum = (fib(num - 1) + fib(num - 2));
  }

  return sum;
}
