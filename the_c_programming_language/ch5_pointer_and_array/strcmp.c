/**
 * strcmp函数:
 * 根据s按照字典顺序小于,等于或大于t的结果分别返回负整数,0或正整数.
 * 该返回值是s和t由前向后逐个字符比较时遇到的第一个不相等字符处字符的差值.
 */
#include <stdio.h>

int strcmp(char *s, char *t){
  int i;

  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') {
      return 0;
    }
  }
  return s[i] - t[i];
}
