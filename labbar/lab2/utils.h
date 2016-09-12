
#ifndef __UTILS_H__
#define __UTILS_H__

int  ask_question_int(char *question);
void ask_question_string(char *question, char *buf, int buf_siz);
int  read_string(char *buf, int buf_siz);
void clear_input_buffer();

#endif
