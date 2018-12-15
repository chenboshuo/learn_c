#include "stdio.h"
int power(int m, int n);
/*
声明表示函数有两个int参数,并返回一个int参数
这种声明称为函数原型
*/

/*
测试power函数
c语言没有求幂运算,编写求幂函数power
 */
int main() {
  int i;

  for ( i = 0; i < 10; ++i) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
  return 0;
}


/* power函数:求底数的n次幂;其中n>=0 */
int power(int base, int n){//power的参数只对内部有效
//函数圆括号出现的称为形参,调用中出现的为实参
  int i, p;

  p = 1;
  for ( i = 1; i <= n; ++i) 
    p = p * base;
  return p;
  
}
