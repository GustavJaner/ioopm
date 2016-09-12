#include <stdio.h>
#include <stdlib.h>

//************************************
void print_number(int num);

//************************************
int main(int argc, char *argv[]) {

  int t = atoi(argv[1]);

  for(int i=0; i < t; i++) {
    print_number(i);
  }


  return 0;
}

void print_number(int num) {

  if((num%3)==0 && (num%5)==0)
    puts("Fizz Buzz");

  else if((num % 3) == 0)
    puts("Fizz");

  else if((num % 5) == 0)
    puts("Buzz");

  else
    printf("%d\n", num);
}
