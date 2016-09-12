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
}; typedef struct item item_t;

//******************
void print_item(item_t *vara);
item_t make_item(char *name, char *desc, int price, char *shelf);
item_t input_item();
bool check_shelf(char* shelf);
char* ask_question_shelf(char* question);
char* magick(char** a, char** b, char** c, int rand);
void list_db(item_t *items, int no_items);
void edit_db(item_t* items, int db_siz);

//******************
int main(int argc, char *argv[]) {

  char *array1[] = {"Laser",        "Polka",      "Extra"};
  char *array2[] = {"förnicklad",   "smakande", "ordinär"};
  char *array3[] = {"skruvdragare", "kola",     "uppgift"};

  if (argc < 2) // ** if no argv input **
    printf("Usage: %s number\n", argv[0]);

  else {
    int maxsize = 5;
    item_t db[maxsize];  // Array med plats för 16 varor
    int db_siz = 0; // Antalet varor i arrayen just nu
    int items = atoi(argv[1]); // Antalet varor som skall skapas manuellt

    if(items > 0 && items <= maxsize) {
      for (int i = 0; i < items; ++i) {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item; // start at 0
        ++db_siz; // added after
      }
    }
    else {
      puts("Sorry, must have [1-5] items in database.");
      return 1; // Avslutar programmet! If too big argv[1] entered..
    }

    for(int i = db_siz; i < maxsize; ++i) {
        char *name = magick(array1, array2, array3, 3);
        char *desc = magick(array1, array2, array3, 3);
        int  price = random() % 1337;
        char shelf[] = { random() % ('Z'-'A') + 'A',
                         random() % 10 + '0',
                         random() % 10 + '0',
                         '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item; // adds the random generated item, per item
        ++db_siz; // added after
      }

     list_db(db, db_siz);
     edit_db(db, db_siz);
     list_db(db, db_siz);

  }
  return 0;
}

//******************
void print_item(item_t *vara) {

  printf("Name: %s\nDesc: %s\nPrice: %d\nShelf: %s\n",
          vara->name, vara->desc, vara->price, vara->shelf);
}

//******************
item_t make_item(char *name, char *desc, int price, char *shelf) {

  item_t vara = {name, desc, price, shelf};
  return vara;
}

//******************
item_t input_item() {

  char* name = ask_question_string("enter name of item: ");
  char* desc = ask_question_string("enter desc of item: ");
  int  price = ask_question_int  ("enter price of item: ");
  char* shelf= ask_question_shelf ("enter shelf number: ");

  item_t vara = {name, desc, price, shelf};
  return vara;
}

//******************
char* ask_question_shelf(char* question) {

  char* shelf;

  do {
    shelf = ask_question_string("enter shelf number: ");
  } while(!check_shelf(shelf)); // while not a valid shelf name eg. "a22"

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
void edit_db(item_t* items, int db_siz) {

  int index;
  do {
    index = ask_question_int("enter index of item: ");
  } while (index > db_siz || index <= 0);

  index--; // readjust to normal index

  print_item(&items[index]);

  item_t nanana = input_item();

  items[index] = nanana;
}
