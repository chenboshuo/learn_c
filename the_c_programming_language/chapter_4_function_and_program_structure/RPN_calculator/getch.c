#include <stdio.h>
#define BUFSIZE 100
static char buf[BUFSIZE]; // ungetch函数使用的缓冲区
static int bufp = 0; // 缓冲区buf的下一个空闲位置
/*
 * 要将对象指定为静态存储,可以在对象之前加上关键字`static`作为前缀,
 * 其他函数不能访问buf与bufp,因此两个名字不会和同一文件其他相同名字冲突.
 */

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
