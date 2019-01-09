#include "stdio.h"
/*
2-3 判断闰年---if---else
题目描述
输入一个2000至2500年间（包含2000年和2500年）的任意年份，判断是否是闰年。
输入
输入一个整数year，表示年份。输入保证2000≤year≤2500。
输出
如果输入的年份是闰年，请输出“leap year”，否则请输出“not leap year”。 请注意不需要输出引号，行尾输出换行。
样例输入
2000
样例输出
leap year

*/
/*
闰年规则
1.能被4整除不能被100整除
2.能被400整除
*/
int main() {
  int a;
  scanf("%d\n", &a);
  if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
    printf("leap year\n");
  }
  else{
    printf("not leap year\n");
  }
  return 0;
}
