#include <stdio.h>
#include <stdlib.h> // to use atoi

int main(int argc, char *argv[]) {

  int totalt=0;

  // if wrong input
  if (argc < 2 || argc > 3) puts("Usage: ./p4 rows growth");

  else {  // atoi = ascii to int
    int rows=(atoi(argv[1])), growth=(atoi(argv[2]));

    for (int i = 1; i <= rows; i++) {
      for(int j=0; j < (growth*i); j++) {
        printf("%c", '#');
        totalt += 1;
      }

      printf("\n");
    }

    printf("totalt: %d\n", totalt);
  }



  return 0;
}
