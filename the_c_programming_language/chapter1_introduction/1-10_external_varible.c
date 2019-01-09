/* 打印最长的输入行
 * input
 * as
 * absd
 * assdd
 * a
 *
 * output
 * assdd
 */
#include "stdio.h"

#define MAXLINE 1000  /*允许输入行的最大长度*/

int max;                /*到目前为止发现的最长行的行数*/
char line[MAXLINE];       /*  当前输入行  */
char longest[MAXLINE];    /* 用于保存最长的行*/

int get_line(void);
void copy(void);

/*打印最长的输入行*/
int main(int argc, char const *argv[]) {
  int len;                  /*当前行的长度*/
  // extern int max;
  // extern char longest[];
  /*
   * 如果外部变量出现在使用之前,可以省略
   */

  max = 0;
  while ((len = get_line()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) {      /*存在这样的行*/
    printf("%s\n", longest);
  }
  return 0;
}


/* gentline函数 */
int get_line(void)
{
  int c,i;
  // extern char line[];

  for (i = 0; i < MAXLINE-1
    && (c=getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}

/* copy函数,特别版*/
void copy(void) {
  int i;
  // extern char line[],longest[];

  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}
