// 各位数字之和排序（一维数组）
// 时间限制: 1 Sec  内存限制: 12 MB
// 提交: 43  解决: 26
// [提交] [状态] [讨论版] [命题人:外部导入]
// 题目描述
// 给定n个正整数，根据各位数字之和从小到大进行排序。
//
// 输入
// 输入数据有多组，每组数据占一行，每行的第一个数正整数n，
// 表示整数个数，后面接n个正整数。当n为0时，不作任何处理，输入结束。n<=10
//
// 输出
// 输出每组排序的结果。
//
// 样例输入
// 2 1 2
// 3 121 10 111
// 0
//
// 样例输出
// 1 2
// 10 111 121
//
// 来源/分类
#include "stdio.h"

// 求和
int sum(int *p,int len) {
  int i,s = 0;
  for ( i = 0; i < len; i++) {
    s += *(p + i);
  }
  return s;
}

// 提取各个数位的值
void every_bit(int a,int *pbit){
  int i;
  for (i = 0; ; i++) {
    *(pbit+i) = a % 10;
    if((a /= 10) == 0){
      break;
    }
  }
}

// 伪冒泡排序改进
// 比较和的大小并调换数据位置
// p:数据
// s:各个位置和
void bubble_sort_(int *p,int *s,int len) {
  int _,i, j;
  for (i = 0; i < len-1; i++) {
    for (j = 0; j < len-1-i; j++) {
      if (*(s+j) > *(s+j+1)) {
        _ = *(p+j);*(p+j) = *(p+j+1);*(p+j+1) =_;
        _ = *(s+j);*(s+j) = *(s+j+1);*(s+j+1) =_;
      }
    }
  }
}

// 各位数字之和排序
int main(int argc, char const *argv[]) {
  while (1) {
    int len;//存储数组长度

    scanf("%d", &len);
    if (len == 0) {
      break;
    }

    int p[len];//原数
    int s[len];//保存每位数的和
    int _[len];// 无关的中间变量

    for (int i = 0; i < len; i++) {
      scanf("%d", p+i);
      every_bit(*(p+i),_);//提取每一位
      *(s+i) = sum(_,len);//将每一位保存到数组s
    }
    bubble_sort_(p, s, len);
    for (int i = 0; i < len; i++) {
      printf("%d ", *(p+i));
    }
  }
  return 0;
}

