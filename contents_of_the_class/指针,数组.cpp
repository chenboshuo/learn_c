#include "stdio.h"
void f(int b[]) {
  int _;
  _ = b[0];b[0]=b[1];b[1]=_;
}
int main(int argc, char const *argv[]) {
  int a[3]={0,1,2};
  for (size_t i = 0; i < 3; i++) {
    printf("%d ", *(a+i));//output 0 1 2
  }
  printf("\n");
  //f(a[3]);<--a[3]是值而形参是地址
  f(a);
  for (size_t i = 0; i < 3; i++) {
    printf("%d ", *(a+i));//output 1 0 2
  }
  return 0;
}
/*  a         f     a
    ↓        -->    ↓
    0  1 2          1 0 2
*/
