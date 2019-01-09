#include "stdio.h"
/*
整除（if--else练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 11  解决: 8
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

判断一个数n能否同时被3和5整除。

输入

输入一个正整数n。

输出

如果能够同时被3和5整除，输出Yes，否则输出No。

样例输入

15

样例输出

Yes
*/
int main() {
  int n;
  scanf("%d", &n);
  if(n%3==0&&n%5==0){
    printf("Yes");
  }
  else printf("No");
  return 0;
}
