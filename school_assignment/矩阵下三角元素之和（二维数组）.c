/*
矩阵的下三角部分包括主对角线和其下方的所有元素

矩阵下三角元素之和（二维数组）
时间限制: 1 Sec  内存限制: 12 MB
提交: 4  解决: 2
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入一个正整数n（1<=n<=10),再输入n*n的矩阵，要求求该矩阵的下三角元素之和。

输入

输入包括n+1行。 第一行为整数n； 接下来的n行为矩阵数据。

输出

矩阵的下三角元素之和。

样例输入

5
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

样例输出

75
*/
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int count, i, j,s=0;
  scanf("%d", &count);
  int a[count][count];
  for ( i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < count; i++) {
    for (j = 0; j <= i; j++) {
      s += a[i][j];
    }
  }
  printf("%d\n", s);
  return 0;
}
