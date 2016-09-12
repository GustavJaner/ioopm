#include <stdio.h>
#include <stdlib.h>
#include <math.h> // to use: sqrt
#include <stdbool.h> // to use booleans

int main(int argc, char *argv[]) {
  // if wrong input

  if (argc == 0 || argc > 2) puts("Usage: ./p5 integer");

  else {
    int N     = (atoi(argv[1]));
    int limit = floor(sqrt(N)) + 2;

    bool lol  = false;

    for(int x=2; x <= limit; x++) {
      for(int y=2; y <= N; y++) {
        if (x*y == N) lol = true;
      }
      if(lol) {
        printf("%d is NOT prime number.\n", N);
        break; // breaks entire loop
      }

      else if(x == limit) printf("%d is a prime number", N);
    }
  }


  printf("\n");

  return 0;
}
