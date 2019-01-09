#include "stdio.h"
/*
大小写转换
时间限制: 1 Sec  内存限制: 12 MB
提交: 5  解决: 1
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

把一个字符串里所有的大写字母换成小写字母，小写字母换成大写字母。其他字符保持不变。

输入

输入为一行字符串，其中不含空格。长度不超过80个字符。

输出

输出转换好的字符串。

样例输入

ABCD123efgh

样例输出

abcd123EFGH
*/
int main() {
  char a,b;
  while ((a = getchar()) != EOF) {
    if (a>='a' && a<= 'z') {
      b = a - 32;putchar(b);
    }
    else if (a>='A'&&a<='Z') {
      b = a + 32;putchar(b);
      }
    else
      putchar(a);  
  }
  return 0;
}
