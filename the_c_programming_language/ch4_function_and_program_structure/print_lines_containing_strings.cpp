// input
// ah Love! could you and I with Fate conspire
// To grasp this sorry Scheme of things entire,
// Would not we shatter it to bits -- and then
// Re-mould it nearer to Heart's Desire!
//
// output
// ah Love! could you and I with Fate conspire
//
// Would not we shatter it to bits -- and then
//
// Re-mould it nearer to Heart's Desire!
#include "stdio.h"
#define MAXLINE 1000 // 最大输入行长度

int getline(char s[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* 找出与模式匹配的行 */
int main(int argc, char const *argv[]) {
  char line[MAXLINE];
  int found = 0;

  while (getline(line, MAXLINE) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s\n", line);
      found ++;
    }
  }
  return found;
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
int strindex(char s[], char t[]){
  int i, j, k;

  for ( i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      ;
    }
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}
