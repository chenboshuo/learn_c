/**
 * strcmp函数:
 * 根据s按照字典顺序小于,等于或大于t的结果分别返回负整数,0或正整数.
 * 该返回值是s和t由前向后逐个字符比较时遇到的第一个不相等字符处字符的差值.
 */
#include <stdio.h>

int strcmp(char *s, char *t){
  for ( ; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

int main(int argc, char const *argv[]) {
  char a[] = "abc";
  char b[] = "cde";

  printf("%d\n", strcmp(a,b));
  return 0;
}
// output
// -2
