#include "stdio.h"
// 局部变量与全局变量同名时,在局部变量作用范围内,局部有效
// When the local variable is the same name as the global variable,
//  it is locally effective in the range of local variable.
int x = 2;
int f(int a){
  // staic int x = 10;
  static int x = 10;
  printf("line6 %d\n",x);
  x++;
  printf("line8 %d\n", x);
  return x+a;
}


int main(int argc, char const *argv[]) {
  int i;
  for (i = 1; i <=2; i++) {
    printf("f(i) %d\n", f(i));
    printf("for_loop x %d\n", x);
  }
  return 0;
}
// output
// line6 10
// line8 11
// f(i) 12
// for_loop x 2
// line6 11
// line8 12
// f(i) 14
// for_loop x 2
