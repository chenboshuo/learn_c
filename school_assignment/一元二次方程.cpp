#include "stdio.h"
#include "math.h"

/*求根公式解一元二次方程
the formula to solve the QUADRATIC EQUATION*/
int main() {
  int a, b, c, delta;
  float x1, x2;
  printf("Enter a,b,c\n");
  scanf("%d,%d,%d", &a, &b, &c);
  delta = b * b - 4*a*c;
  if (delta >= 0) {
    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);
    printf("x1=%.2f\nx2=%.2f\n", x1,x2);

  }
  else{
    printf("UNCOUNTABLE SOLUTIONS");
  }
  return 0;
}
