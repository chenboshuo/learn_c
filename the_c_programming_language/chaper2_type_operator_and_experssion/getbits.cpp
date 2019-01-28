#include "stdio.h"

// 返回x从p位(从0开始数)开始的n位
unsigned getbits(unsigned x,int p, int n){
  return (x >> (p+1-n) & ~(~0 << n));
}
/* 函数中x>>(p+1-n)把希望获得的字段移到最右端
 * ~0的所有位都是1,左移n位,后n位都是0,取反
 * 这样就建立了右边n位都是0的屏蔽码
 */
int main(int argc, char const *argv[]) {
  int a = 166; //二进制10100110
  printf("%d\n", getbits(a,4,3));// output 1
  return 0;
}
