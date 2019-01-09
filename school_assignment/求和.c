#include "stdio.h"
/*
题目描述

从键盘上输入任意一个整数n，计算1到n的和。

输入

从键盘输入任意整数n。

输出

输出1到n的和。

样例输入

3

样例输出

6
*/
int main() {
  int a,s=0,i;
  scanf("%d", &a);
  for (i = 0; i <= a; i++) {
    s += i;
  }
  printf("%d\n", s);
  return 0;
}
