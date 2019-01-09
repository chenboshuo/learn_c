#include "stdio.h"
/*
题目描述
计算两个整数的和，即任务是计算a+b。
输入
输入包含一系列的a和b对，通过空格隔开。一对a和b占一行。
输出
对于输入的每对a和b，你需要依次输出a、b的和。 如对于输入中的第二对a和b，在输出中它们的和应该也在第二行。
样例输入
1 5
10 20
样例输出
6
30

*/
main()
{
  int a, b;
  while(scanf("%d %d",&a,&b)!=EOF)
  {
    printf("%d\n\n", a+b);
  }
  return 0;
}
