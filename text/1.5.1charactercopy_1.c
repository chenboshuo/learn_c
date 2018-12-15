#include<stdio.h>
/*
标准库的输入输出模型
	输入输出按照字符流的方式处理,
	文本流是多行字符构成的字符序列,每行行末是个换行符
 */

/* 将输入复制到输出,版本1 */
main()
{
	int c;
	/*
	c必须足够大,除了存储任何可能字符之外还要存储EOF
	 */

	c = getchar();
	/*
	一次读一个字符
	 */
	while (c != EOF){
		putchar(c);
		c = getchar();
	}
 }
