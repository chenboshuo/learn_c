// 18蓝桥杯校内 5.众数问题
// 问题描述
// 给定含有n个元素的多重集合S,
// 每个元素在S中出现的次数称为该元素的重数。
// 多重集S中重数最大的元素称为众数。
// 例如, S={1,2,2,2.3,5}.多重集s的众数是2,其重数为3.
// 对于给定的n个自然数组成的多重集S,计算s的众数及其重数。
// 数据输入:
//  6 1 2 2 2 3 5
//  结果输出:
//   2 3


#include "stdio.h"
int main(int argc, char const *argv[]) {
  int count,i,j;
  int m_frequency=0;//存储众数的频率
  int mode;//Mode 众数
  scanf("%d ", &count);

  int s[count];

  for (i = 0; i < count; i++) {
    scanf("%d", s+i);
  }

  for (i = 0; i < count; i++) {
    int i_times=0;
    for (j = 0; j < count; j++) {
      if (*(s+j)==*(s+i)) {
        i_times++;
      }
    }
    if (i_times>m_frequency) {
      m_frequency = i_times;
      mode = *(s+i);
    }
  }
  printf("%d %d", mode,m_frequency);
  return 0;
}
