/**
 * 考虑这样一个问题, 编写一个函数math_name(n),
 * 它返回一个指向n和月名字的字符串的指针.
 * 这是static类型数组的一种理想应用.
 * mouth_name函数包括一个私有的字符串数组,
 * 当它被调用时,返回一个指向正确元素的指针
 */

#include <stdio.h>

char *mouth_name(int n){
  static char *name[] = {
    "illeagal mouth",
    "January", "Febuary", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "Deceber"
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char const *argv[]) {
  for(unsigned int i = 0; i < 15; ++i){
    printf("%d\t%s\n", i,mouth_name(i));
  }
  return 0;
}
/* output
0       illeagal mouth
1       January
2       Febuary
3       March
4       April
5       May
6       June
7       July
8       August
9       September
10      October
11      November
12      Deceber
13      illeagal mouth
14      illeagal mouth
*/
