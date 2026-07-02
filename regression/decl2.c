#include <stdio.h>

/* Declarations of structs in unusual places */

struct s { int x; };

int f(void) {
  int n = sizeof(struct s { char * name; int x; });
  struct s my_s = {"Hello", 42};
  return my_s.x;
}

int main(void)
{
  printf("%d\n", f());
}
