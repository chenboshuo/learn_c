#include <stdio.h>
/* 统计输入的字符数v1.0 */
main()
{
  long nc;

//  nc = 0
	 nc = 0;
  while (getchar() != EOF){
    ++nc;//执行+1操作
  }
      printf("%ld\n", nc);
}
