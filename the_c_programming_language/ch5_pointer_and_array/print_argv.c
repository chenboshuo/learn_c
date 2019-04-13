#include <stdio.h>

/* 回显命令行参数: 版本1 */
int main(int argc, char const *argv[]) {
  int i;

  for( i = 0; i < argc; ++i){
    printf("%s%s\n", argv[i], (i < argc-1) ? " ": "");
  }
  printf("\n");
  return 0;
}
/*
$ print_argv 1 2 hello 5
print_argv
1
2
hello
5

 */
