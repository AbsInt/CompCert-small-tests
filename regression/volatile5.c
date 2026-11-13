/* Members of volatile structs, unions and arrays are automatically volatile.
   This is best checked by the reference interpreter, which reports
   undefined behavior when accessing volatile storage with a non-volatile
   load or store. */

struct A {
  char y; double z;
};


struct S {
  int x;
  struct A s;
  char t[2];
};

union U {
  int x;
  struct A s;
  char t[2];
};

volatile int vt[10];
volatile struct A va[2];
volatile struct S vs;
volatile union U vu;

int main()
{
  int n;

  vt[0] = 123;  n = vt[9];
  va[1].z = va[0].y + 1;
  vs.x ++;
  vs.s.y = 'c';
  vs.t[1] = vs.t[0] + 1;
  n += vu.x;
  vu.s.y = 123;
  vu.t[0] = vu.t[1] + 1;
  return n;
}
