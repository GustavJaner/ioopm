
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

  int a = atoi(argv[1]), b = atoi(argv[2]);
  int x=a, y=b;

  while(a > 0 && b > 0) {
    if(a == b) {
      printf("gcd(%d, %d) = %d\n", x, y, a); // BASE case
      break;
    }
    else if(a > b) a -= b;

    else if(a < b) b -= a;
  }


  return 0;
}
