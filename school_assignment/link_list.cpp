#include"stdio.h"
#include"stdlib.h"//sizeof malloc
// #define NULL 0

// 定义数据结构体
struct data{
  int x;
  char c;
  struct data *next;//指向下一个结构体的指针
}*head;//定义了指针 head

//         x     |-->x
//         c     |   c
//         next -|   NULL
//

// 生成简单链表,并删除
int main()
{
  // 链表初始化
    struct data *p, *q;
    int i;
    p =(struct data*)malloc(sizeof(struct data));
    //  ↑              ↑      ↑
    //  ↑              ↑      返回字符串的长度
    //  ↑              向系统申请存储空间
    //  ↑              返回值为 void*
    //  指针需要数据类型相同,进行强制类型转换
    // sizeof(int) 求数据所占字节数
    // malloc(n),向系统申请n个存储单元
    // ↑ #include"stdlib.h"
    p->x = 0;
    p->c = 'a';
    p->next = NULL;
    //          0
    //         'a'
    //         NULL
    //          ↑p

    head = p;
    //          0
    //         'a'
    //         NULL
    //          ↑p/head
    for(i=0; i<4; i++){
      q=(struct data*)malloc(sizeof(struct data));
      // 以下以第一轮为例,其他同理
      //         x     |-->x
      //         c     |   c
      //         next -|   NULL
      //         ↑ q

      scanf("%d %c", &(q->x), &(q->c));
      q->next=NULL;
      //     0        x
      //    'a'       c
      //    NULL      NULL
      //     ↑head/p    ↑ q
      p -> next = q;
      //     0      |->x
      //    'a'     |  c
      //     q -----  NULL
      //     ↑head/p    ↑ q
      p=q;
      //     0      |->x
      //    'a'     |  c
      //     q -----  NULL
      //     ↑head    ↑ q/p
    }
    p=q=head;//循环结束,p,q回到开始
    // ↓head/p/q
    // 0 'a' next-->1 'b' next-->2 'c' next->3 'd'-> 4 'e' NULL
    printf("%s\n", "test the initlization of the list");
    while(p !=NULL){
      printf("%d %c\n", p->x, p->c);
      p = p->next;//到下一个p
    }

  // 删除链表的节点(删除2)
    p=q=head;
    // 1.查找要删除的节点
    while (p->x != 2 && p != NULL) {
      q=p;
      p=p->next;
    }
    // ↓head        ↓q           ↓p
    // 0 'a' next-->1 'b' next-->2 'c' next->3 'd'-> 4 'e' NULL

    // 2.删除节点
    if (p->x == 2) {
      q->next = p->next;
      //                          ↓p
      // ↓head        ↓q          2 'c' next->3 'd'-> 4 'e' NULL
      // 0 'a' next-->1 'b' next--------------↑
      free(p);//将p所占内存释放
      // 0 'a' next-->1 'b' next->3 'd'-> 4 'e' NULL
    }
    else{
      printf("%s\n", "Error");
    }
    printf("%s\n", "test delete result");
    p = q = head;
    // ↓head/p/q
    // 0 'a' next-->1 'b' next->3 'd'-> 4 'e' NULL
    while(p !=NULL){
      printf("%d %c\n", p->x, p->c);
      p = p->next;
    }
    p = q = head;

  // 链表的插入

    // ↓head/p/q
    // 0 'a' next-->1 'b' next->3 'd'-> 4 'e' NULL

    // 1.确定插入的相关位置
    for (int i = 0; i <2; i++) {
      q=p;
      p = p->next;
    }
    // ↓head        ↓q          ↓p
    // 0 'a' next-->1 'b' next->3 'd'-> 4 'e' NULL

    // 2.申请一个新的节点并保存
    struct data *new_;
    new_ = (struct data*)malloc(sizeof(struct data));
    new_->x = 0; new_ ->c = 'n';

    // 3.修改相关指针
    q->next = new_;
    new_->next = p;

    p = q = head;
    printf("%s\n", "test insert");
    while(p !=NULL){
      printf("%d %c\n", p->x, p->c);
      p = p->next;
    }

}
// input
// 1 b
// 2 c
// 3 d
// 4 e
//
// test the initlization of the list
// 0 a
// 1 b
// 2 c
// 3 d
// 4 e
// test delete result
// 0 a
// 1 b
// 3 d
// 4 e
