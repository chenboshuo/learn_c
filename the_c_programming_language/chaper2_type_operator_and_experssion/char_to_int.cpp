#include "stdio.h"

/**
 * 将字符串转化为 int
 * @param  s 字符串
 * @return   对应整数
 */
int atoi(char s[]){
  int i,n;

  n=0;
  for (i = 0; s[i] >= '0'&&s[i] <= '9'; i++) {
    n = n*10+s[i]-'0';
  }
  return n;
}

int main(int argc, char const *argv[]) {
  char a[] = "23";
  printf("%d\n", atoi(a));
  return 0;
}
// output 23
