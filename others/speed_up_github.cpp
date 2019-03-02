/**
 * 网上提供的github加速方法,封装后需要管理员权限
 */
#include <stdio.h>
int main(int argc, char const *argv[]) {
  FILE *fp;
  fp = fopen("C:/Windows/System32/drivers/etc/hosts", "a");
  fprintf(fp, "\n151.101.185.194 http://github.global.ssl.fastly.net\n");
  fprintf(fp, "\n192.30.253.112 http://github.com\n");
  fclose(fp);
  return 0;
}
