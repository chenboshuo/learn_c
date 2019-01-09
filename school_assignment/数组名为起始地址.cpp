// 数组名为起始地址
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int a[] ={0,1,2};
  printf("%d\n", a);
  printf("%d\n",&a[0] );
  //a++;	lvalue(左值) required as increment(增值) operand(操作数)
  //a 是指针常量,不能放到等式左边
  return 0;
}
