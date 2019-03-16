/**
 * 函数getint接受自由格式的输入,并执行转换,将输入的字符流分解成整数,
 * 每次调用得到一个整数.getint返回得到的整数,
 * 并且,在到达输入结尾时要返回文件结束的标记.这些值必须通过不同方式返回.
 * EOF可以用任何值表示,也可以用一个输入值表示
 */
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn){
  int c, sign;

  while (isspace(c = getch())) {
    ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-')? -1:1;
  if (c == '+' || c == '-') {
    c = getch();
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if (c !=EOF ) {
    ungetch(c);
  }
  return c;
}

int main(int argc, char const *argv[]) {
  int memo[100] = {0};
  getint(memo);
  for (size_t i = 0; memo[i]; i++) {
    printf("%d\n", memo[i]);
  }
  return 0;
}

/**
 * 输入
 *          567
 * 输出
 * 567
 */


#define BUFSIZE 100
static char buf[BUFSIZE]; // ungetch函数使用的缓冲区
static int bufp = 0; // 缓冲区buf的下一个空闲位置
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
