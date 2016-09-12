#include <stdio.h>

//***************** TYPE DEF *******************
typedef int(*int_fold_func)(int, int); // int -> int -> int

//***************** FUNC DECLARATION *******************
long sum(int numbers[], int numbers_siz);
int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f);
int add(int a, int b);

//***************** MAIN *******************
int main() {

  int siz=5, result;
  int arr[]={1,2,3,4,5};

  result = sum(arr, siz);

  printf("result = %d\n", result);

  return 0;
}


//***************** FUNC DEFINITION *******************
long sum(int numbers[], int numbers_siz) {

  long result = 0;

  for (int i = 0; i < numbers_siz; ++i) {
    result = foldl_int_int(numbers, numbers_siz, add);
  }

  return result;
}

//*****************
int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f) {
  int result = 0;

  // Loopa över arrayen och för varje element e utför result = f(result, e)
  for (int i = 0; i < numbers_siz; ++i) {
    result = f(result, numbers[i]); // f() == add(result, numbers[i])!!
  }

  return result;
}

//*****************
int add(int a, int b) {
  return a + b;
}

/*
typedef existerande_typ nytt_namn;

typedef char * string_t;
typedef unsigned int age_t;

typedef int(*int_fold_func)(int, int);

/// En funktion som tar en array av heltal, arrayens längd och
/// en pekare till en funktion f av som har typen Int -> Int -> Int
int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f)
{
  int result = 0;

  // Loopa över arrayen och för varje element 'e' utför result = f(result, 'e')
  for (int i = 0; i < numbers_siz; ++i)
  {
    result = f(result, numbers[i]);
  }

  return result;
}

Låt oss skriva en funktion som adderar två tal:

int add(int a, int b)
{
  return a + b;
}
Eftersom add() är en funktion av typen Int -> Int -> Int
kan den användas tillsammans med foldl_int_int.
För att skicka med en funktion som en parameter skriver du bara funktionens namn,
i detta fall alltså add.
--> f är en funktionsvariabel!!
    Kan vara vilken valid functions som helst. krav: rätt parameter+return värde.*/
