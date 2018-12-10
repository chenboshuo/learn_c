#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
/*
#define 名字 替换文本
*/
//打印摄氏度与华氏度的对照表
main()
{
	int fahr;

	for (
	fahr = UPPER;//初始化后执行一次
	 fahr >= LOWER; //测试条件部分
	 fahr = fahr - STEP
	 )
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
 }
