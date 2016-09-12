#include <stdio.h>

int main(int argc, char *argv[]) {

  char *str = "hello world!!";
  int year = 2016;

  printf("string: %s\t year: %d\n", str, year);


  int x = 1, y = 2;

  printf("x=%d\ny=%d\n*******\n", x, y);

  int tmp = x;
  x = y;
  y = tmp;

  printf("x=%d\ny=%d\n", x, y);


  return 0;
}
