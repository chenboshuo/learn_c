/*
 */
#include "stdio.h"

/**
 * 折半查找,输入x与中间值比较,若小于中间值,则在数组的前半部分
 * 查找;否则在后半部分查找,一直进行直到范围为空
 * @param  x 要比较的数
 * @param  v 排好序的数组
 * @param  n 数组长度
 * @return   元素所在位置,不存在返回-1
 */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  int v[4] = {1,2,3,4};
  printf("%d\n", binsearch(2,v,4));
  printf("%d\n", binsearch(0,v,4));
  return 0;
}
// output
// 1
// -1
