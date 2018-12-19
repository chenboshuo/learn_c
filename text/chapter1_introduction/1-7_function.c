/* power函数:求底数的n次幂;其中n>=0
output
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
 */
#include "stdio.h"
int power(int m, int n);
/*
  声明表示函数有两个int参数,并返回一个int参数
  这种声明称为函数原型,它必须与power的定义,用法相同
  */

/*测试power函数
  c语言没有求幂运算,编写求幂函数power
  math.h中
 */
int main() {
  int i;

  for ( i = 0; i < 10; ++i) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
  /*
    C语言中,所有参数是都是"通过值"传递的,
    形参可以看成局部变量

    必要时,也可以通过指针修改主函数的值

    如果数组为参数,那需要传递指针
   */
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
