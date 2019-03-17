#include <stdio.h>

/**
 * 返回字符串的长度
 * @param  s 字符串
 * @return   长度
 */
int strlen(char *s){
  int n;

  for (n = 0; *s != '\0'; s++) {
    n++;
  }
  return n;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", strlen("abc"));
  return 0;
}
// output
// 3
