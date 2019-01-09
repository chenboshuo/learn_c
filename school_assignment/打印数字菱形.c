#include "stdio.h"
/*
打印数字图形（for练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 1  解决: 0
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

从键盘输入一个整数n(1≤n≤9),打印出指定的数字图形。

输入

正整数n（1≤n≤9）。

输出

指定数字图形。

样例输入

5

样例输出

    1
   121
  12321
 1234321
123454321
 1234321
  12321
   121
    1

*/
int main() {
  int n,a,j;
  scanf("%d", &n);
  for (a = 0; a < n+1; a++) {
    for (j = 0; j < n-a; j++) {
      printf(" ");
    }
    for (j = 0; j < a; j++) {
      printf("%d" ,j+1);
    }
    for (j = 0; j < a-1; j++) {
      printf("%d",a-1-j);
    }
    printf("\n");
  }

  for ( a = 0; a < n-1 ; a++) {
    for (j = 0; j < a+1; j++) {
      printf(" ");
    }
    for (j = 0; j < n-1-a; j++) {
      printf("%d",j+1);
    }
    for(j=0;j < n-2-a;j++){
    	printf("%d",-j+n-2-a);
	}
    printf("\n");
  }
  return 0;
}
