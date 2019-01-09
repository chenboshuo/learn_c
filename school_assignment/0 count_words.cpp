// 18蓝桥杯校内 1.统计单词数
// 问题描述
// 统计输入英文文章段落中不同单词(单词有大小写之分，但统计时 忽略大小写)
// 各自出现的次数。输入段落中所含单词的总数不超过100最长单词的长度不超过20个字母，
// 输入格式
// 一个包含若干句子的段落， 每个句子由若干英文单词组成。
// 除空格，逗 号和句号外，这些输入的句子中不含其他非字母字符，
// 并且，逗号和句号紧跟在它前面的英文单词后面，中间没有空格。
// 段落最后一个字符是回车符,表示输入结束
// 输出格式
// 
// 若段落中共有 M个不同的英文单词，
// 则按照其在段落中出现的先后顺序输出M行，
// 各行的格式为:  
// 单词中所有字母均用大写形式输出(最长的单词顶格输出，
// 它前面没有多余的空格;  其余单词与其右对齐)
// +冒号+N个*号+该单词在段落中的出现次数N
// 
// 样例输入
// 
// This is a test. This test is easy. This is a test. This test is easy.
// 样例输出
// THTS:****4
// IS:****4
// A:**2
// TEST:****4
// EASY:**2

#include "stdio.h"
#include"stdlib.h"
#include <string.h>


// 读取当前单词
int read_the_word(char *p, char *word) {
  int i;
  if (*p ==' '||*p == '.') {
    p++;
  }
  for (i = 0;*p != ' '&&*p != '.'; i++) {
    if (*(p)>='a' && *(p) <='z') {
      *(p) -= 32;
    }
    *(word+i) = *p;
    p++;
  }
  return i+1;
}

int main(int argc, char const *argv[]) {
  char text[2000]="This is a test.This test is easy.This is a test.This test is easy.";
  char *t = text;
  char words[100][20];
  int w_times[100];
  char *w = words[0];
  int len;

  // gets(text);
  for (int i = 0; i < 100; i++) {
    *(w_times+i) = 0;
  }

  len = read_the_word(t, w[i]);
  *(w[i]+len) = '\0';
  w += len;
  return 0;
}
