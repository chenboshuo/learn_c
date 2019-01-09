/*stru05.c 程序的功能是：
输入n个职工的工号、姓名、工资，
求出其中工资最高与最低的职工并输出，请填空。
例如输入：
4
1001 liming  7800
1002 zhaohu  4500
1003 gaonin  6000
1004 lihong  3500
输出：
工资最高职工:1001 liming  7800
工资最低职工:1004 lihong  3500
*/
#include<stdio.h>

struct worker{
  int num;
  char name[10];
  float salary;
};


main()
{ int i,n;
  struct worker  wor,hig,low;
  hig.salary=0;low.salary=10000;
  printf("\nplaese input worker'nuber n:");
  scanf("%d",&n);
  printf("plaese input worker'data:\n");
  for(i=0;i<n;i++)
  {
/*******************************************************************/
	// scanf("%d%s%f",(1));
  scanf("%d%s%f",&wor.num,&wor.name, &wor.salary);
/*******************************************************************/
    // if(wor.salary>hig.salary)  hig=(2);
    if(wor.salary>hig.salary)  hig=wor;
/*******************************************************************/
	// if(wor.salary<low.salary)  low=(3);
  if(wor.salary<low.salary)  low=wor;
/*******************************************************************/
  }
  printf("工资最高职工:%6d%10s%6.0f\n",hig.num,hig.name,hig.salary);
  printf("工资最低职工:%6d%10s%6.0f\n",low.num,low.name,low.salary);

}
