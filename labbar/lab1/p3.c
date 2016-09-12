#include <stdio.h>

int main(void) {

  int n=5, tot=0;

  for (int i = 1; i < n; i++) {
    for(int j=0; j < i; j++) {
      printf("%c", '#');
      tot += 1;
    }

    printf("\n");
  }

  printf("tot=%d\n", tot);

  return 0;
}
