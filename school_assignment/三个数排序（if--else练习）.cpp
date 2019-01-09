/* 冒泡法排序,由小到大v1.0*/
#include "stdio.h"

int main() {
  int _,i,j, a[3];
  for ( i = 0; i < 3; i++) {
    scanf("%d,", &a[i]);
  }
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3-i; j++) {
      if (a[j]>a[j+1]) {
        _ = a[j];a[j] = a[j+1];a[j+1] =_;
      }
    }
  }
  for ( i = 0; i < 3; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
