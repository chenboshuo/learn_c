#include "stdio.h"
/**/
int main() {
  int a, i=2;
  scanf("%d", &a);
  while (i < a) {
    if (a % i == 0) {
      printf("no\n");
      //break
      break;
    }
    i++;

  }
  if (a == i) {
      printf("yes\n");
    }
  }
