#include "stdio.h"

#define IN 1 //在单词之内
#define OUT 0 //在单词之外

/* 统计输入的行数,单词数与字符数
input
this is a test.
this is a test.
^Z
output
2 8 32
  */
int main() {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t'){
      /*
       ||  代表逻辑或 && 代表与,
       由两者组成的表达式从左到右求值
       && 仅仅比||高一个优先级
       */
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  // getchar();
}
