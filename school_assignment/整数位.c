#include<stdio.h>
/*输出数字的每一位，位数小于五 v1.0*/
int main() {
  //int x, w, x1, x2, x3, x4,x5
  int x, w, x1, x2, x3, x4,x5;
  scanf("%d",&x);
  if (x<10) w = 1;
  else if(x<100) w = 2;
    else if (x<1000) w = 3;
      else if (x<10000)w = 4;
        else w = 5;
  x5 = x % 10;
  x1 = x / 10000;
  x2 = x / 1000 % 10;
  x3 = x / 100 % 10;
  x4 = x / 10 % 10;
  printf("%d-digit\n", w);
  switch (w) {
    case 5:printf("%d ", x1);
    case 4:printf("%d ", x2);
    case 3:printf("%d ", x3);
    case 2:printf("%d ", x4);
    case 1:printf("%d ", x5);
  }
  return 0;
}
