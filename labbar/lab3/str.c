#include <stdio.h>
#include <string.h>

//*************
int string_length(char *str);

//*************
int main(int argc, char *argv[]) {

  if (argc < 2) { // correct amount of argc
    printf("Usage: %s words or string\n", argv[0]);
  }

  else {
    for (int i = 1; i < argc; ++i) {
      int expected = strlen(argv[i]);
      int actual   = string_length(argv[i]);
      printf("strlen(\"%s\")=%d\t\tstring_length(\"%s\")=%d\n",
             argv[i], expected, argv[i], actual);
    }
  }
  
  putchar('\n');return 0;
}

//*************
int string_length(char *str) {

  char c = str[0];
  int counter = 0;

  while(c != '\0') {
    counter++;
    c = str[counter];
  }

  return counter;
}
