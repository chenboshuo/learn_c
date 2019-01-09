/*stru04.c  程序的功能是：按学生的姓名查询
其成绩排名和平均成绩，查询时可连续进行，
直到输入"0"时才结束，请填空。
例如输入：liming
   输出：3  liming  89.0
   例如输入：liqing
   输出：2  liqing  96.2
   例如输入：0
   程序运行结束
*/
#include<stdio.h>
#include<string.h>
#define NUM  4
struct student
{  int rank;
   char name[10];
   float score;
};
/******************************************************************************/
struct student stu[]={
  {3,"liming",89.0},
  {4,"zhanghua",78.2},
  {1,"wangming",90.6},
  {2,"liqing",96.2},
};
/******************************************************************************/
int main()
{  char str[10];
   int i;
  do
  { printf("please enter neme:");
	scanf("%s",str);
    for(i=0;i<NUM;i++)
/*************************************************/
	if(strcmp(str,stu[i].name)==0)
/*************************************************/
	  { printf("number  name  score\n");
		printf("%3d%10s%6.1f\n",stu[i].rank,stu[i].name,stu[i].score);
	    break;
	  }
	if(i>=NUM)
		 printf("not found\n");
/*************************************************/
}while(strcmp(str,"0")!=0);
/*************************************************/
}
