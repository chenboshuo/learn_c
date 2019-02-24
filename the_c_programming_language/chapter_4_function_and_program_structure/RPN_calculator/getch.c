#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

/**
 * 取一个字符(也可能是压回一个字符)
 * @return  字符
 *
 * ungetch 把压回的字符放到一个共享缓冲区中(字符数组),
 * 当缓冲区不为空时,getch从缓冲区读取字符,当缓冲区为空时,
 * getch调用getchar()直接读取输入字符
 */
int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
}


/**
 * 把字符压回到输入中
 * 标准库提供函数ungetc,将一个字符压回栈中
 * 这里使用了数组,更通用
 * @param c 字符
 */
void ungetch(int c) {
  if (bufp > BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
