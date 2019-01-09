/*stru01.c   程序的功能是：
结构数组中存有三人的姓名和年龄，
以下程序输出三人中最年长者的姓名和年龄，请填空。
例如输出：zhangping  20
*/
#include<stdio.h>
struct man
{ char name[20];
  int age;
}per[]={"liming",18,"wanghua",19,"zhangping",20};
int main()
{
  int i,old,temp;
/****************************/
  // (1)
  old = per[0].age;
/****************************/
   for(i=0;i<3;i++)
/****************************/
   {if(per[i].age>old)
      // old=(2)
      old= per[i].age,
      /*
      我把这里改成,表达式运算,这样就可以视为一条语句
      不知能否通过
       */
      temp=i;
   }
/****************************/
   // printf("%s %d\n",(3));
   printf("%s %d\n",per[temp].name, old);
/****************************/
}
