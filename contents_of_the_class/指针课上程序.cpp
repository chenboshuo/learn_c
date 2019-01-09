/*指针的玩法*/
#include "stdio.h"

/* 形参  实参        形参  实参   f_1   形参  实参
    x     x=1 --->   x=1   x=1  ---->  x=2   x=1
    y     y=2        y=2   y=2         y=1   x=2
*/
//交换int变量但没有返回值
void f_1(int x,int y) {
  int _;
  _ = x;x=y;y=_;
}
//交换指针指向的值
/* 形参  实参        形参  实参   f_2   形参  实参
    x ----x=1 --->   &x    x=1  ---->  &x    x=2
    y ----y=2        &y    y=2         &y    x=1
*/
void f_2(int *x, int *y) {
  int _;
  _ = *x;*x =*y; *y = _;
}

//交换指针变量
/* 形参  实参        形参  实参   f_3   形参  实参
    x ----x=1 --->   &x    x=1  ---->  &y    x=1
    y ----y=2        &y    y=2         &x    x=2
*/
void f_3(int *x, int *y) {
  int *_;
  _ = x;x=y;y=_;
}
int main(int argc, char const *argv[]) {
  int x=1,y=2;
  printf("%d,%d\n", x, y);// output 1,2
  f_1(x, y);
  printf("%d,%d\n", x, y);// output 1,2
  x=1,y=2;
  f_2(&x, &y);
  printf("%d,%d\n", x, y);// output 2,1
  x=1,y=2;
  f_3(&x,&y);
  printf("%d,%d\n", x, y);// output 1,2
  return 0;
}
