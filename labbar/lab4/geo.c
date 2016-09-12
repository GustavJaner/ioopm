
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*********************
struct point {
  int x;
  int y;
}; typedef struct point point_t; // point_t == struct point

struct rectangle {
  point_t ul;
  point_t lr;
}; typedef struct rectangle rect_t; // rectangle_t == struct rectangle

//*********************
point_t make_point(int a, int b);
rect_t make_rect(int xul, int yul, int xlr, int ylr);
void print_point(point_t *p);
void print_rect(rect_t *r);
void translate(point_t *p1, point_t *p2);
int area_rect(rect_t *r);
bool intersects_rect(rect_t *r1, rect_t *r2);
rect_t intersection_rect(rect_t *r1, rect_t *r2);



//*********************
int main () {
                    //(x,y  x,y)
  rect_t r1 = make_rect(0,2, 2,0);
  rect_t r2 = make_rect(1,3, 3,1);
  print_rect(&r1);

  int area = area_rect(&r1);

  printf("area=%d\n", area);

  printf("%d\n", intersects_rect(&r1, &r2));

  rect_t r0 = intersection_rect(&r1, &r2);

  print_rect(&r0);


  return 0;
}


//*********************
point_t make_point(int a, int b) {

  point_t p = {.x=a, .y=b};

  return p;
}

//*********************
rect_t make_rect(int xul, int yul, int xlr, int ylr) {

  point_t p1 = {.x=xul, .y=yul};
  point_t p2 = {.x=xlr, .y=ylr};

  rect_t r = {.ul=p1, .lr=p2};

  return r;
}

//*********************
void print_point(point_t *p) {

  printf("point(%d,%d)\n", p->x, p->y);
}

//*********************
void print_rect(rect_t *r) {

  puts("rect upper left: ");
  print_point(&r->ul); // arg is a pointer.sends the mem.address of r.ul to func.

  puts("rect lower right: ");
  print_point(&r->lr);
}

//*********************
void translate(point_t *p1, point_t *p2) {
  p1->x += p2->x;
  p1->y += p2->y;
}

//*********************
int area_rect(rect_t *r) {

  point_t p1 = r->ul; point_t p2 = r->lr;

  int base, height, area;
  base   = p2.x - p1.x;
  height = p1.y - p2.y;
  area = base * height;

  return area;
}

//*********************
bool intersects_rect(rect_t *r1, rect_t *r2) {

  point_t p11 = r1->ul; point_t p12 = r1->lr;
  point_t p21 = r2->ul; point_t p22 = r2->lr;

  if((p21.x > p11.x && p21.x < p12.x) ||
     (p22.x > p11.x && p22.x < p12.x) ||
     (p21.y < p11.y && p21.y > p12.y) ||
     (p22.y < p11.y && p22.y > p12.y))
        return true;

  else
        return false;

}

//*********************
rect_t intersection_rect(rect_t *r1, rect_t *r2) {

  point_t p11 = r1->ul; point_t p12 = r1->lr;
  point_t p21 = r2->ul; point_t p22 = r2->lr;



  if(intersects_rect(r1, r1)) {
    int xul = abs(p11.x - p21.x);
    int yul = abs(p11.y - p21.y);
    int xlr = abs(p12.x - p22.x);
    int ylr = abs(p12.y - p22.y);

    return (make_rect(xul, yul, xlr, ylr));
  }

  else
      return (make_rect(0, 0, 0, 0));
}
