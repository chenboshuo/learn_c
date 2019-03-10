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
}
