/*
  用这个直接新建cpp
 */
#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  FILE *a;
  char name[255];

  printf("%s\n", "input your cpp file\'s name:");
  gets(name);
  strcpy(name, strcat(name,".cpp"));
  a = fopen(name,"w");
  fprintf(a, "%s\n", "/*");
  fprintf(a, "%s\n", "\t");
  fprintf(a, "%s\n\n", "\t*/");
  fprintf(a, "%s\n\n", "#include\"stdio.h\"");
  fprintf(a, "%s\n", "int main(int argc, char const *argv[]) {");
  fprintf(a, "%s\n", "\t");
  fprintf(a, "%s\n", "\treturn 0;");
  fprintf(a, "%s\n", "}");
  fclose(a);
  return 0;
}
