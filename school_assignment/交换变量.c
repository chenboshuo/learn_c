#include "stdio.h"
/*
题目描述

交换两个变量的值，由终端输入两个整数给变量x、y，然后交换x和y的值后，输出x和y。

输入

从键盘输入两个整数变量x和y；

输出

在交换x、y的值后将x和y输出！

样例输入

4 6

样例输出

6 4

来源/分类
*/
int main() {
  int x, y, _;
  //scanf("%d %d\n", x, y);
  scanf("%d %d", &x, &y);
  _ = x;x = y; y = _;
  printf("%d %d\n", x, y);
  return 0;
}
