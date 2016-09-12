// to compile both files: gcc guess.c utils.c -o file -Wall ---> then run ./file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

//************************************
int main() {

  bool correctGuess = false;
  srandom(time(NULL));
  int key = random() % 20;  // random int between 0 and 20
  int guessCount = 0;
  int buf_siz = 20;
  char buf[buf_siz];
  int numb;
  int maxGuess=10;

  ask_question_string("enter your name:", buf, buf_siz);
  printf("%s, i'm thinking of a number.. guess which!\n", buf);

  while(correctGuess == false && guessCount < maxGuess) {

    numb = ask_question_int("enter your guess: ");

    if(numb==key) {
      puts("correct!!");
      correctGuess = true;
    }

    else if(numb < key)
      puts("too small!");

    else if(numb > key)
      puts("too big!");

    guessCount++;
  }

  if(guessCount < maxGuess)
    printf("it took %s %d guesses to find %d\n", buf, guessCount, key);
  else
    printf("out of guesses. The number was %d\n", key);


  return 0;
}
