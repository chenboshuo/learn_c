#include "stdio.h"

/* 统计各个数字,空白符及其他字符出现的次数


 */
int main() {
  int c, i, nwhite=0, nother;
  int ndigit[10];// ndigit声明为由10个整形数构成的数组
  for ( i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')//判断 c 是否为数字
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  printf("digits = ");
  for ( i = 0; i < 10; i++)
    printf("%d\n", ndigit[i]);
  printf(", white space = %d, other = %d\n",
      nwhite, nother);
  getchar();
}
