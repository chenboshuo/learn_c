#include "stdio.h"
#define MAXLINE 255  /*允许输入行的最大长度*/

int gentilne(char line[], int maxline);
void copy(char to[], char from[]);

/*打印最长的输入行*/
int main(int argc, char const *argv[]) {
  int len;                  /*当前行的长度*/
  int max= 0;                /*到目前为止发现的最长行的行数*/
  char line[MAXLINE];       /*  当前输入行  */
  char longest[MAXLINE];    /* 用于保存最长的行*/

  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {      /*存在这样的行*/
    printf("%s\n", longest);
  }
  return 0;
}


/* gentline函数: 将一行读入到s并返回其长度*/
int getline(char s[], int lim)
{
  int c,i;

  for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = 0;
  return i;
}
