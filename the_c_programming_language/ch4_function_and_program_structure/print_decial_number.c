#include <stdio.h>

/**
 * 打印十进制数
 * @param n 要打印的数
 */
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if(n / 10){
    printd(n/10);
  }
  putchar(n % 10 + '0');
}
int main(int argc, char const *argv[]) {
  int a = -242;
  printd(a);
  return 0;
}
