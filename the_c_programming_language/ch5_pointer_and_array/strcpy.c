/**
 * strcpy函数: 将指针t指向的字符串复制到s指向的位置
 * 使用数组下标实现的版本
 */
#include <stdio.h>

void strcpy(char *s, char *t) {
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0') {
    i++;
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
