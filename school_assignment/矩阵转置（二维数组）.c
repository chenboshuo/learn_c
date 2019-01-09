/*
矩阵转置（二维数组）
时间限制: 1 Sec  内存限制: 12 MB
提交: 4  解决: 2
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入N*N的矩阵，输出它的转置矩阵。

输入

第一行为整数N（1≤N≤100）。 接着是一个N*N的矩阵。

输出

转置矩阵。

样例输入

2
1 2
1 2

样例输出

1 1
2 2

来源/分类
*/
#include "stdio.h"
int main() {
  int n,i,j;
  scanf("%d\n", &n);
  int a[n][n];
  for ( i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for ( j = 0; j < n; j++) {
    for ( i = 0; i < n; i++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
