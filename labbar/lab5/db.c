#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "utils.h"

//******************
struct item {
  char *name;
  char *desc;
  int price;
  char *shelf;
  int amount;
}; typedef struct item item_t;

//******************
void print_item(item_t* vara);
item_t make_item(char* name, char* desc, int price, char* shelf, int amount);
item_t input_item();
bool check_shelf(char* shelf);
char* ask_question_shelf(char* question);
char* magick(char** a, char** b, char** c, int rand);
void list_db(item_t* items, int no_items);
int ask_index(char* question, int db_siz);
void edit_db(item_t* items, int db_siz);
void print_meny();
char ask_question_menu();
int add_item_to_db(item_t* items, int db_siz);
int remove_item_from_db(item_t* items, int db_siz);
void event_loop(item_t* items, int db_siz);


//******************
int main(int argc, char *argv[]) {

  int maxsize = 5; int db_siz=0;
  item_t items[maxsize];

  items[0] = make_item("hej1", "Lol", 22, "a22", 3); db_siz++;
  items[1] = make_item("hej2", "Lol", 22, "a22", 5); db_siz++;
  items[2] = make_item("hej3", "Lol", 22, "a22", 6); db_siz++;

  event_loop(items, db_siz);

  return 0;
}

//******************
void print_item(item_t *vara) {

  printf("Name: %s\nDesc: %s\nPrice: %d\nShelf: %s\nAmount: %d\n",
          vara->name, vara->desc, vara->price, vara->shelf, vara->amount);
}

//******************
item_t make_item(char *name, char *desc, int price, char *shelf, int amount) {

  item_t vara = {name, desc, price, shelf, amount};
  return vara;
}

//******************
item_t input_item() {

  char* name = ask_question_string     ("enter name of item: ");
  char* desc = ask_question_string     ("enter desc of item: ");
  int  price = ask_question_int       ("enter price of item: ");
  char* shelf= ask_question_shelf      ("enter shelf number: ");
  int amount = ask_question_int ("enter the amount of items: ");

  item_t vara = {name, desc, price, shelf, amount};
  return vara;
}

//******************
char* ask_question_shelf(char* question) {

  char* shelf;

  do {
    shelf = ask_question_string("enter shelf number: ");
  } while(!check_shelf(shelf)); // while not a valid shelf name eg. "a22"

  char c = toupper(shelf[0]);
  shelf[0] = c;
  return shelf;
}

//******************
bool check_shelf(char* shelf) {

  if(strlen(shelf) < 2) // edge case, when only a letter is entered.
    return false;

  if(isalpha(shelf[0]))
    if(is_number(++shelf)) // the ++ is done BEFORE the func call. (next index of the pointer)
      return true; // is_number returns true if entered parameter is only numbers
    else
      return false;

  else
    return false;
}

//******************
char* magick(char** a, char** b, char** c, int rand) {

  char buf[250];
  int i = 0;

  int key1 = random() % rand; // randoms 0-2
  int key2 = random() % rand;
  int key3 = random() % rand;

  for(char* str = a[key1]; *str != '\0'; str++) // keys are constant after they are assigned
    buf[i++] = *str; // next char in buf, incremented AFTER char in str is added.

  buf[i++] = '-';

  for(char* str = b[key2]; *str != '\0'; str++)
    buf[i++] = *str;

  buf[i++] = ' ';

  for(char* str = c[key3]; *str != '\0'; str++)
    buf[i++] = *str;

  buf[i++] = '\0';

  return strdup(buf); // copy the buf to main, otherwise the pointer is cleared after func is done.+
}

//******************
void list_db(item_t *items, int no_items) {

  for(int i=0; i < no_items; i++)
    printf("%d. %s\n", i+1, items[i].name);
}

//******************
int ask_index(char* question, int db_siz) {

  int index;
  do {
    index = ask_question_int(question);
  } while (index > db_siz || index <= 0);
  return index-1;// readjust to normal array index
}

//******************
void edit_db(item_t* items, int db_siz) {

  int index = ask_index("opt which item to edit: ", db_siz);

  print_item(&items[index]);

  item_t nanana = input_item();

  items[index] = nanana;
}

//******************
void print_meny() {

  puts("\n[L]ägga till en vara\n[T]a bort en vara\n[R]edigera en vara\nÅn[g]ra senaste ändringen\nLista [h]ela varukatalogen\n[A]vsluta\n");
}

//******************
char ask_question_menu() {

  char* c;

  print_meny();
  c = ask_question_string("opt: LlTtRrGgHhAa\n");

  while(strlen(c)>1 || (*c!='L' && *c!='l' && *c!='T' && *c!='t' && *c!='R' && *c!='r' && *c!='G' && *c!='g' && *c!='H' && *c!='h' && *c!='A' && *c!='a'))
    c = ask_question_string("opt: LlTtRrGgHhAa\n");

  return toupper(*c);
}

//******************
int add_item_to_db(item_t* items, int db_siz){

  //int index = ask_index(db_siz);
  items[db_siz] = input_item();
  return db_siz+1;
}

//******************
int remove_item_from_db(item_t* items, int db_siz) {

  list_db(items, db_siz);
  int index = ask_index("opt which item to remove: ", db_siz);

  if(index == db_siz-1) // if just the last element will be removed.
    return db_siz-1;

  else {
    for(int i=index; i < db_siz-1; i++)
        items[i] = items[i+1];

    return db_siz-1;
  }
}

//******************
void event_loop(item_t* items, int db_siz) {

  char option;
  do {
    option = ask_question_menu();

    if     (option == 'L')
      db_siz = add_item_to_db(items, db_siz);
    else if(option == 'T')
      db_siz = remove_item_from_db(items, db_siz);
    else if(option == 'R')
      edit_db(items, db_siz);
    else if(option == 'G')
      puts("** NOT YET IMPLEMENTED **");
    else if(option == 'H')
      list_db(items, db_siz);
    else // when option == 'A'
      puts("program ends...");
  } while(option != 'A');
}
