#include <stdio.h>
#include <stdbool.h>
#include <string.h> // to use strlen()
#include <ctype.h>  // to use isdigit()


//************************************
bool is_number(char *str);

//************************************
int main(int argc, char *argv[]) {

  if(argc > 1 && is_number(argv[1]))
    printf("%s is a number\n", argv[1]);

  else {
    if (argc > 1)
      printf("%s is not a number\n", argv[1]);
    else
      printf("Please provide a command line argument!\n");
  }

  return 0;
}

//************************************
bool is_number(char *str) {
  bool lol = true;

  for(int i=0; i < strlen(str); i++) {

    if(i == 0) {
      if(str[i] == '-' && strlen(str) == 1)
        lol = false; // edge case
      if(str[i] != '-' && !isdigit(str[i]))
        lol = false;
    }

    else
      if(!isdigit(str[i]))
        lol = false;

    if(lol == false)
      break; // not a number
  }

  return lol;
}
