// filename: print_lines_containing_strings.c
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 // 最大输入行长度

int getline(char s[], int lim);

/* 找出与模式匹配的行 */
int main(int argc, char const *argv[]) {
  char line[MAXLINE];
  int found = 0;
if (argc != 2) {
    printf("%s\n", "Usage: find pattern");
  } else {
    while (getline(line, MAXLINE) > 0) {
      if (strstr(line, argv[1]) != NULL) {
        /* 标准库函数`strstr(s,t)`返回一个指针,
          该指针指向字符串t在s中第一次出现的位置,
          如果没有出现s则返回NULL,该函数声明在`<string.h>`中
         */
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
