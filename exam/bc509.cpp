/*********************************************************
程序要求：
编写程序，输入两个字符串分别存入两个字符数组中，
并比较大小将较大字符串输出。
输入：abc↙
      xy↙
输出：xy
*********************************************************/
#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  char a[200],b[255];
  gets(a);
  gets(b);
  strcmp(a,b)>0?puts(a):puts(b);
  return 0;
}
