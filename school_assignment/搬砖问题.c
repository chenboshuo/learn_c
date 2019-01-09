#include "stdio.h"
/*36块砖，36人搬，男搬4，女搬3，两个小孩搬一个，问有多少方法*/
int main(int argc, char const *argv[]) {
  int man, woman, children;
  for (man = 0; man < 9; man++) {
    for ( woman = 0; woman < 12; woman++) {
      for ( children = 0; children < 36; children++) {
        if(man*4+woman*3+children/2 ==36){
          printf("%d %d %d\n",man,woman,children);
        }
      }
    }
  }
  return 0;
}
