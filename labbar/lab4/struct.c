
#include <stdio.h>

typedef struct point point_t; // point_t == struct point

//*********************
struct point {
  int x;
  int y;
};

//*********************
point_t translate(point_t p1, point_t p2);
void translateP(point_t *p1, point_t *p2);

//*********************
int main(void) {

  struct point p;
  p.x = 10;
  p.y = -42;
  printf("point p  (x=%d,y=%d)\n", p.x, p.y);

  struct point q = { .x = 99, .y = -88};
  printf("point q  (x=%d,y=%d)\n", q.x, q.y);

  point_t lol = { .x = 10, .y = -42}; // create with typedef
  translateP(&lol, &p);
  printf("point lol(x=%d,y=%d)\n", lol.x, lol.y);

  point_t p1 = { .x = 10 }; // .y is an integer, auto becomes assigned 0.
  printf("point p1 (x=%d,y=%d)\n", p1.x, p1.y);



  return 0;
}

point_t translate(point_t p1, point_t p2) {
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

//********************* with pointers instead
void translateP(point_t *p1, point_t *p2) {
  p1->x += p2->x;
  p1->y += p2->y; // instead of p1.y --> use p1->y. To access a pointer in a struct.
}



/*  struktar har värdesemantik!!! blir kopierade vid anrop. inte reference
Värt att notera med { .x = 10, .y = -42 }-syntaxen är att det är tillåtet att utelämna fält som då får defaultvärden enligt följande:

heltalsfält får värdet 0
flyttalsfält får värdet 0
booleska fält fär värdet false
pekarfält får värdet NULL som betyder att de ännu inte pekar ut något
*/
