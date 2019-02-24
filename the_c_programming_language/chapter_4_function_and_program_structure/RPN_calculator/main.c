#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

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
// input
// 1 2 - 4 5 + *
// output
// 1 2 - 4 5 + *
//         -9
