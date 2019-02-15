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
// output
// 300  148.9
// 280  137.8
// 260  126.7
// 240  115.6
// 220  104.4
// 200   93.3
// 180   82.2
// 160   71.1
// 140   60.0
// 120   48.9
// 100   37.8
//  80   26.7
//  60   15.6
//  40    4.4
//  20   -6.7
//   0  -17.8
