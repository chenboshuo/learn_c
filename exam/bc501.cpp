/*------------------------------------------------------
请编写程序，从键盘上输入10个整数，放在数组中，
要求计算最大数和最小数的差。
说明：10个数用空格分隔。
输入： 8  3  10  34  1  22  7  9  12  23
输出： dif=33
----------------------------------------------------*/
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int i,a[10],*max=a,*min=a;
  for (i = 0; i < 10; i++) {
    scanf("%d", a+i);
    if (*(a+i)>*max) {
      max = a+i;
    }
    if (*(a+i)<*min) {
      min = a+i;
    }
  }
  printf("dif=%d\n", *max-*min);
  return 0;
}
