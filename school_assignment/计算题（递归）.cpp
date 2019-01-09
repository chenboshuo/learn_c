/*
计算题（递归）
时间限制: 1 Sec  内存限制: 128 MB
提交: 2  解决: 2
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

一个简单的计算，你需要计算f(m,n)，其定义如下：
当m=1时，f(m,n)=n；
当n=1时，f(m,n)=m；
当m>1,n>1时，f(m,n)= f(m-1,n)+ f(m,n-1)

输入

第一行包含一个整数T（1<=T<=100），表示下面的数据组数。
以下T行，其中每组数据有两个整数m，n（1<=m，n<=2000），中间用空格隔开。

输出

对每组输入数据，你需要计算出f(m,n)，并输出。每个结果占一行。

样例输入

2
1 1
2 3

样例输出

1
7
*/
#include "stdio.h"
int f(int m, int n){
  if (m == 1) {
    return n;
  }
  else if (n==1) {
    return m;
  }
  else{
    return f(m-1,n)+f(m,n-1);
  }
}
int main() {
  int count,m,n,i;
  scanf("%d", &count);
  for (i = 0; i < count; i++) {
    scanf("%d %d", &m,&n);
    printf("%d\n", f(m,n));
  }
  return 0;
}
