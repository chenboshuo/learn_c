/*程序的功能是：统计子串sub在母串中出现的次数，请填空。
例如输入：abcabsdefabc
          abc
输出：2
*/
// 原题
// int count(char *p,char *q)
// { int m,n,k,num=0;
//   for(m=0;p[m];m++)
//     for(__(1)__,k=0;q[k]==p[n];k++,n++)
//       if(q[__(2)__]=='\0') {num++;break;}
//    return num;
// }
#include<stdio.h>
#include<string.h>

/**
 * 统计子串sub在母串中出现的次数
 * @param  p 母字符串的指针
 * @param  q 指向要查找子串
 * @return   次数
 */
int count_sub(char *p,char *q){
  int m,n,k,num=0;
  for(m=0;p[m];m++){
    //   ↓p[m]
    // p:abcabsdefabc
    for(n=m,k=0;q[k]==p[n];k++,n++){
//      ↓p[m]
//    p:abcabsdefabc
//      ↑p[n]
//      ↓q[k]	
//	q:abc 
      if(q[k+1]=='\0'){//如果下一项为0，结束
        num++;
        break;
      }
//    下一个循环 
//	   ↓p[m]
//    p:abcabsdefabc
//       ↑p[n]
//      ↓q[k]	
//	q:abc
    }
  }
   return num;
}

inta main()
{ char s[80],sub[80];
  gets(s);
  gets(sub);
  printf("%d\n",count_sub(s,sub));
}
