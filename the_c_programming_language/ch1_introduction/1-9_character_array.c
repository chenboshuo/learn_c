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

int get_line(char line[], int maxline);
/*
  声明时不必指定长度,因为该数组长度在主函数中设置
  调用get_line函数无法预知输入行的长度,因此需要检查溢出
  copy知道内存行的长度,所以不需要进行错误检查

 */
void copy(char to[], char from[]);

/*打印最长的输入行*/
int main(int argc, char const *argv[]) {
  int len;                  /*当前行的长度*/
  int max=0;                /*到目前为止发现的最长行的行数*/
  char line[MAXLINE];       /*  当前输入行  */
  char longest[MAXLINE];    /* 用于保存最长的行*/

  while ((len = get_line(line, MAXLINE)) > 0) {
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
int get_line(char s[], int lim)
{
  int c,i;
  /*
    这个i跟copy中的i没关系,
    称为局部变量(别的语言成为自动变量)
   */

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

/* copy函数:将from复制到to*/
void copy(char to[], char from[]) {
  int i=0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
