/*----------------------------------------------------
统计从键盘输入的字符串中大写字母的个数。
输入的字符串可能包含空格。
输入： abGshXf
输出： num=2
----------------------------------------------------*/
#include "stdio.h"
int main(int argc, char const *argv[]) {
  char a[100],*p;
  int num = 0;
  gets(a);
  for (p=a;*p;p++) {
    if (*p>='A'&&*p<='Z') {
      num++;
    }
  }
  printf("num=%d\n", num);
  return 0;
}
