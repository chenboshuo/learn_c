// 老师上课ppt-192
// int a[3][4] ,*p, (*pa)[4]; p = a[0]; pa = a;
// 注意区分下列表达式的含义。
// ① a、*a、**a、a[2]、a+2、*a+2；
// ② p、p++、p+2、*(p+2)、*p+2、p+1*4+2、*(p+2*4)；
// ③ pa、pa++、pa+2、*pa、*pa+2、*(pa+2)、*(*pa+2)、
// *(*(pa+1)+2)。
// 通过指针变量存取数组元素速度快且程序简明。用指针变量
// 作形参，可以允许数组的行数不同。因此数组与指针联系紧
// 密。
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int a[3][4] = {
    {00,01,02,03},
    {10,11,12,13},
    {20,21,22,23},
  };
  int *p=a[0], (*pa)[4] = a;

  //  printf("%d\n", a);
  //  printf("%d\n", a[0]);
  //  printf("%d\n", &a[0][0]);
  // /*a[0],a 都为二维数组行地址*/

  // printf("%d\n", &a[0][0]);
  // printf("%d\n", *a);
  /* &a[0][0]== *a*/

  // printf("**a %d\n", **a);
  // printf("%d\n", a[0][0]);
  //  /* **a==a[0][0]*/

  // printf("%p\n", a[2]);
  // printf("%p\n", a+2);
  // /*a[2]与a+2等效*/

  // printf("%d\n", *a+2==&a[0][2]);
  // /* *a+2==&a[0][2]*/

  // printf("%p\n", p);
  // printf("%p\n", a[0]);
  // printf("%p\n", &a[0]);
  // /*p为首行地址*/

  // printf("%d\n", *p);
  // printf("%d\n", *a[0]);

  // printf("%d\n", p++);
  // printf("%d\n", &a[0]);
  // /*
  // 这里p++是后缀运算，p的值+1但是表达式的值不变
  // x = 1
  // y = x++
  // uyput x=2,y=1
  // */

  // printf("%d\n", ++p);
  // printf("%d\n", &a[0][1]);
  // /* ++p 等效于 a【0】【1】的地址 */

  // printf("%d\n", p+2);
  // printf("%d\n", &a[0][2]);

  // printf("%d\n", *(p+2));
  // printf("%d\n", a[0][2]);

  // printf("%d\n", *p+2==a[0][0]+2);
  // /* *p+2==a[0][0]+2*/

  // printf("%d\n", p+1*4+2);
  // printf("%d\n", p+6);
  // printf("%d\n", &a[1][2]);
  // /* 上面一组值都相等*/

  // printf("%d\n", *(p+2*4));
  // printf("%d\n", *(p+8));
  // printf("%d\n", a[2][0]);

  // printf("%d\n", pa);
  // printf("%d\n", &a[0]);

  // printf("%d\n", ++pa);
  // printf("%d\n", &a[1]);

  // printf("%d\n", pa+2);
  // printf("%d\n", &a[2]);

  // printf("%d\n", *pa);
  // printf("%d\n", a[0]);
  // printf("%d\n", &a[0][0]);

  // printf("%d\n", *pa+2);
  // printf("%d\n", a[0]+2);
  // printf("%d\n", &a[0][2]);

  // printf("%d\n", *(pa+2));
  // printf("%d\n", a[2]);
  // printf("%d\n", &a[2][0]);

  // printf("%d\n", *(*pa+2));
  // printf("%d\n", a[0][2]);

  // printf("%d\n", *(*(pa+1)+2));
  // printf("%d\n", *(*(&a[1])+2));
  // printf("%d\n", *(a[1]+2));
  // printf("%d\n", a[1][2]);

  return 0;
}
