/**
 * 我们引用指针数组来处理这种问题.
 * 如果待排序的文本首行首尾相连的存储在一个长字符串中,
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
 *
 *
 * 5.11 指向函数的指针
 *
 * 在C语言中, 函数不是变量, 但可以定义指向函数的指针.
 * 这种类型的指针可以被赋值, 存放在数组中,
 * 传递给函数或者作为函数的返回值等等,
 * 接下来修改本章之前的排序函数,
 * 在给定可选参数`-n`的情况下,
 * 函数将按照数值大小而非字典顺序进行排序.
 * 排序通常包括三部分:
 * 判断任何对象之间次序的比较操作,
 * 颠倒对象次序的交换操作,
 * 一个用于比较和交换对象直到所有对象都按正确次序排列的排序算法.
 * 由于排序算法与比较, 交换操作无关,
 * 因此, 通过在排序算法中调用不同的比较和交换函数,
 * 便可实现按照不同标准排序. 这就是我们新版本排序所采用的方法.
 *
 * 我们在前面讲过,
 * 函数`strcmp` 按字典排序比较两个输入行.
 * 在这里, 我们还需要一个以数值为基础来比较两个输入行,
 * 并返回与`strcmp`一样结果的`numcmp`.
 * 指向恰当函数的指针将被传给`quick_sort`函数. 在这里,
 * 参数的出错处理并不是问题的重点.
 */
#include <stdio.h>
#include <stdlib.h> // atof
#include <string.h>

#define MAXLINES 5000 // 进行排序的最大文本行数

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quick_sort(void *lineptr[], int left, int right,
                int (*comp)(void *, void *));

int numcmp(char *, char *);

// 对输入的文本进行排序
int main(int argc, char const *argv[]) {
  int nlines;      // 读入的输入行数
  int numeric = 0; // 若进行数值排序, 其值为 1
  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    /**
     * 调用qsort的语句中,strcmp和numcmp是函数地址.因为他们是函数,所以前面不需要加取地址符&,
     * 同样的原因,数组名前面也不需要&运算符.
     *
     * 改写之后的quick_sort能够处理任何数据类型,不仅仅限于字符串.
     * 从quick_sort原型可以看出, 他的参数表包括一个指针数组, 两个整数
     * 和一个有两个指针参参数的函数.
     *
     * 其中, 指针数组参数的类型为通用指针void*.
     * 由于任何类型都可以转换为void*类型,
     * 并且在将它转换回来的类型时不会丢失信息,
     * 所以, 调用quick_sort函数可以将参数强制转化为void*类型.
     * 比较函数也要执行这种类型转换.
     * 这种转换通常不会影响到数据的实际表示, 但要确保编译器不会报错.
     */
    quick_sort((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("%s\n", "Error: input too big to sort");
    return 1;
  }
  return 0;
}

#define MAXLEN 1000 // 每个输入文本行的最大长度
int getline(char *, int);
char *alloc(int);

/**
 * 读取输入行
 * @param  lineptr  每行的地址指针
 * @param  maxlines 最长的输入行数
 * @return          行数
 */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0'; // 删除换行符
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

//
/**
 * quick_sort函数: 以递增的顺序对v[left]...v[right] 进行排序
 * @param v     [description]
 * @param left  [description]
 * @param right [description]
 * @param comp  comp是个指向函数的指针,该函数有两个void参数,返回值为int
 */
void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= right) { // 若数组元素少于2个
    return;            // 不执行任何操作
  }
  swap(v, left, (left + right) / 2);    // 将划分为子集的元素
  last = left;                          // 移动到v[0]
  for (i = left + 1; i <= right; i++) { // 划分子集
    if ((*comp)(v[i], v[left]) < 0) {
      swap(v, ++last, i); // 恢复子集的元素
    }
  }
  swap(v, left, last);
  quick_sort(v, left, last - 1, comp);
  quick_sort(v, last + 1, right, comp);
}

/**
 * 交换v[i],v[j]
 * @param v 数组
 * @param i 要交换的数字
 * @param j 要交换的数字
 */
void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define ALLOCDIZE 10000          // 可用空间大小
static char allocbuf[ALLOCDIZE]; // alloc的存储区
static char *allocp = allocbuf;  // 下一个空闲位置

/**
 * 分配存储空间
 * allocbuf :　__已使用____|＿＿＿空闲＿＿＿|
 * 　　　　　　　　　　　　　↑ allocbuf
 * @param  n 字符串长度
 * @return   指向分配前的位置的指针
 * allocbuf :　__已使用___  ____ |＿＿＿空闲＿＿＿|
 * 　　　　　　分配前的指针 ↑  n  ↑ allocbuf
 */
char *alloc(int n) {
  /**
   * 有足够的空间
   * @param n 分配空间长度
   * 如果分配空间足够,分配存储空间后allocp的新值比allocbug的尾端地址+1
   */
  if (allocbuf + ALLOCDIZE - allocp >= n) { //
    allocp += n;
    return allocp - n; // 分配前的指针
  } else {
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
int getline(char s[], int lim) {
  int c, i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

/**
 * 按数值顺序比较s1,s2
 */
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2) {
    return 1;
  } else {
    return 0;
  }
}
