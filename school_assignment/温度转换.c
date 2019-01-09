#include "stdio.h"
/*
温度转换（scanf/printf练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 9  解决: 7
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入一个华氏温度，输出摄氏温度，其转换公式为：C=5(F-32)/9。

输入

输入数据只有一个实数，即华氏温度。

输出

输出数据只有一个，即摄氏温度，保留2位小数。

样例输入

32.0

样例输出

0.00
*/
int main() {
  float celsius,fahr;
  scanf("%f", &fahr);
  celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%.2f", celsius);
  return 0;
}
