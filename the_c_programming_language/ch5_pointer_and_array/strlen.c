#include <stdio.h>

/**
 * 返回字符串的长度
 * @param  s 字符串
 * @return   长度
 */
int strlen(char *s){
  char *p = s;

  for (;*p != '\0'; p++) {
    ;
  }
  return p - s;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", strlen("abc"));
  return 0;
}
// output
// 3
