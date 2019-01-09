#include "stdio.h"
/*统计正负数的个数，输入0结束*/
int main() {
  int a,pos=0,neg=0;
  while (1) {
    //scanf("%d\n", a);
    scanf("%d", &a);
    if (a == 0) break;
    if (a > 0)++pos;
    else neg++;
    }
  printf("positive number have %d\nnegative number have %d", pos, neg);
  return 0;
}
