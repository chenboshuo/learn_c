// n[a] == *(n+a) == *a + n == a[n]
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int a[] = {1,2,3,4};
  printf("%d\n", 3[a]); // output 4
  return 0;
}
