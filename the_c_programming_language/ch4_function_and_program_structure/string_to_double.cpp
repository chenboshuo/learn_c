#include <ctype.h>
#include <stdio.h>

/**
 * 把字符串转成双精度浮点数
 * @param  s 字符串
 * @return   对应双精度浮点数
 */
double atof(char s[]){
  double val, power;
  int i,sign;

  for (i = 0; isspace(s[i]); i++) {// 跳过空白符
    ;
  }
  sign = (s[i] == '-') ? -1: 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0 ;isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
}


int main(int argc, char const *argv[]) {
  char a[] = "-12.0";
  printf("%lf\n", atof(a));
  return 0;
}
// output
// -12.000000
