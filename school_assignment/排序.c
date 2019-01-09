#include<stdio.h>
int main()
{
  int a,b,c,_;
  //scanf("%f,%f,%f",a,b,c);
  while(scanf("%d %d %d" ,&a,&b,&c) != EOF)
  {if (a > b) {_ = a;a = b; b=_;}
  if (a > c){_ = c; c = a; a = _;}
  if (b > c){_ = b;b = c;c = _;}
  //printf("%f5.2 < %f5.2 <%5.2",a,b,c);
  printf("%d %d %d",c,b,a);}
  return 0;
}
