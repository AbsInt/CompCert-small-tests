/* __builtin_memcpy of various sizes and alignments */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char src[128], dst[128];

void fill(size_t sz)
{
  for (size_t i = 0; i < sz; i++) src[i] = rand();
}

void check(size_t sz, size_t al)
{
  if (memcmp(src, dst, sz) != 0)
    printf("FAILURE: size = %z, alignment = %z\n", sz, al);
}

#define TEST(sz, al) \
  fill(sz); __builtin_memcpy_aligned(dst, src, sz, al); check(sz, al)

int main()
{
  TEST(1, 1); 
  TEST(2, 1); TEST(2, 2); 
  TEST(3, 1); 
  TEST(4, 1); TEST(4, 2); TEST(4, 4); 
  TEST(5, 1); 
  TEST(6, 1); TEST(6, 2); 
  TEST(7, 1); 
  TEST(8, 1); TEST(8, 2); TEST(8, 4); TEST(8, 8); 
  TEST(9, 1); 
  TEST(10, 1); TEST(10, 2); 
  TEST(11, 1); 
  TEST(12, 1); TEST(12, 2); TEST(12, 4); 
  TEST(13, 1); 
  TEST(14, 1); TEST(14, 2); 
  TEST(15, 1); 
  TEST(16, 1); TEST(16, 2); TEST(16, 4); TEST(16, 8); 
  TEST(17, 1); 
  TEST(18, 1); TEST(18, 2); 
  TEST(19, 1); 
  TEST(20, 1); TEST(20, 2); TEST(20, 4); 
  TEST(21, 1); 
  TEST(22, 1); TEST(22, 2); 
  TEST(23, 1); 
  TEST(24, 1); TEST(24, 2); TEST(24, 4); TEST(24, 8); 
  TEST(25, 1); 
  TEST(26, 1); TEST(26, 2); 
  TEST(27, 1); 
  TEST(28, 1); TEST(28, 2); TEST(28, 4); 
  TEST(29, 1); 
  TEST(30, 1); TEST(30, 2); 
  TEST(31, 1); 
  TEST(32, 1); TEST(32, 2); TEST(32, 4); TEST(32, 8); 
  TEST(33, 1); 
  TEST(34, 1); TEST(34, 2); 
  TEST(35, 1); 
  TEST(36, 1); TEST(36, 2); TEST(36, 4); 
  TEST(37, 1); 
  TEST(38, 1); TEST(38, 2); 
  TEST(39, 1); 
  TEST(40, 1); TEST(40, 2); TEST(40, 4); TEST(40, 8); 
  TEST(41, 1); 
  TEST(42, 1); TEST(42, 2); 
  TEST(43, 1); 
  TEST(44, 1); TEST(44, 2); TEST(44, 4); 
  TEST(45, 1); 
  TEST(46, 1); TEST(46, 2); 
  TEST(47, 1); 
  TEST(48, 1); TEST(48, 2); TEST(48, 4); TEST(48, 8); 
  TEST(49, 1); 
  TEST(50, 1); TEST(50, 2); 
  TEST(51, 1); 
  TEST(52, 1); TEST(52, 2); TEST(52, 4); 
  TEST(53, 1); 
  TEST(54, 1); TEST(54, 2); 
  TEST(55, 1); 
  TEST(56, 1); TEST(56, 2); TEST(56, 4); TEST(56, 8); 
  TEST(57, 1); 
  TEST(58, 1); TEST(58, 2); 
  TEST(59, 1); 
  TEST(60, 1); TEST(60, 2); TEST(60, 4); 
  TEST(61, 1); 
  TEST(62, 1); TEST(62, 2); 
  TEST(63, 1); 
  TEST(64, 1); TEST(64, 2); TEST(64, 4); TEST(64, 8); 
  TEST(65, 1); 
  TEST(66, 1); TEST(66, 2); 
  TEST(67, 1); 
  TEST(68, 1); TEST(68, 2); TEST(68, 4); 
  TEST(69, 1); 
  TEST(70, 1); TEST(70, 2); 
  TEST(71, 1); 
  TEST(72, 1); TEST(72, 2); TEST(72, 4); TEST(72, 8); 
  TEST(73, 1); 
  TEST(74, 1); TEST(74, 2); 
  TEST(75, 1); 
  TEST(76, 1); TEST(76, 2); TEST(76, 4); 
  TEST(77, 1); 
  TEST(78, 1); TEST(78, 2); 
  TEST(79, 1); 
  TEST(80, 1); TEST(80, 2); TEST(80, 4); TEST(80, 8); 
  TEST(81, 1); 
  TEST(82, 1); TEST(82, 2); 
  TEST(83, 1); 
  TEST(84, 1); TEST(84, 2); TEST(84, 4); 
  TEST(85, 1); 
  TEST(86, 1); TEST(86, 2); 
  TEST(87, 1); 
  TEST(88, 1); TEST(88, 2); TEST(88, 4); TEST(88, 8); 
  TEST(89, 1); 
  TEST(90, 1); TEST(90, 2); 
  TEST(91, 1); 
  TEST(92, 1); TEST(92, 2); TEST(92, 4); 
  TEST(93, 1); 
  TEST(94, 1); TEST(94, 2); 
  TEST(95, 1); 
  TEST(96, 1); TEST(96, 2); TEST(96, 4); TEST(96, 8); 
  TEST(97, 1); 
  TEST(98, 1); TEST(98, 2); 
  TEST(99, 1); 
  TEST(100, 1); TEST(100, 2); TEST(100, 4); 
  TEST(101, 1); 
  TEST(102, 1); TEST(102, 2); 
  TEST(103, 1); 
  TEST(104, 1); TEST(104, 2); TEST(104, 4); TEST(104, 8); 
  TEST(105, 1); 
  TEST(106, 1); TEST(106, 2); 
  TEST(107, 1); 
  TEST(108, 1); TEST(108, 2); TEST(108, 4); 
  TEST(109, 1); 
  TEST(110, 1); TEST(110, 2); 
  TEST(111, 1); 
  TEST(112, 1); TEST(112, 2); TEST(112, 4); TEST(112, 8); 
  TEST(113, 1); 
  TEST(114, 1); TEST(114, 2); 
  TEST(115, 1); 
  TEST(116, 1); TEST(116, 2); TEST(116, 4); 
  TEST(117, 1); 
  TEST(118, 1); TEST(118, 2); 
  TEST(119, 1); 
  TEST(120, 1); TEST(120, 2); TEST(120, 4); TEST(120, 8); 
  TEST(121, 1); 
  TEST(122, 1); TEST(122, 2); 
  TEST(123, 1); 
  TEST(124, 1); TEST(124, 2); TEST(124, 4); 
  TEST(125, 1); 
  TEST(126, 1); TEST(126, 2); 
  TEST(127, 1); 
  TEST(128, 1); TEST(128, 2); TEST(128, 4); TEST(128, 8); 
  printf("Test passed\n");
}
