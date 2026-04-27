/* Minimal alignment for global variables */

#include <stdio.h>
#include <stdint.h>

char c2[2];
char c4[4];
char c8[8];
char c16[16];
char _Alignas(16) a16[16];

int alignment(void * p)
{
  return (int)(intptr_t) p;
}

int main()
{
  printf("c2 mod 2 = %d\n", alignment(c2) % 2);
  printf("c4 mod 4 = %d\n", alignment(c4) % 4);
  printf("c8 mod 8 = %d\n", alignment(c8) % 8);
  printf("c16 mod 8 = %d\n", alignment(c16) % 8);
  printf("a16 mod 16 = %d\n", alignment(a16) % 16);
}
