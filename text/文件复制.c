#include<stdio.h>
/* 将输入复制到输出,版本1 */
main()
{
	int c;
	
	c = getchar();
	while (c != EOF){
		putchar(c);
		c = getchar();
	}
 } 
