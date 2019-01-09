/*
简单字符串比较（字符串函数和字符数组）
时间限制: 1 Sec  内存限制: 128 MB
提交: 2  解决: 2
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

请使用字符串比较函数，比较两个字符串的大小，并按要求输出比较后的结果。字符串最长不超过15个字符。
输入两个字符串str1和str2，如果第一个字符串与第二个字符串相等，输出str1=str2，如果第一个字符串大于第二个字符串，输出str1>str2，如果第一个字符串小于第二个字符串，输出str1 < str2。

输入

第1行为第一个字符串。
第2行为第二个字符串

输出

在一行输出比较后的结果。例如"abc"与"abc"相等，输出为abc=abc，如果"ab"小于"abc”，输出ab < abc。

样例输入

ab
abc

样例输出

ab<abc

来源/分类


*/
#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[]) {
  char str1[100], str2[100];
  int a;
  scanf("%s", str1);
  scanf("%s", str2);
  a = strcmp(str1,str2);//逐个比较字符串的ASCII码值,判断字符串大小
  if (a > 0) {//前者大于后者,返回值大于0
    printf("%s>%s", str1, str2);
  }
  else if (a < 0) {
    printf("%s<%s", str1, str2);
  }
  else{
    printf("%s=%s", str1, str2);
  }
  return 0;
}
