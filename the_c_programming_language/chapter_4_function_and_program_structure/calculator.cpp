// input   output
// 1
//         1
// 2
//         3
// 4
//         7
// 5
//         12
// 6
//         18
// 7
//         25
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/**
 * 简单计算器
 * 每行读取一个数,进行求和
 */
int main(int argc, char const *argv[]) {
  double sum,atof(char []);
  char line[MAXLINE];
  int getline(char line[], int max);

  sum = 0;
  while (getline(line, MAXLINE) > 0) {
    printf("\t%g\n", sum += atof(line));
  }
  return 0;
}

/**
 * 将一行读入到s并返回其长度
 * @param  s   要写入的字符串
 * @param  lim 最长输入
 * @return     这一行的长度
 */
int getline(char s[], int lim){
  int c,i=0;

  while (--lim > 0 && (c=getchar()) != EOF && c!='\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

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
