#include "stdio.h"
/*
1001: A+B for Input-Output Practice (I)（利用while实现多组输入）
时间限制: 1 Sec  内存限制: 128 MB
提交: 23  解决: 8
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

Your task is to Calculate a + b. Too easy?! Of course! I specially designed the problem for acm beginners.  You must have found that some problems have the same titles with this one, yes, all these problems were designed for the same aim.

输入

The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line.

输出

For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input.

样例输入

1 5
10 20

样例输出

6
30
*/
int main() {
  int a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    printf("%d\n", a + b);
  }
  return 0;
}
