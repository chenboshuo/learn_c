/**
 * 从数列中挑出一个元素，称为 “基准”（pivot）;
 * 重新排序数列，所有元素比基准值小的摆放在基准前面，
 * 所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
 * 在这个分区退出之后，该基准就处于数列的中间位置。
 * 这个称为分区（partition）操作；
 *
 * 递归地（recursive）把小于基准值元素的子数列
 * 和大于基准值元素的子数列排序；
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 以递增的顺序对v[left]...v[right]排序
 * @param v     数组
 * @param left  最左边的索引值
 * @param right 最右边的索引值
 */
void qsort_(int v[], int left, int right) {
  int i,last;
  void swap(int v[], int i, int j);

  if (left >= right) {// 若数组元素少于2个
    return;// 不执行任何操作
  }
  swap(v, left, (left+right)/2);// 将划分为子集的元素
  last = left;// 移动到v[0]
  for (i = left+1; i <= right; i++) {// 划分子集
    if (v[i] < v[left]) {
      swap(v, ++last, i);// 恢复子集的元素
    }
  }
  swap(v, left, last);
  qsort_(v, left, last-1);
  qsort_(v, last+1, right);
}

/**
 * 交换v[i],v[j]两个数
 * @param v 数组
 * @param i 要交换的数字
 * @param j 要交换的数字
 */
void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/**
 * 为了调用库qsort函数的比较函数
 * @param  a 指针
 * @param  b 指针
 * @return   比较大小的结果
 */
int cmpfunc(const void *a,const void*b) {
  return (*(int*)a -*(int*)b);
}

int main(int argc, char const *argv[]) {
  int v[4] = {4, 3, 2, 1};
  qsort_(v,0,3);
  for (int i = 0; i < 4; i++) {
    printf("%d\n", v[i]);
  }

  // 调用库函数
  int a[4] = {3,4,6,1};
  qsort(a, 4 , sizeof(int), cmpfunc);
  printf("\n");
  for (int i = 0; i < 4; i++) {
    printf("%d\n", a[i]);
  }

  return 0;
}
// output
// 1
// 2
// 3
// 4
// 
// 1
// 3
// 4
// 6
