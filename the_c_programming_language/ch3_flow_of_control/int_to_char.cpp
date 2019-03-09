#include "stdio.h"
#include <string.h>// strlen
/**
 * 翻转字符串
 * @param s 字符串
 */
void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}

/**
 * 将数字n转换为字符串并保存到s中
 * @param n 数字
 * @param s 保存到这个字符串中
 */
void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {// 记录符号
    n = -n;// 使n成为正数
  }
  i = 0;
  do { // 反序生成数字
    s[i++] = n % 10 + '0'; // 取下一个数字
  } while((n /= 10) > 0); // 删除该数字
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

int main(int argc, char const *argv[]) {
  int a = -24;
  char s[3];
  itoa(a, s);
  puts(s);
  return 0;
}
// output
// -24
