// This is the first problem for test.
// Since all we know the ASCII code,
//  your job is simple: Input numbers
//  and output corresponding messages.
// 输入
// The input will contain a list of positive integers separated by whitespaces(spaces, newlines, TABs). Please process to the end of file (EOF). The integers will be no less than 32.
// 输出
// Output the corresponding message. Note there is NOT a newline character in the end of output.
// 样例输入
// 72 101 108 108 111 44
// 32 119 111 114 108 100 33
// 样例输出
// Hello, world!
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int i=0;
  int _,j;
  int a[32];//储存数组
  int *p = a;//尝试用一下指针

  while ((scanf("%d", &_)) != EOF) {
    *(p+i) = _;
    i++;
  }

  // // test
  // _ = 72;
  // *(p+i) = _;
  // i++;
  //
  // // test

  for (j = 0; j < i; j++) {
    printf("%c", *(p+j));
  }
  return 0;
}
