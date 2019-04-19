#include <stdio.h>

/* 回显命令行参数: 版本1 */
int main(int argc, char const *argv[]) {
  while(--argc > 0)
    printf((argc > 1)? "%s ": "%s", *++argv);
  printf("\n");
  return 0;
}
/*
$ print_argv a b 12 as
a b 12 as

 */
