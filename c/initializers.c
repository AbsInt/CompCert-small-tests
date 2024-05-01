#include <stdio.h>

char x1 = 'x';

int x2 = 12345;

double x3 = 3.14159;

char x4[4] = { 'a', 'b', 'c', 'd' };

int x5[10] = { 1, 2, 3 };

struct { int y; int z; } x6 = { 4, 5 };

struct { int y; char z; } x7 = { 6, 'u' };

struct { char y; int z; } x8 = { 'v', 7 };

struct { char y[9]; double z; } x9 = { { 'a', 'b' }, 2.718 };

struct {
  struct { char y; int z; } u;
  double v;
} x10 = { { 'v', 7 }, 2.718 };

float x11 = 1 + 1 / 3.14159;

double x12 = 1 / 3.14159 + 1;

typedef enum { AAA , BBB } MyEnum;

const MyEnum x13[2] = { AAA, BBB };

int * x14 = &x2;

struct { char * y; int * z; float * u; double * v; } x15 = { x4, x5, &x11, &x12 };

int main(int argc, char ** argv)
{
  int i;

  printf("x1 = '%c'\n", x1);
  printf("x2 = %d\n", x2);
  printf("x3 = %.5f\n", x3);
  printf("x4 = { '%c', '%c', '%c', '%c' }\n",
         x4[0], x4[1], x4[2], x4[3]);
  printf("x5 = { ");
  for (i = 0; i < 10; i++) printf("%d, ", x5[i]);
  printf("}\n");
  printf("x6 = { %d, %d }\n", x6.y, x6.z);
  printf("x7 = { %d, '%c' }\n", x7.y, x7.z);
  printf("x8 = { '%c', %d }\n", x8.y, x8.z);
  printf("x9 = { { ");
  for (i = 0; i < 9; i++) printf("'%c', ", x9.y[i]);
  printf("}, %.3f }\n", x9.z);
  printf("x10 = { { '%c', %d }, %.3f }\n",
         x10.u.y, x10.u.z, x10.v);
  printf("x11 = %.10f\n", x11);
  printf("x12 = %.10f\n", x12);
  printf("x13 = { %d, %d }\n", x13[0], x13[1]);
  if (x14 == &x2) printf("x14 ok\n"); else printf("x14 error\n");
  if (x15.y == x4 && x15.z == x5 && x15.u == &x11 && x15.v == &x12)
    printf("x15 ok\n");
  else
    printf("x15 error\n");
  return 0;
}

