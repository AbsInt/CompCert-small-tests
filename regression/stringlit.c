#include <stdio.h>
#include <wchar.h>
// In some versions of Glibc, <uchar.t> is incompatible with CompCert.
// Just define the two types `char16_t` and `char32_t` as specified in C11
// #include <uchar.h>
#include <stdint.h>
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;

/* Without escapes nor universal character names */

unsigned char s1[] = "aé猫🍌";
unsigned char s2[] = u8"aé猫🍌";
char16_t s3[] = u"aé猫🍌";
char32_t s4[] = U"aé猫🍌";
wchar_t s5[] = L"aé猫🍌";

/* With universal character names */

unsigned char t1[] = "a\u00e9\u732B\U0001F34C";
unsigned char t2[] = u8"a\u00e9\u732B\U0001F34C";
char16_t t3[] = u"a\u00e9\u732B\U0001F34C";
char32_t t4[] = U"a\u00e9\u732B\U0001F34C";
wchar_t t5[] = L"a\u00e9\u732B\U0001F34C";

/* With numerical escapes */

unsigned char e1[] = "a\xe9\350";
unsigned char e2[] = u8"a\xe9\350";
char16_t e3[] = u"a\xe9\350\x732B";
char32_t e4[] = U"a\xe9\350\x732B\x0001F34C";
wchar_t e5[] = L"a\xe9\350\x732B\x0001F34C";

#define PRINT(x) \
  printf("%s: size %u, contents", #x, (int) sizeof(x)); \
  for (int i = 0; x[i] != 0; i++) printf(" %x", x[i]); \
  printf("\n")

int main()
{
  PRINT(s1); PRINT(s2); PRINT(s3); PRINT(s4); PRINT(s5);
  PRINT(t1); PRINT(t2); PRINT(t3); PRINT(t4); PRINT(t5);
  PRINT(e1); PRINT(e2); PRINT(e3); PRINT(e4); PRINT(e5);
  return 0;
}

