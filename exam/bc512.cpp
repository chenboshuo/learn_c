/*---------------------------------------------
任意输入两个字符串（使用数组存储，
串长度不超过19个字符，允许出现空格字符，
并且一个串内字符不重复），
求两串中相同的字符（按相同字符在第一个串的先后顺序输出）。
输入：poiuytr
      asofigjkutmn
输出：oiut
----------------------------------------------*/
#include "stdio.h"
int main(int argc, char const *argv[]) {
  char a[19],b[19],s[19],*p,*q,i=0;
  gets(a);
  gets(b);
  for (p=a;*p;p++) {
    for(q=b;*q;q++){
      if (*p==*q) {
        *(s+i) = *p;
        i++;
      }
    }
  }
  *(s+i) = '\0';
  puts(s);
  return 0;
}
