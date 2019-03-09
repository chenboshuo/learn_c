#include <stdio.h>

void shellsort(int v[], int n) {
  int gap, i, j, temp;
  for (gap = n/2; gap > 0 ; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int  a[5] = {5,4,3,2,1};
  shellsort(a,5);
  for (int i = 0; i < 5; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}

// output
// 1
// 2
// 3
// 4
// 5
