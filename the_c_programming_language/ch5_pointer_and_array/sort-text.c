/**
 * 我们引用指针数组来处理这种问题. 如果待排序的文本首行首尾相连的存储在一个长字符串中,
 * 那么每个文本可以通过指向他的第一个字符的指针来访问.
 * 这些指针本身可以存放在数组中.
 * 这样,将指向两个文本行的指针传递给函数`strcmp`就可以实现两个文本行的比较.
 * 当交换次序颠倒的两个文本行时,实际上交换的是指针数组中与这两个文本行相对应的指针,
 * 而不是文本行本身.
 *
 * 这种方法消除了因移动文本本身所带来的复杂存储管理和巨大的开销这两个孪生问题
 * 排序包括以下三个步骤
 * 1. 读取所有输入行
 * 2. 对文本进行排序
 * 3. 按次序打印文本行
 *
 * 输入输出函数必须收集和保留每个文本行中的字符, 并建立一个指向这些文本行的数组.
 * 他同时还必须统计输入的行数, 因为在排序和打印时要用到这一信息.
 * 由于输入函数只能处理有限数目的输入行,所以在输入行过多而超过限定的最大行数时,
 * 函数返回某个表示非法行数的值,比如-1.
 *
 * 输出函数只要按照指针数组的次序依次打印这些文本即可
 */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // 进行排序的最大文本行数

char *lineptr[MAXLINES];

int readlines(char *lineptr, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// 对输入的文本进行排序
int main(int argc, char const *argv[]) {
  return 0;
}

#define MAXLEN 1000 // 每个输入文本行的最大长度
int getline(char *, int);
char *alloc(int);




void qsort(char *v[], int left, int right) {
  int i,last;
  void swap(char *v[], int i, int j);

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
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/**
 * 交换v[i],v[j]两个数
 * @param v 数组
 * @param i 要交换的数字
 * @param j 要交换的数字
 */
void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define ALLOCDIZE 10000 // 可用空间大小
static char allocbuf[ALLOCDIZE]; // alloc的存储区
static char *allocp = allocbuf; // 下一个空闲位置
/**
 * 分配存储空间
 * allocbuf :　__已使用____|＿＿＿空闲＿＿＿|
 * 　　　　　　　　　　　　　↑ allocbuf
 * @param  n 字符串长度
 * @return   指向分配前的位置的指针
 * allocbuf :　__已使用___  ____ |＿＿＿空闲＿＿＿|
 * 　　　　　　分配前的指针 ↑  n  ↑ allocbuf
 */
char *alloc(int n){
  /**
   * 有足够的空间
   * @param n 分配空间长度
   * 如果分配空间足够,分配存储空间后allocp的新值比allocbug的尾端地址+1
   */
  if (allocbuf + ALLOCDIZE - allocp >= n) { //
    allocp += n;
    return allocp - n; // 分配前的指针
  }else{
    return 0;
    /**
     * C语言保证0永远不是有效的地址,因此返回值为0可以表示发生了异常事件
     * 这里0表示没有足够空间可供分配
     * 指针与整数之间不能相互转换,但0是唯一例外,0可以赋值给指针,指针也可以和0比较.
     * 程序中经常用`NULL`代替0,
     * 这样清晰的说明0是指针的一个特殊值.`NULL`定义在`<stddef.h>`中.
     */
  }
}


/**
 * 将一行读入到s并返回其长度
 * @param  s   要写入的字符串
 * @param  lim 最长输入
 * @return     这一行的长度
 */
int getline(char s[], int lim){
  int c,i=0;

  while (--lim > 0 && (c=getchar()) != EOF && c!='\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
