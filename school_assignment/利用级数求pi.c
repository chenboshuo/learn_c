#include"stdio.h"
#include "math.h"
/*pi/4 = 1 -1/3  + 1/5 ....*/
int main() {
  float m;
  int i, p, t;
  //p = 0;m = i = t =1
  p = 0;m = i = t =1;
  //while (fabs(t) < 1e-7) {
  while (fabs(t) > 1e-7) {
    t = m/(2*i - 1);
    p += t;
    i++; m *= -1;
    //print("pi = %f", 4*p);
  }
printf("pi = %f", 4*p);
  return 0;
}
