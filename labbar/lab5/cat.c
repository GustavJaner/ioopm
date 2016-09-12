
#include <stdio.h>

void cat(char *filename) {

  FILE *f = fopen(filename, "r");
  int c = fgetc(f);
  int i = 1;

  while(c != EOF) {

    if(i==1)
      printf("%d\t", i++);

    fputc(c, stdout); //stdout --> output to terminal!

    if(c == '\n' && c != EOF)
      printf("%d\t", i++);

    c = fgetc(f);
  }

  fclose(f);
}

int main(int argc, char *argv[]) {
  if (argc < 2)
  {
    fprintf(stdout, "Usage: %s fil1 ...\n", argv[0]); //stdout --> output to terminal!
  }
  else
  {
    for (int i = 1; i < argc; ++i)
    {
      cat(argv[i]);
    }
  }

  return 0;
}

/*
Funktionen fopen() tar som input två strängar -- den första är filnamnet och den andra beskriver hur filen skall öppnas. För läsning: "r", för skrivning "w", och "a" för append. fopen() returnerar en FILE * -- dvs. en pekare till en fil som kan användas för att läsa från/skriva till beroende på hur filen öppnades ("r", etc.).
fclose() stänger en öppen fil.
fprintf() fungerar som printf() men är inte låst till stdout -- printf(...) är ekvivalent med fprintf(stdout, ...). Alltså, fprintf(fil, ...) skriver ut på filen fil.
fgetc(fil) läser ett tecken från filen fil.
fscanf(fil, ...) läser som scanf() fast från filen fil.
etc.
*/
