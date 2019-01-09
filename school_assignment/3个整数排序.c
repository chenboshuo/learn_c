#include<stdio.h>
/*
题目描述

从键盘输入三个整数a、b、c，要求将输出的数据按从大到小排序后输出。

输入

从键盘上输入三个整数a、b、c，每个整数之间用空格分开。

输出

从大到小顺序输出a、b、c的值。

样例输入

4 3 5

样例输出

5 4 3

提示

多组测试数据

来源/分类
*/
int main()
{
  int a,b,c,_;
  //scanf("%f,%f,%f",a,b,c);
  scanf("%d %d %d",&a,&b,&c);
  if (a>b) {_ = a;a = b; b=_;}
  if (a > c)
  {_ = c; c = a; a = _;}
  if (b > c)
  {_ = b;b = c;c = _;}
  //printf("%f5.2 < %f5.2 <%5.2",a,b,c);
  printf("%d %d %d",c,b,a);
  return 0;
}
