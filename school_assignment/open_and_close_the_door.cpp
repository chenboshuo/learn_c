// 18蓝桥校内预选赛3
// 旅馆里有100个房间,从1到100,第一个服务员把所有房门打开了,
// 第2个服务员把所有编号是2的倍数的房间做了相反处理;
// 第3个服务员把所有编号是3的倍数的房间做了相反处理...
// 之后每个服务员都是如此,问100个服务员过来后,那些门是开着的
// -1 为关,1为开
#include "stdio.h"

void operate(int *p,int n) {
  int i;
  for (i = 1; i < 101; i++) {
    if (i % n == 0) {
      *(p+i-1) *= -1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int door[100];
  int i;
  for (i = 0; i < 100; i++) {
    *(door+i) = -1;
  }

  for (i = 1; i < 101; i++) {
    operate(door,i);
  }
  // operate(door,1);
  for (i = 1; i < 101; i++) {
    if(*(door+i-1) == 1){
      printf("%d ", i);
    }
  }
  return 0;
}
