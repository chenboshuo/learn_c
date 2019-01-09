#include "stdio.h"
/*
1-3-2 求两个整数中的较大者(2)----if
题目描述
输入一系列的以空格分隔的整数对a和b，分别输出这两个数中较大的那一个。
输入
输入包含一系列的a和b对，通过空格隔开。一对a和b占一行。
输出
对于输入的每对a和b，你需要依次输出a和b的较大值。 如对于输入中的第二对a和b，在输出中它们的较大者应该也在第二行。
样例输入
3 8
11 6
-3 2
样例输出
8
11
2
提示
#include<stdio.h>

int main()

{

	int a,b;

	//只要不是文件结尾End-Of-File。

	//循环读取每行数据，输出结果，。

	while(scanf("%d %d",&a,&b)!=EOF)

	{

	}

	return 0;

}
*/
int main() {
  int a,b;

	//只要不是文件结尾End-Of-File。

	//循环读取每行数据，输出结果，。

	while(scanf("%d %d",&a,&b)!=EOF)

	{	if (a >= b) {
    printf("%d\n", a);
  }
    else{
 //     printf("%d\n", b)
      printf("%d\n", b);
    }
	}

  return 0;
}
