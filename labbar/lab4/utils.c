
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
    bl = check(buf); // true if: is_number, or not_empty..
  } while(bl == false || amountChar < 1); // repeat loop until string of correct type is entered

  return (answer_t) convert(buf); // returns buf converted to correct type, with the convert func().
}

//***************
int ask_question_int(char *question) {
       // .i --> from typedef union{} answer_t --> return an int
  return ask_question(question, is_number, (convert_func) atoi).i;
}

//*************
char *ask_question_string(char *question) {
      // .s --> from typedef union{} answer_t --> return a string
  return ask_question(question, not_empty, (convert_func) strdup).s;
}

//*************
int read_string(char *buf, int buf_siz) {

  char ch;
  int i=0;

  do {
    ch = getchar();

    if(ch!='\n') {
      buf[i] = ch; // adds char for char --> to buf, creating the string
      i++;
    }
  } while(ch != '\n' && i < buf_siz);

// CLEAR KEYBOARD BUFFER, if  more chars entered then the buf size
  if(i >= buf_siz-1)
    clear_input_buffer();

  buf[i] = '\0'; // null terminates buf
  return i;// amount of char input;
}

//*************
bool is_number(char *str) {

    bool lol = true;

    for(int i=0; i < strlen(str); i++) {
      if(i == 0) {
        if(str[i] == '-' && strlen(str) == 1)
          lol = false; // edge case, when only '-' is entered
        if(str[i] != '-' && !isdigit(str[i]))
          lol = false;
      }
      else
        if(!isdigit(str[i]))
          lol = false;

      if(lol == false)
        break; // not a number
    }
    return lol; // only reaches this return if true the entire loop.
}

//*************
void clear_input_buffer() {

  int c;
  do {
      c = getchar();
    } while (c != '\n' && c != EOF);
}

//*************
char *trim(char *str) { // clears 'space' before and after characters

  char *start = str;
  char *end = start + strlen(str)-1; // end of string

  while (isspace(*start)) ++start; // skips to the first not-space char
  while (isspace(*end)) --end;     // same, but from end of string

  char *cursor = str;
  for (; start <= end; ++start, ++cursor) // until start reaches end
    {
      *cursor = *start; // assigns current char in 'start', to 'cursor' pointer.
    }
  *cursor = '\0'; // end the string

  return str; // return str with no spaces before and after
}

//*************
bool not_empty(char *str) {

  return strlen(str) > 0;
}

//*************
void print(char *str) {

  for(; *str != '\0'; str++)
    putchar(*str);
}

//*************
void println(char *buf) {

  print(buf);
  putchar('\n');
}
