#include "stdio.h"
/* fibonacci series v1.0*/

int main(int argc, char const *argv[]) {
  int a=1,b=1,i,lens=10;//a,b 为开头数字，lens为长度 
  for (i = 0; i < lens/2; i++) {
    printf("%d %d ", a,b);
    a += b;
    b += a;
  }
  return 0;
}
