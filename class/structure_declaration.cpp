// 结构体是将不同数据类型组织在一起的有机整体
#include "stdio.h"
int main(int argc, char const *argv[]) {
  struct student{
    int num;
    char name[20];
  }a[2] = {101,"lihua",102,"liming"};
  printf("%d\n", a[1].num);// output 102
  printf("%s\n", a->name);//output lihua
  return 0;
}
