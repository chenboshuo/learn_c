#include "stdio.h"

/* 利用级数求e
e = 1 + 1/2! + 1/3! .... */
int main() {
  float e, a=1, m=1,i=1;
  while (a>1e-6) {
    a = 1/m*i;
    e += a;
    i++;
    m *= i;
  }
  printf("exp = %f\n", e);
  return 0;
}
