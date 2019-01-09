/*
	在字符串s中找出最大的字符放在第一位置上，
	例如：boy&girl
	输出：ybo&girl
 */
#include"stdio.h"
#include"string.h"
int main()
{
	// char[80], *t, max, *w;
	char s[80], *t, max, *w;//原题错,记得改过来,要不运行不了
	t=s;
	gets(t);
	max=*(t++);// 赋初值并之后移动指针
	while(*t!='\0')
	{if(max<*t)
	{max=*t;w=t;}// w记录最大值的位置
	t++;
	}
	t=w;
	// while((1))
	while(t>s)//t没有到最开始,就让t减少
	// {*t=*(t-1);___(2)___;}
	{
		*t=*(t-1);//将t向后移位
		t--;
	}
	*t=max;
	puts(t);
}
