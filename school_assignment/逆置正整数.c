#include "stdio.h"
/*
逆置正整数（%、/ 练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 7  解决: 4
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入一个三位正整数，将它反向输出。

输入

3位正整数。

输出

逆置后的正整数。

样例输入

123

样例输出

321

提示

注意130逆置后是31
*/
int main(int argc, char const *argv[]) {
  int a,x1,x2,x3,x;
 // scanf("%d", a);
 scanf("%d", &a);
 x1 = a / 100;
 x2 = a / 10 % 10;
 x3 = a % 10;
 x = x1 +x2*10+x3*100;
 printf("%d", x);
  return 0;
}
