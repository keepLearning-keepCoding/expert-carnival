**STRCPY(3)        BSD库函数手册        STRCPY(3)**

**名称**

   **stpcpy, stpncpy, strcpy, strncpy --  复制字符串**

**库**

   **C标准库(libc, -lc)**

**概要**

 `#include <string.h>`

**<u>char</u> <u>*</u>**

**stpcpy(<u>char</u> <u>*</u> <u>dst</u>,<u>const</u> <u>char</u> <u>*</u><u>src</u>);**



**<u>char</u> <u>*</u>**

**stpncpy(<u>char</u> <u>*</u> <u>dst</u>, <u>const</u> <u>char</u> <u>*</u> <u>src</u>, <u>size_t</u> <u>len</u>);**



**<u>char</u> <u>*</u>**

**strcpy(<u>char</u> <u>*</u> <u>dst</u>,<u>const</u> <u>char</u> <u>*</u><u>src</u>);**



**<u>char</u> <u>*</u>**

**strncpy(<u>char</u> <u>*</u> <u>dst</u>, <u>const</u> <u>char</u> <u>*</u> <u>src</u>, <u>size_t</u> <u>len</u>);**



**描述**

​         **函数stpcpy()和strcpy()把字符串<u>src</u>复制到<u>dst</u>(包括终止字符串的'\0'字符)。**

​         **函数stpncpy()和strncpy()最多把<u>len</u>个字符串从<u>src</u>复制到<u>dst</u>。若<u>src</u>的长度小于<u>len</u>个字符串长，则<u>dst</u>的其余部分将被字符串'\0'填充。否则，<u>dst</u>不会终止。源字符串的地址和目的字符串的地址不应重叠，因为该行为未定义。**

**返回值**

**函数strcpy()和strncpy()返回<u>dst</u>。函数stpcpy()和stpncpy()返回一个指针，该指针指向字符串<u>dst</u>的终止字符'\0'。若stpncpy()没有用空字符'\0'来终止字符串<u>dst</u>,它就会返回一个指向dst[n]的指针——dst[n]不必指向一个有效的内存位置。**

**示例**

**以下的语句把''abc\0\0\0' '赋给<u>chararray</u>:**

​			`char chararray[6];`
      `(void)strncpy(chararray,"abc",sizeof(chararray));`

**以下的语句把''abcdef' '赋给<u>chararray</u>:**

`char chararray[6];`
`(void)strncpy(chararray,"abcdefgh",sizeof(chararray));`

**注意它<u>并没有</u>用空字符'\0'来终止<u>chararray</u>,因为源字符串的长度大于等于长度参数。**

**以下语句把尽可能多的字符从<u>input</u>复制到<u>buf</u>，并会以'\0'来结束目的字符串。因为函数strncpy()<u>并不</u>保证以空字符'\0'来终止字符串本身，这一过程必须显式完成。**

​		**char buf[1024];**

​		**(void)strncpy(buf,input,sizeof(buf)-1);**

​		**buf[sizeof(buf)-1]='\0';**

**以上的功能可以通过调用strlcpy(3)来实现，正如以下的例子所示:**

​		  **(void)strlcpy(buf,input,sizeof(buf));**

**注意，因为strlcpy(3)并未在任何标准中定义，只有当不考虑可移植性问题时，才可调用它。**

**另请参阅**

  **bcopy(3), memccpy(3), memcpy(3), memmove(3), strlcpy(3), wcscpy(3)**

**标准**

**函数strcpy()和strncpy()遵循ISO/IEC 9899:1990(''ISO C90'')这一标准。函数stpcpy()和stpncpy()遵循IEEE Std 1003.1-2008(''POSIX.1'')这一标准。**

**历史**

  **函数stpcpy()最初出现在FreeBSD 4.4中，而在FreeBSD 8.0中则新增了函数stpncpy()。**

**安全考量**

**函数strcpy()很容易被以某种方式不当使用，这种方式使得恶意用户可以通过缓冲区溢出攻击而随意改变某个运行中程序的功能。**

**BSD             2009年2月28日    			BSD**

参考链接: https://blog.csdn.net/pjl1119/article/details/79815541
