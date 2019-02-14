/**
 * 目标是编写一个具有加减乘除运算的计算器程序,
 * 为了容易实现,我们用逆波兰表示法(Reverse Polish notation，RPN，或逆波兰记法)
 * 来代替中缀表示法.
 * 逆波兰表示法中,所有运算符都在操作数的后面
 * (1-2) * (4+5)
 * 1 2 - 4 5 + *
 * 逆波兰表示法中没有括号,只要知道每个运算符需要几个操作数就不会引起歧义.
 * 实现:
 * 每个操作数都被压入栈中;一个运算符到达后,从中弹出相应项目的操作数,
 * 然后把该运算符作用于弹出的操作数,并把结果压入栈中.例如上面先把1,2压入栈,
 * 然后用两者之差-1取代他们; 然后4,5压入栈中,用9取代他们, 最后取出栈顶的-1,9,
 * 把他们的积-9压入栈顶
 * input
 * 1 2 - 4 5 + *
 * output
 * -9
 *
 */
#include <stdio.h>
#include <stdlib.h> // atof()

#define MAXOP 100 //操作数或运算符的最大长度
#define NUMBER '0' // 标识找到一个数

int getop(char []);
void push(double);
double pop(void);

/* 逆波兰计算器 */
int main(int argc, char const *argv[]) {
  int type;
  double op2;
  char s[MAXOP];


  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-': // + * 满足交换律,次序无关紧要,-,/需要区分顺序
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("%s\n", "error: zero divisor");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
}
  return 0;
}

#define MAXVAL 100 // 栈val的最大深度

int sp = 0; // 下一个空闲栈的位置
double val[MAXVAL]; // 值栈

/**
 * 将f压入栈中
 */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full,can't push\n");
  }
}

/**
 * pop函数,弹出并返回栈顶值
 */
double pop(void){
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void  ungetch(int);

/**
 * 获取下一个运算符或数值操作数
 */
int getop(char s[]){
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c; // 不是数
  }
  i = 0;
  if (isdigit(c)) { // 收集整数部分
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // 用于ungetch的缓冲区
char bufp = 0;

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
