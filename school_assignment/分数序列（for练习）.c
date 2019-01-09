#include "stdio.h"
/*
分数序列（for练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 3  解决: 3
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

有一个分数序列：2/1, 3/2, 5/3, 8/5, 13/8, …编写程序求出这个序列的前n项之和。
                0
输入

输入只有一个正整数n，1≤n≤10。

输出

输出该序列前n项和，结果保留小数后6位。

样例输入

3

样例输出

5.166667

来源/分类
*/
float fibonacci(n)
{
  if (n<=2) {
    return 1.0;
  }
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}
int main() {
  int i,n;float s=0.0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    s += (fibonacci(i+3)/fibonacci(i+2));
  }
  printf("%.6f\n", s);
  return 0;
}
