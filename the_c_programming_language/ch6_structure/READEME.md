# 第六章 结构
结构是一个变量或多个变量的组合,这些变量可以为不同类型.

## 6.1 结构的基本知识
点是最基本的对象, 假定用`x`,`y`坐标表示(都为整数)
```c
struct point{
  int x;
  int y;
};

```
`struct` 之后的名字是可选的, 称为结构标记(这里是`point`).
结构标记用于为结构命名,定义之后结构标记就代表花括号内的声明,
可以用它作为声明的简写形式.

结构体中定义的b变量称为成员.
结构成员, 结构标记和普通变量可以采用相同名字,他们不会冲突.
不同结构中的成员可以使用相同的名字,
但是, 从编程风格来说, 通常只有密切相关的对象才使用相同名字.

`struct`声明定义了一种数据类型.
在标识结构成员表结束的右花括号可以跟一个变量表,这与其他基本变量的声明是相同的
```c
struct {...} x,y,z;
```
声明`x`,`y`,`z`为指定类型变量, 为他们分配存储空间.

如果结构声明之后不带变量表,则不需要分配存储空间, 它仅仅描述了一个结构的模板或轮廓.

结构的初始化可以在定义之后使用初值表进行.
初值表中的每个成员必须是常量表达式
```c
struct point pt = {320, 200};
```

在表达式中, 可以通过`结构名`.`成员`引用,例如
```c
printf("%d, %d", pt.x, pt.y);
```

结构可以嵌套, 可以用对角线上两个点定义矩形
```c
struct rect{
  struct point pt1;
  struct point pt2;
};
```
可以使用下面语句访问`pt1`的坐标:
```c
screen.pt1.x
```

## 6.2 结构与函数
结构的合法操作只有几种:
作为一个整体复制和赋值,
通过`&`运算符取地址, 访问其成员.
其中,复制和赋值包括向函数传递参数以及从函数返回值.
结构之间不可以进行比较.
可以用一个常量成员值列表初始化结构, 自动结构也可以通过赋值进行初始化.

为了更进一步理解结构, 我们编写几个对点和矩形操作的函数.
至少可以通过3种可能的方法传递结构:
一是传递各个结构成员,
二是传递整个结构,
三是传递指向结构的指针.
这三种方法各有利弊

首先看一下函数`makepoint`,它有两个整型参数,返回`point`结构:

```c
// makepoint函数: 通过x,y坐标构造一个点
struct point makepoint(int x, int y){
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}
```
注意, 参数名和结构成员同名不会引起冲突.
事实上,使用重名还可以强调两者之间的关系

现在可以使用`makepoint`动态初始化任意结构,
也可以向函数结构提供结构类型的参数, 例如
```c
struct rect screen;
  struct point middle;
  struct point makepoint(int x, int y);

  screen.pt1 = makepoint(0, 0);
  screen.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                     (screen.pt1.y + screen.pt2.y) / 2);
```
接下来编写函数进行算数运算
```c
// addpoint 函数: 将两个点相加
struct point addpoint(struct point p1, struct point p2) {
  p1.x +=p2.x;
  p1.y += p2.y;
  return p1;
}
```
其中, 函数的参数和返回值都是结构类型.
之所以直接将相加的结果赋给`p1`而没有使用显式临时变量存储, 是为了强调结构类型的参数和其他类型的参数一样, 都是通过值传递的.

下面看另外一个例子, pt_in_rect 函数: 如果p在矩形r内,返回1, 否则返回0
约定: 矩形包括其左侧边和底边, 不包括顶边和右侧边.
```c
/**
 *  pt_in_rect 函数: 如果p在矩形r内,返回1, 否则返回0
 *  约定: 矩形包括其左侧边和底边, 不包括顶边和右侧边.
 */
int pt_in_rect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}
```

这里假设矩形是用标准形式表示的, 其中`pt1`的坐标小于`pt2`的坐标. 下列函数返回一个标准的矩形.
```c
struct rect canonrect(struct rect r) {
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt1.x = max(r.pt1.x, r.pt2.x);
  temp.pt1.y = max(r.pt1.y, r.pt2.y);
  return temp;
}
```

如果传递的结构很大, 使用指针的方式要比复制整个结构的效率高.
结构指针类似于普通变量的指针.声明:
```c
struct point *pp;
```
将`pp`定义为一个指向`struct`,`point`类型对象的指针,`*pp`即为该结构.`(*pp).x`是结构成员.可以按照以下方式使用:
```c
struct point origan = { 1, 5 }, *pp;

pp = &origan;
printf("origan is (%d,%d)", (*pp).x, pp->y);
```
其中`(*pp).x`的圆括号是必须的, 因为结构成员运算符`.`优先级比`*`的优先级高.表达式`*pp.x`等价于`*(pp.x)`, 因为`x`不是指针, 所以该运算是非法的.

由于指针使用的频度非常高, 为了使用方便, C语言提供了另一种简写方式.
假定`p`是一个指向结构的指针, 可以用:
```c
p -> 结构成员
```
这种形式引用成员.运算符`.`和`->`都是从左向右结合的,对于一下声明:
```c
struct rect r, *rp = &r;
```
下面的结构等价
```c
r.pt1.x;
rp->pt1.x;
(r.pt1).x;
```
在所有运算符中,以下四个运算符优先级最高:结构运算符`.``->`,用于函数调用的`()`,下标运算`[]`,因此,对于下面结构体的声明
```c
struct {
    int len = 1;
    char * str;
  } * p;
```
表达式
```c
++p -> len
```
增加`len`的值, 蕴含括号关系是`++(p->len)`
同理, `p++->len`先对`len`执行操作,然后将p加一.`*p++->str`先读取指针`str`指向对象的值,再将`p`加1.
