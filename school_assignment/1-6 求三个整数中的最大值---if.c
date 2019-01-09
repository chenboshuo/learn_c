#include "stdio.h"
/*
题目描述
编写一个程序，输入a, b, c三个值，输出其中最大者。
输入
输入三个整数a, b, c，以空格分隔。
输出
max=最大数
样例输入
2 -3 9
样例输出
max=9
*/
/*
错因:c没有and运算
main(){
  int a, b, c;
  while(scanf("%d %d %d", &a, &b, &c) != EOF){
    if (a >= b and a >= c) {
      printf("max=%d\n", a);
    }
    else if (b >= c and b>= a) {
      printf("max=%d\n", b);
    }
    else {
      printf("max=%d\n", c);
    }
  }
}
*/
int main() {
  int a, b, c, d;
  while(scanf("%d %d %d", &a, &b, &c) != EOF){
    if (a >= b) {
      d = a;
    }
    else{
      d = b;
    }
    if (c >= d) {
      d = c;
    }
    printf("max=%d\n", d);
  }
  return 0;
}
