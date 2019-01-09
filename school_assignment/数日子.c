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
int month_days(int a,int b,int d){
  switch (b) {
    case 12: d += 30;
    case 11: d += 31;
    case 10: d += 30;
    case 9: d += 31;
    case 8: d += 31;
    case 7: d += 30;
    case 6: d += 31;
    case 5: d += 30;
    case 4: d += 31;
    case 3: if(leap_year(a))d += 29;else d += 28;
    case 2: d += 31;
  }
  return d;
}
int main() {
  int y, m ,d,n,i;
  scanf("%d", &n);
  for ( i = 0; i < n; i++) {
    scanf("%d %d %d",&y,&m,&d );
    d = month_days(y,m,d);
    printf("%d\n",d);
  }

  return 0;
}
