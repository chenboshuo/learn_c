#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("%s\n", "1234567890");
  printf("%*s\n", 15, "12345");
  return 0;
}
// output
// 1234567890
//           12345
