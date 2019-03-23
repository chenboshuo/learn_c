/**
 * strcpy函数: 将指针t指向的字符串复制到s指向的位置
 * 使用指针实现的版本3
 */
#include <stdio.h>

void strcpy(char *s, char *t) {
  while (*s++ = *t++) {
    ;
  }
}

int main(int argc, char const *argv[]) {
  char s[] = "abc";
  char t[] = "1234";

  strcpy(s,t);
  printf("s:  %s\n", s);
  printf("t:  %s\n", t);

  return 0;
}
// output
// s:  1234
// t:  1234
