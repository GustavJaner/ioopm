
#ifndef __UTILS_H__
#define __UTILS_H__

//*************** TYPE DEFINITION *****************
typedef union {
  int   i;
  float f;
  char *s;
} answer_t;

typedef bool(*check_func)(char *);
typedef answer_t(*convert_func)(char *);

//*************** FUNC DECLARATION ****************
answer_t ask_question(char *question, check_func check, convert_func convert);
int ask_question_int(char *question);
char* ask_question_string(char *question);
int  read_string(char *buf, int buf_siz);
bool is_number(char *str);
//void clear_input_buffer();
bool not_empty(char *str);
void print(char *buf);
void println(char *buf);




#endif
