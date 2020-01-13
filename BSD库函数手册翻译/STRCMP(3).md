**STRCMP(3)        BSD库函数手册      STRCMP(3)**



**名称**

   **strcmp, strncmp -- 比较字符串**



**库**

   **C标准库 (libc, -lc)**



**概要**

  `#include <string.h>`

  `int`

  `strcmp(const char *s1,const char *s2);`

  `int`

  `strncmp(const char *s1,const char *s2,size_t n);`



**描述**

  **函数strcmp()和strncmp()用字典序比较以'\0'结束的字符串s1和s2。**

  **函数strncmp()比较不超过n个字符。因为设计strncmp()的目的是比较字符串而非二进制数据，出现在'\0'后面的字符不会被比较。**

**返回值**

​       **函数strcmp()和strncmp()会根据字符串s1和s2的大小关系返回一个整数，具体规则是：当s1大于s2,返回正整数；当s1等于s2,返回零；当s1小于s2,返回负整数。比较的单位是无符号字符，所以'\200'大于'\0'。**

**另请参阅**

​	 **bcmp(3), memcmp(3), strcasecmp(3), strcoll(3), strxfrm(3), wcscmp(3)**

**标准**

  **函数 strcmp() 和 strncmp()  遵循 ISO/IEC 9899:1990(''ISO C90'')这一标准。**



**BSD             2001年10月11日              BSD**