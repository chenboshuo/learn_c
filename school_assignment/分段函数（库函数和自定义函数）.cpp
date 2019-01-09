#include "stdio.h"
#include "math.h"
int main() {
  int count,i;
  float x, y;
  scanf("%d", &count);
  for (i = 0; i < count; i++) {
    scanf("%f", &x);
    if (x==0) {
      y = 0;
    }
    else if (x<0) {
      y = fabs(x) + sin(x);
    }
    else if (x>=10) {
      y = pow(x,2);
    }
    else{
      y = log(x)/log(2);
    }
    printf("%.2f\n", y);
  }


}
