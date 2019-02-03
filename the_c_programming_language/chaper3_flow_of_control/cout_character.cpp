#include "stdio.h"

/* 统计各个数字,空白符及其他字符出现的次数


 */
int main() {
  int c, i, nwhite=0, nother;
  int ndigit[10];// ndigit声明为由10个整形数构成的数组
  for ( i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF){
    switch (c) {
    case '0':case '1':case '2':case'3':case '4':
    case '5':case '6':case'7':case'8':case'9':
      ndigit[c-'0']++;
      break;
    case ' ':
    case'\n':
    case'\t':
      nwhite++;
      break;
    default:
      nother++;
      break;
    }
  }
  printf("digits = ");
  for ( i = 0; i < 10; i++)
    printf("%d\n", ndigit[i]);
  printf(", white space = %d, other = %d\n",
      nwhite, nother);
  getchar();
}
// input
// 4 0 4
// zsb
// ^Z
// output
// digits = 1
// 0
// 0
// 0
// 2
// 0
// 0
// 0
// 0
// 0
// , white space = 5, other = 3
//
