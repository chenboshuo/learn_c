// 简单密码破解（字符数组）
// 时间限制: 1 Sec  内存限制: 128 MB
// 提交: 6  解决: 3
// [提交] [状态] [讨论版] [命题人:外部导入]
// 题目描述
//
// 密码是我们生活中非常重要的东东，我们的那么一点不能说的秘密就全靠它了。哇哈哈.
// 接下来渊子要在密码之上再加一套密码，虽然简单但也安全。
// 假设渊子原来一个BBS上的密码为zvbo941987,为了方便记忆，他通过一种算法把这个密码变换成YUANzi1987，这个密码是他的名字和出生年份，怎么忘都忘不了，而且可以明目张胆地放在显眼的地方而不被别人知道真正的密码。
// 他是这么变换的，大家都知道手机上的字母：
 // 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6,
 // pqrs--7, tuv--8 wxyz--9, 0--0
 // ,就这么简单，渊子把密码中出现的小写字母都变成对应的数字，
 // 数字和其他的符号都不做变换，声明：密码中没有空格，
 // 而密码中出现的大写字母则变成小写之后往后移一位
 // ，如：X，先边成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
//
// 输入
//
// 输入包括多个测试数据。输入是一个明文，密码长度不超过100个字符，输入直到文件结尾。
//
// 输出
//
// 输出渊子真正的密文。
//
// 样例输入
//
// YUANzi1987
//
// 样例输出
//
// zvbo941987
#include "stdio.h"
#include<ctype.h>//tolower

//密码的具体算法
char encrypt(char c){
  if (c>='A' && c<'Z') {
    return tolower(c+1);
  }
  else if (c == 'Z') {
    return 'a';
  }
  else if (c >= 'a' && c<='z') {
    switch (c) {
      case 'a': case 'b': case 'c': return '2'; break;
      case 'd': case 'e': case 'f': return '3'; break;
      case 'g': case 'h': case 'i': return '4'; break;
      case 'j': case 'k': case 'l': return '5'; break;
      case 'm': case 'n': case 'o': return '6'; break;
      case 'p': case 'q': case 'r':case 's': return '7'; break;
      case 't': case 'u': case 'v': return '8'; break;
      case 'w': case 'x': case 'y':case 'z': return '9'; break;
    }
  }
  else{
    return c;
  }
}

// 简单密码破解（字符数组）
int main(int argc, char const *argv[]) {
  char a,b;
  while ((a = getchar()) != EOF) {
    b = encrypt(a);
    putchar(b);
  }

  return 0;
}
