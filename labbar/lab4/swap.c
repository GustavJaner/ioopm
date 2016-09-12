
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

void swap(int *a, int *b) {

  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {

  int x = 7;
  int y = 42;

  swap(&x, &y);
  printf("%d, %d\n", x, y);

  return 0;
}

/*
int a = 42;
int *ptr;

ptr  = &a; --> assigns ptr the mem.address of the variable a.
*ptr = 7;  --> assigns 7 to the mem.address where ptr is pointing


int a = 42;  // a innehåller nu heltalet 42
int *b = &a;  // b innehåller nu en adress till där värdet på a finns lagrat
printf("%d, %d\n", a, *b);  // skriver ut 42, 42
a = 7;
printf("%d, %d\n", a, *b);  // skriver ut 7, 7
*b = 42;
printf("%d, %d\n", a, *b);  // skriver ut 42, 42

void string_copy(char *source, char *dest)
{
  for (; *source != '\0'; ++dest, ++source)
  {
    *dest = *source;
  }
}
eller:
void string_copy(char *source, char *dest)
{
  while (*dst++ = *source++) ;
}
*/
