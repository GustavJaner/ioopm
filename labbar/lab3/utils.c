
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"


//*************** FUNC DEFINITION *********************
answer_t ask_question(char *question, check_func check, convert_func convert) {

  int buf_siz = 10, amountChar;
  char buf[buf_siz];
  bool bl;

  do {
    printf("%s\n", question);
    amountChar = read_string(buf, buf_siz); // > 0  if a string is entered
    bl = check(buf);             // true if a string is entered//or is_number
  } while(bl == false || amountChar < 1); // repeat loop until string of correct type is entered

  return (answer_t) convert(buf); // returns buf converted with correct func().
}

//***************
int ask_question_int(char *question) {
  // is_number --> makes sure the entered string is a number. atoi
  answer_t answer = ask_question(question, is_number, (convert_func) atoi);
  return answer.i; // .i --> svaret som ett heltal, från answer_t...
}

//*************
char *ask_question_string(char *question) {
  // not_empty --> makes sure a string is entered
  return ask_question(question, not_empty, (convert_func) strdup).s;
}

//*************
int read_string(char *buf, int buf_siz) {

  char ch;
  int i=0;

  do {
    ch = getchar();

    if(ch!='\n') {
      buf[i] = ch;
      i++;
    }
  } while(ch != '\n' && i < buf_siz-1);

// CLEAR KEYBOARD BUFFER, if  more chars entered then the buf size
  if(i >= buf_siz-1) {
    int c;
    do {
        c = getchar();
      } while (c != '\n' && c != EOF);
  }

  buf[i] = '\0'; // null terminated

  return i;// amount of char input;
}

//*************
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

//*************
bool not_empty(char *str) {

  return strlen(str) > 0;
}

//*************
void print(char *buf) {

  for(int i=0; buf[i] != '\0'; i++)
    putchar(buf[i]);
}

//*************
void println(char *buf) {

  print(buf);
  putchar('\n');
}
