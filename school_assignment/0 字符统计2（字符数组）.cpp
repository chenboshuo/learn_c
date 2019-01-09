// 字符统计2（字符数组）
// 时间限制: 1 Sec  内存限制: 128 MB
// 提交: 15  解决: 9
// [提交] [状态] [讨论版] [命题人:外部导入]
// 题目描述
//
// 输入英文句子，输出该句子中除了空格外
// 出现次数最多的字符及其出现的次数。
//
// 输入
//
// 输入数据包含多个测试实例，每个测试实例
// 是一个长度不超过100的英文句子，占一行。
//
// 输出
//
// 逐行输出每个句子中出现次数最多的字符及其出现的次数（如果有多个字符的次数相同，只输出ASCII码最小的字符）。
//
// 样例输入
//
// I am a student
// a good programming problem
// ABCD abcd ABCD abcd
//
// 样例输出
//
// a 2
// o 4
// A 2
//
/* 用python解决
s = input()
a = [0]*52
for i in s:
    if i.isupper():
        a[ord(i)-ord('A')] += 1
    if i.islower():
        a[ord(i)-ord('a')+26] += 1
        #  a[ord(i-'a')+26] += 1 错,字符串不能做减法
max_frequency = max(a)
index_ = a.index(max_frequency)
m_char = chr(index_ + ord('A')) if index_ < 26 else chr(index_ + ord('a')-26)
print(m_char, max_frequency)
(加上try-except即可)
 */
#include "stdio.h"


int main(int argc, char const *argv[]) {
  int a,i;
  while (a = getchar() != EOF) {
    int md=0;//存储最大数字
    int mi=0;//存储最大字母
    while (a !='\n') {
      int s[52];
      int *p = s;

      // 将次数初始化为0
      for (i = 0; i < 52; i++) {
        *(p+i) = 0;
      }
      if(a>='a' && a<='z'){
        // *(p+a-'a'+26) ++;
        ++s[a-'a'+26];
      }
      else if (a>='A' && a<='Z') {
        //*(p+a-'A') ++;
        ++s[a-'A'] ;
      }

      for ( i = 0; i < 52; i++) {
        if (*(p+i)>md) {
          md = *(p+i);
          mi = i;
        }
      }
    }
    // 将mi变成字母
    if (mi>=26) {
      mi += 'a' ;
    }
    else{
      mi+= 'A';
    }
    printf("%c %d\n", mi, md);
  }

  return 0;
}
