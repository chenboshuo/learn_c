// 原题是查看运行结果
# include"stdio.h"
void fun(int *w)
{
  static int j=0;//静态变量只定义一次
  do{
    // test
    printf("j=%d\n", j);
    // test
    w[j]+=w[j+1];
  } while(++j<2);
}

main()
{
  int k,a[10]={1,2,3,4,5};
  for(k=1;k<3;k++){
    fun(a);
    // test
    for (int i = 0; i < 5; i++) {
      printf("%d", a[i]);
    }
    printf("\n");
    // test
  }
  for(k=0;k<5;k++) printf("%d",a[k]);
  printf("\n");
  return 0;
}
