#include "stdio.h"
main()
{
  int c;

  while(c = getchar() != EOF)
    printf("%d\n", c);
  printf("%d - at EOF\n", c);
}
// 
// 1
// >>>1
// >>>1
// 5
// >>>1
// >>>1
// q
// >>>1
// >>>1
// ^Z
// >>>0 - at EOF
