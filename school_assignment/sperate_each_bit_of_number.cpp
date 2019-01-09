#include "stdio.h"
/*输入数字分离各个位数*/

/**
 * 分离数字的每一位
 * @param  number 原始数字
 * @param  bits   指向要存放数据的指针
 *
 * 最终将每一位倒序存放在 bits 中
 */
void every_bit(int number, int*bits){
  while (number) {
    *bits = number % 10;
    bits++;
    number/=10;
  }
}

main(){
  int num,bits[3];
  printf("input a triple-digit number ");
  // scanf("%d", a);
  scanf("%d", &num);
  every_bit(num, bits);
  printf("%d %d %d", bits[2],bits[1],bits[0]);

}
//input
// 123
//output
//1 2 3
