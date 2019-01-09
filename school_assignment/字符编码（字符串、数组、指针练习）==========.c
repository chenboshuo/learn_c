
/*
字符编码（字符串、数组、指针练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 7  解决: 4
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

请将一串长度为5的纯字母文本译成一个密码，密码规律如下：用原来的字母后面的第4个字母代替原来的字母。如C用G代替（文本中不存在W/w、X/x、Y/y、Z/z等字母），最后得到的文本即为密码。

输入

输入一串文本，长度固定为5。

输出

输出对应的密码。格式为： password is 密码

样例输入

China

样例输出

password is Glmre
*/
#include "stdio.h"
int main() {
  char a;
  a = getchar();
  a ++;
  putchar(a);

  return 0;
}
