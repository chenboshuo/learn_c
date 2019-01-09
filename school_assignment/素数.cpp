#include "stdio.h"
int main(int argc, char const *argv[]) {
  int n,i;
  scanf("%d", &n);
  for ( i = 2; i < n; i++) {
    if (n % i == 0) {
      break;
    }
  }
  if (i == n) {
    printf("this is a prime\n");
  }
  else{
    printf("this is not a prime\n");
  }
  return 0;
}
