## 字符串相关
### 1 以下程序运行结果为

```c
char s1[10]="12345",s2[10]="abc",s3[]="67";
strcpy(s1,s2);
strcat(s1,s3);
puts(s1);
```
output abc67

- C 库函数 strcpy
```c
 *strcpy(char *dest, const char *src)
```

  把 src 所指向的字符串复制到 dest。

  ```c
  strcpy("12345","abc");
  ```
  s1变成abc

- strcat()
```c
char *strcat(char *dest, const char *src)
```
把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
```c
strcat(s1,s3)
```
变成了
```c
strcat("abc","67")
```
