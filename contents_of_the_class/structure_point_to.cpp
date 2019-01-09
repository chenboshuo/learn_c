// 结构体指针
#include "stdio.h"

int main(int argc, char const *argv[]) {
  struct student{
    int num;
    char name[20];
  }s[2]={1,"lihua",10,"liming"},*p=s;
  // 以下语句运行结果是单个语句运行的结果

  // printf("%d\n",++p -> num);// output 2
  // printf("%d\n", ++(p -> num));// output 2

  //先对p+1,再引用
  // printf("%d\n", (++p) -> num);// output 10

  // printf("%d\n", p++ -> num);// output 1
  // printf("%d\n", (p++)->num);// output 1

  int b[3] = {310, 320, 330};
  int c[2] = {210, 220};
  struct {
    int x;
    int *y ;
  }a[2]={1,b,10,c}, *q=a;

  // // 表示y所指的内容
  // printf("%d\n", *q -> y);//output 310

  // // 指向y的内容后,y自增
  // printf("%d\n", *q -> y++);
  // printf("%d\n", *a -> y);
  // // output
  // // 310
  // // 320

  // // 自增y指的内容
  // printf("%d\n", ++*q -> y);//output 311

  // 自增y指的内容
  printf("%d\n", (*q -> y)++);
  printf("%d\n", *q -> y);
  // output
  // 310
  // 311

  // // 访问y所指的内容后q自增
  // printf("%d\n", *q++->y);
  // printf("%d\n", *q->y);
  // // output
  // // 310
  // // 210

  return 0;
}
