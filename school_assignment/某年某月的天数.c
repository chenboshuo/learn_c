#include "stdio.h"
/*
某年某月的天数（switch/if--else练习）
时间限制: 1 Sec  内存限制: 12 MB
提交: 2  解决: 1
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

输入年和月，判断该月有几天？

输入

输入年和月，格式为年\月。

输出

输出该月的天数。

样例输入

2009\1

样例输出

31

提示

注意判断闰年啊
*/
int leap_year(int a) {
  if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
    return 1;
  }
  else{
    return 0;
  }
}
int month_days(int a,int b){
  switch (b) {
    case 1: return 31;break;
    case 2: if(leap_year(a))return 29;else return 28;break;
    case 3: return 31;break;
    case 4: return 30;break;
    case 5: return 31;break;
    case 6: return 30;break;
    case 7: return 31;break;
    case 8: return 31;break;
    case 9: return 30;break;
    case 10: return 31;break;
    case 11: return 30;break;
    case 12: return 31;break;
  }
}
int main() {
  int a,b,d;
  scanf("%d\\%d",&a,&b );
  d = month_days(a,b);
  printf("%d",d);
  return 0;
}
