/**
 * 程序由两个函数组成, 第一个函数alloc(n)返回一个指向n个连续字符存储单元的指针,
 * alloc函数的调用者可利用该指针存放字符序列,
 * 第二个函数释放存储空间,以便以后重用.
 * 之所以说两个函数是不完善的, 是因为对afree函数调用次序必然与调用alloc的次序相反.
 * 换句话说,alloc与afree 是以栈的方式(后进先出)进行存储空间的管理.
 * 标准库中提供类似的功能malloc和free,他们没有这些限制.
 *
 * 最容易实现的方法是让alloc函数对一个大字符数组allocbuf中的空间进行分配.
 * 该数组是alloc和afree的私有数组. 由于alloc和afree处理的对象是指针而不是数组下标,
 * 因此,其他函数无需知道该数组的名字,
 * 这样,可以在包含alloc和afree的源文件中将该数组声明为static类型,使他对外不可见.
 *  实际实现时,该数组甚至可以没有名字,
 *  它可以通过调用malloc函数或者向操作系统申请一个无名存储块的指针获得.
 *
 * allocbuf中的空间使用状况也是我们需要了解的信息.
 * 我们使用指针allocp指向allocbuf中的下一个空闲单元.
 * 当调用alloc申请n个字符的存储空间时,alloc检查allocbuf中有没有足够的剩余空间,
 * 则alloc返回allocp的当前值(即空闲位置开始位置),然后将alloc指向下一个空闲区域.
 *  如果空闲不够,则alloc返回0.
 *  如果p在allocbuf的边界之内,则afree(p)仅仅只是将alloc的值设为p
 */
#define ALLOCDIZE 10000 // 可用空间大小

/**
 * 仅供源文件的函数使用,其他函数不能访问.
 * 用`stastic`声明限定外部变量与函数,
 * 可以将其后声明的对象的作用域限定为被编译源文件的剩余部分.
 */
static char allocbuf[ALLOCDIZE]; // alloc的存储区
static char *allocp = allocbuf; // 下一个空闲位置

/**
 * 分配存储空间
 * allocbuf :　__已使用____|＿＿＿空闲＿＿＿|
 * 　　　　　　　　　　　　　↑ allocbuf
 * @param  n 字符串长度
 * @return   分配前的指针
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

void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCDIZE) {
    allocp = p;
  }
}
