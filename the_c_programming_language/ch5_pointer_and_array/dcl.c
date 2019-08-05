#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define BUFSIZE 100

static char buf[BUFSIZE]; // ungetch函数使用的缓冲区
static int bufp = 0;      // 缓冲区buf的下一个空闲位置

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;           // 最后一个记号类型
char token[MAXTOKEN];    // 最后一个记号的字符串
char name[MAXTOKEN];     // 标识符名
char datatype[MAXTOKEN]; // 数据类型为char,int等
char out[1000];          // 输出串

// 将声明转化为文字描述
int main(int argc, char const *argv[]) {
  while (gettoken() != EOF) { // 该行的第一个记号是数据类型
    strcpy(datatype, token);
    out[0] = '\0';
    dcl(); // 分析其他部分
    if (tokentype != '\n') {
      printf("syntax error\n");
    }
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

/**
 * 对一个声明符进行语法分析
 */
void dcl(void) {
  int ns;

  for (ns = 0; gettoken() == '*';) { // 统计*的个数
    ++ns;
  }
  dirdcl();
  while (ns-- > 0) {
    strcat(out, " pointer to");
  }
}

/**
 * 分析一个直接声明
 */
void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error missing )\n");
    }
  } else if (tokentype == NAME) { // 变量名
    strcpy(name, token);
  } else {
    printf("error: expected name or (dcl)\n");
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}

/**
 * 跳过空格与制表符, 以便查找输入中下一个记号.
 * 记号(token)可以是一个名字, 一对圆括号, 可能包含一个数字的一对方括号,
 * 也可以是任意的单个字符
 * @return  [description]
 */
int gettoken(void) {
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t') {
    ;
  }
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';) {
      ;
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}

/**
 * 取一个字符(也可能是压回一个字符)
 * @return  字符
 *
 * ungetch 把压回的字符放到一个共享缓冲区中(字符数组),
 * 当缓冲区不为空时,getch从缓冲区读取字符,当缓冲区为空时,
 * getch调用getchar()直接读取输入字符
 */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

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
