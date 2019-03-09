/* 标准库中提供了更完善的函数strtol
 * 在标准库<stlib.h>中
 */
#include "stdio.h"
#include <ctype.h>

/**
 * 将字符串转化为 int
 * 如果有空白符,跳过
 * 如果有符号,读取符号;
 * 取整数部分,并且进行转换
 * @param  s 字符串
 * @return   对应整数
 */
int atoi(char s[]){
  int i,n,sign;

  for (i = 0; isspace(s[i]); i++) {// 跳过空白符
    ;
  }
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {// 跳过符号
    i++;
  }


  for (n=0; isdigit(s[i]); i++) {
    n = n*10+s[i]-'0';
  }
  return sign * n;
}

int main(int argc, char const *argv[]) {
  char a[] = "23";
  printf("%d\n", atoi(a));
  char b[] = " -32";
  printf("%d\n", atoi(b));
  return 0;
}
// output
// 23
// -32
