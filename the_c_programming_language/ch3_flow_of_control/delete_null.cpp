#include "stdio.h"
#include <string.h>// strlen
/**
 * 删除字符串尾部的空格,制表,换行
 * @param  s 字符串
 * @return   最后一个字符的索引
 */
int trim(char s[]){
  int n;

  for (n = strlen(s)-1 ; n >= 0; n--) {
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
      break;
    }
  }
  s[n+1] = '\0';
  return n;
}

int main(int argc, char const *argv[]) {
  char s[] = "abc ";
  printf("%d\n",trim(s));
  return 0;
}
// output
// 2
