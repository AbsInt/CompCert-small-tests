#include <stdio.h>
#include <wchar.h>
// In some versions of Glibc, <uchar.t> is incompatible with CompCert.
// Just define the two types `char16_t` and `char32_t` as specified in C11
// #include <uchar.h>
#include <stdint.h>
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;

unsigned char c1 = 'a';
char16_t c2 = u'a';;
char32_t c3 = U'a';;
wchar_t c4 = L'a';;

unsigned char d1 = '\xFE';
char16_t d2 = u'\xFE';;
char32_t d3 = U'\xFE';;
wchar_t d4 = L'\xFE';;

unsigned char e1 = '\x1234'; // warning but no error
char16_t e2 = u'\x1234';
char32_t e3 = U'\x1234';
wchar_t e4 = L'\x1234';

unsigned char f1 = 'é';      // CompCert tolerance
char16_t f2 = u'é';
char32_t f3 = U'é';
wchar_t f4 = L'é';

unsigned char g1 = '猫';     // CompCert tolerance + warning
char16_t g2 = u'猫';
char32_t g3 = U'猫';
wchar_t g4 = L'猫';

unsigned char h1 = '🍌';     // CompCert tolerance + warning
char16_t h2 = u'🍌';         // CompCert tolerance + warning
char32_t h3 = U'🍌';
wchar_t h4 = L'🍌';

int m1 = 'ab';
int m2 = '\x01\x02\x03\x04';
int m3 = 'éè';              // CompCert tolerance

#define PRINT(x) printf("%s: %x\n", #x, x)

int main()
{
  PRINT(c1); PRINT(c2); PRINT(c3); PRINT(c4);
  PRINT(d1); PRINT(d2); PRINT(d3); PRINT(d4);
  PRINT(e1); PRINT(e2); PRINT(e3); PRINT(e4);
  PRINT(f1); PRINT(f2); PRINT(f3); PRINT(f4);
  PRINT(g1); PRINT(g2); PRINT(g3); PRINT(g4);
  PRINT(h1); PRINT(h2); PRINT(h3); PRINT(h4);
  PRINT(m1); PRINT(m2); PRINT(m3);
}
