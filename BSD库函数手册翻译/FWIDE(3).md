**FWIDE(3)         BSD 库函数手册        FWIDE(3)**



**名称**

   **fwide --    获取/设置流的方向**



**库**

   **C标准库 (libc, -lc)**



**概要**

   `#include <stdio.h>`

   `#include <wchar.h>` 

   `int`

   `fwide(FILE *stream,int mode);`

**描述**

  **函数fwide()决定了stream指向的流的方向。**

  **若流的方向已经被决定了，则fwide()不会改变它。否则，fwide()会根据模式来设置流的方向。**

  **若参数mode小于零，则stream被设置为字节定向的。若参数mode大于零，则stream被设置为宽度定向的。另外，若参数mode为零，则stream不会改变。**

**返回值**

**在对函数fwide()进行调用后，会根据方向返回一个值——若该流是字节定向的，则值小于零，若该流是宽度定向的，则该值大于零，若该流没有方向，则值等于零。**

**另请参阅**

 **ferror(3), fgetc(3), fgetwc(3), fopen(3), fputc(3), fputwc(3), freopen(3), stdio(3)**

**标准**

 **函数fwide()遵循ISO/IEC 9899:1999 (''ISO C99'')这一标准。**

**BSD              2001年10月24日              BSD**