#include "stdio.h"
/*
最小公倍数和最大公约数
时间限制: 1 Sec  内存限制: 12 MB
提交: 4  解决: 1
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

从键盘输入两个正整数，求这两个正整数的最小公倍数和最大公约数，并输出。

输入

输入包括一行。 两个以空格分开的正整数。

输出

两个整数的最小公倍数和最大公约数。

样例输入

6 8

样例输出

24 2

*/
/*
    更相减损术是出自《九章算术》的一种求最大公约数的算法，
    它原本是为约分而设计的，
    但它适用于任何需要求最大公约数的场合。
*/
int gxjss(int a,int b){
  int _;
  while (a !=b) {
    if (a > b) {
      _ = a;a=b;b=_;
    }
    b -= a;
  }
  return a;
}

int least_common_multiple(int a,int b){
  int c,a1,b1;
  c = gxjss(a,b);
  a1 = a/c;
  b1 = b/c;
  return(c*a1*b1);
}

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  printf("%d %d",least_common_multiple(a, b),gxjss(a,b));
  return 0;
}
