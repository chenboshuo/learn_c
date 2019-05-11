// filename: print_lines_containing_strings.c
/**
 * 假定允许程序带两个参数, 其中一个表示"打印除匹配模式之外的所有行",
 * 另一个参数表示"每个文本行前面加上相应行号"
 * UNIX系统中C语言有一个公共约定: 以负号开头的参数表示一个可选标志或参数.
 * 假定用 `-x`(表示除...之外)打印所有与模式不匹配的文本行,用`-n`(代表行号),
 * 那么下面的命令
 * ~~现在看出起名字的艺术了吧,原文里起名时find,多简洁~~
 * print_lines_containing_strings -x -n
 * 将打印所有与模式不匹配的行, 并在每个打印行前面加上行号.
 * 可选参数可以以任意次序出现, 同时, 程序的其余部分应该与命令行参数数目无关.
 * 此外, 如果可选参数能够组合使用, 将会给使用者带来更大方便
 * print_lines_containing_strings -nx 模式
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 // 最大输入行长度

int getline(char s[], int lim);

/* 找出与模式匹配的行 */
int main(int argc, char const *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while (c = *++argv[0]) {
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        defaut:
          printf("%s\n", "print_lines_containing_strings: illeagal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
    }
  }

  // 循环完成后, argc表示还没有处理的参数数目

  if (argc != 1) {
    printf("%s\n", "Usage: print_lines_containing_strings -x -n");
  } else {
    while (getline(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        /* 标准库函数`strstr(s,t)`返回一个指针,
          该指针指向字符串t在s中第一次出现的位置,
          如果没有出现s则返回NULL,该函数声明在`<string.h>`中
         */
        if (number)
          printf("%ld\n", lineno);
        printf("%s\n", line);
        found ++;
      }
    }
  }
  return found;
}

/**
 * 将一行读入到s并返回其长度
 * @param  s   要写入的字符串
 * @param  lim 最长输入
 * @return     这一行的长度
 */
int getline(char s[], int lim){
  int c,i=0;

  while (--lim > 0 && (c=getchar()) != EOF && c!='\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
/*
$ print_lines_containing_strings ad
$ administrator
administrator

$ adv
adv

$ asdd
$ cbs
$ ^Z
 */
