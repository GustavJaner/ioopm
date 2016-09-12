
#include <stdio.h>
#include <string.h>
#include "utils.h"


//****** FUNC DECLARATION ********************
int  ask_question_int(char *question);
void ask_question_string(char *question, char *buf, int buf_siz); //void, since buf is an array
int  read_string(char *buf, int buf_siz);                          // --> reference parameter
void clear_input_buffer();
void print(char *buf);
void println(char *buf);


//***************** MAIN *******************
//int main(int argc, char *argv[]) {

  /*int buf_siz = 5;
  char buf[buf_siz];
  ask_question_string("first string:", buf, buf_siz);
  printf("you entered: %s\n", buf);
  ask_question_string("second string:", buf, buf_siz);
  printf("you entered: %s\n", buf);*/

//  return 0;
//}

//*************** FUNC DEFINITION *********************
int ask_question_int(char *question) {

  int result = 0, conversions = 0;

  do {
      printf("%s\n", question);
                              // stored directly to the mem.adress of the variable
      conversions = scanf("%d", &result);// scanf with %d, will only read integers, dvs leave any char
      //scanf will return a bool, 1 if it read a int(due to%d), or 0 if failed to read an int
      // meanwhile the read int is stored to the mem.address of the variable 'result'

    // *** to remove unwanted chars still left in the keyboard buffer..  ***
      int c;
      do {// eg. if first input is "1a", the 'a' will remain and ruin the next scanf
          c = getchar(); // removes 1 char that is still in the key.buffer
        } while (c != '\n' && c != EOF);// until end of string, until empty
      putchar('\n');//just prints new line..

    } while (conversions < 1); // ensures that an actual number has been entered.
                              // conversions is 0/false until then.
  return result;
}

//*************
void ask_question_string(char *question, char *buf, int buf_siz) {

  int checkEmpty=0;

  do {
    printf("%s\n", question);

    checkEmpty = read_string(buf, buf_siz);

  } while(checkEmpty < 1);
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
  if(i == buf_siz-2) {
    int c;
    do {
        c = getchar();
      } while (c != '\n' && c != EOF);
  }

  buf[i] = '\0'; // null terminated

  return i;// amount of char input;
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
