// 打印分形 0.1
/* 1,2,4,8,16
rank = 3, line = 4
---.    -------1
--.-.-- --------2
-.---.-
. . . . -------3
---=----
12345678

rank = 5,line = 16
1 -------------.
2 ------------.-.
  -----------.---.
3 ----------. . . .
  ---------.---7---.
          . .--5--. .
         .   .   .   .
4 ------. . . . . . . .
       .-------15------.
      . .------13-----. .
     .   .           .   .
    . . . .         . . . .
   .       .       .        .
  . .     . .     .  .     . .
 .   .   .   .   .    .   .   .
. . . . . . . . . . . . . . . . .
---------------------------------



*/
#include "stdio.h"
#include "math.h"

// 如果在对应位置有值,赋值为1
void fractal(int *p[],int i,int j, int line) {
  if (i != line){
    *(*(p+i)+j) = 1;
    fractal(p,i+1, j-1, line);
    fractal(p,i+1, j+1, line);
  }
}
int main(int argc, char const *argv[]) {
  int i,j,rank;
  int line;//存储行数

  scanf("%d", &rank);
  // line = power(2,rank);
  line = pow(2,rank);
  int a[line][line];
  int (*p)[line] = a;
  fractal(p, 0,(line-1)/2,line);
  return 0;
}
