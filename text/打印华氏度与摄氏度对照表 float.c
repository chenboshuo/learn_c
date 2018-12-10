#include <stdio.h>
/* 当fahr= 0, 20,,,, 300时,分别
打印华氏度与摄氏度对照表 
浮点数版本
######
c语言的其他数据类型
char  字符,一个短字节
short  短整型
long   长整型
double 双精度浮点型*/
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;   /*温度表下限*/
	upper = 300;   /*温度表上限*/
	step = 20;  /*步长*/
	
	fahr = lower;
	while (fahr <= upper){
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t %6.1f\n", fahr, celsius);
		/*
		%d   按照十进制整数打印
		%6d  按照十进制整数打印,至少6字符宽
		%f   按照浮点数打印
		%6f  按照浮点数打印,至少6字符宽
		%.2f 按照浮点数打印,小数点后有两位小数 
		*/
		fahr = fahr + step;
	} 
 } 
