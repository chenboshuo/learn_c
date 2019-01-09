#include "stdio.h"
/*
打印金字塔（for练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 1  解决: 1
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入n值，打印下列形状的金字塔，其中n代表金字塔的层数。

输入
3

输入只有一个正整数n。

输出

打印金字塔图形，其中每个数字之间有一个空格。

样例输入

3

样例输出

    1
  1 2 1
1 2 3 2 1

*/
int main() {
  int n,a,j;
  scanf("%d", &n);
  for (a = 1; a < n+1; a++) {
    for (j = 0; j < 2*n-2*a; j++) {
      printf(" ");
    }
    for (j = 0; j < a; j++) {
      printf("%d ",j+1);
    }
    for (j = 0; j < a-1; j++) {
      printf("%d ", a-1-j);
    }
    printf("\n");
  }

  return 0;
}
