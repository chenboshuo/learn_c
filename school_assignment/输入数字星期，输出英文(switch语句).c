#include "stdio.h"
/*
输入数字星期，输出英文(switch语句)
时间限制: 1 Sec  内存限制: 12 MB
提交: 56  解决: 1
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

从键盘上输入数字星期，然后输出它的英文。 其对应关系是： 1 Monday 2 Tuesday 3 Wednesday 4 Thursday 5 Friday 6 Saturday 7 Sunday

输入

从键盘输入数字星期，输入数字在1-7之间。

输出

输出该数字对应的英文星期表示。

样例输入

2

样例输出

Tuesday

提示

多组测试数据

来源/分类
*/
int main() {
  int a;
  scanf("%d", a);
  if(a>0 && a<8){
  switch (a) {
    case 1: printf("Monday");break;
    case 2: printf("Tuesday");break;
    case 3: printf("Wednesday");break;
    case 4: printf("Thursday");break;
    case 5: printf("Friday");break;
    case 6: printf("Saturday");break;
    case 7: printf("Sunday");break;
  }
}
  return 0;
}
