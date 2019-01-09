/*stru02 程序的功能是：输入3个职工的工号、姓名、工资，按照工资由小到大的顺序依次输出各人员的信息，请填空。

例如输入：
1001 zhang 8600
1003 wang 7600
1005 zhao  8000
输出：
1003 wang  7600
1005 zhao  8000
1001 zhang 8600
*/
#include<stdio.h>

struct worker
{ int num;
 char name[20];
 int pay;
}per[3];

// 对结构体的内容排序 
void sort(struct worker per[],int n)
{ int i,j;
/**************************************************/ 
     struct worker t;//1.声明变量t，是 struct worker
/**************************************************/ 
 for(i=0;i<n-1;i++)
for(j=0;j<n-1;j++)
 if(per[j].pay>per[j+1].pay)
 {t=per[j];per[j]=per[j+1];per[j+1]=t;}//注意这里是结构体相互交换，所以t只能是结构体
}


 main()
{ int i;
 printf("输入工号、姓名、工资：\n");
 for(i=0;i<3;i++)
/**************************************************/ 
scanf("%d%s%d",&per[i].num,&per[i].name,&per[i].pay);//2. 引用结构体 
/**************************************************/ 
  sort(per,3);//3.传递函数参数 结构体名 per，有3个员工 
/**************************************************/ 
 printf("\n排序结果：\n");
 for(i=0;i<3;i++)
printf("%d %s %d\n",per[i].num,per[i].name,per[i].pay);
}
