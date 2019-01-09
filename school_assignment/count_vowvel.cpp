// 统计元音（字符数组）
// 时间限制: 1 Sec  内存限制: 128 MB
// 提交: 16  解决: 6
// [提交] [状态] [讨论版] [命题人:外部导入]
// 题目描述
//
// 统计每个元音字母在字符串中出现的次数。
//
// 输入
//
// 输入数据首先包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串。
//
// 输出
//
// 对于每个测试实例输出5行，格式如下：
//
// a:num1
// e:num2
// i:num3
// o:num4
// u:num5
//
// 多个测试实例之间由一个空行隔开。
//
// 样例输入
//
// 2
// aeiou
// my name is ignatius
//
// 样例输出
//
// a:1
// e:1
// i:1
// o:1
// u:1
//
// a:2
// e:1
// i:3
// o:0
// u:1
#include "stdio.h"

int main(int argc, char const *argv[]) {
  int count;
  scanf("%d\n", &count);
  for (int i = 0; i < count; i++) {
    int vowel[5]={0,0,0,0,0};//储存对应元音的数量
    char s[100];

    gets(s);
    for (int i = 0;s[i] != '\0'; i++) {
      switch (*(s+i)) {
        case 'a': vowel[0]++; break;
        case 'e': vowel[1]++; break;
        case 'i': vowel[2]++; break;
        case 'o': vowel[3]++; break;
        case 'u': vowel[4]++; break;
      }
    }
    printf("a:%d\n", vowel[0]);
    printf("e:%d\n", vowel[1]);
    printf("i:%d\n", vowel[2]);
    printf("o:%d\n", vowel[3]);
    printf("u:%d\n\n", vowel[4]);
  }
  return 0;
}
