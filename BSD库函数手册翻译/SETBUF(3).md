**SETBUF(3)          BSD库函数手册     SETBUF(3)**



**NAME**

   **setbuf, setbuffer, setlinebuf, setvbuf ——流缓冲操作 **  



**库**

   **C标准库 (libc, -lc)**



**概要**

###   `#include<stdio.h>`

###   `void`

###   `setbuf(FILE *restrict stream,char *restrict buf);`

###   `void`

###   `setbuffer(FILE *stream,char *buf,int size);`

###   `int`

###   `setlinebuf(FILE *stream);`

###   `int`

###   `setvbuf(FILE *restrict stream,char *restrict buf,int type,size_t size);`

**描述**

​      有三种可用的缓冲类型：无缓冲，块缓冲和行缓冲。当某个输出流是无缓冲的，一旦写入，信息马上就会出现在目标文件或终端中；当该流是块缓冲的，许多字符被保存下来，以块为单位写入；当该流是行缓冲的，字符被保存,直到输出一个新行或从连接到终端设备的任何流中读取输入(通常是stdin)。

对于标准输出(STDBUF1)或所有的描述符(STDBUF),默认的缓冲区设置可以被覆盖。环境变量的值是一个字母，后面跟一个标识**缓冲区大小**的可选数值。有效的大小范围是0B到64KB。有效的字母是:

​	U       无缓冲(Unbuffered)

​    L        行缓冲(Line-buffered)

​    F        全缓冲(Fully-buffered)

可以使用函数fflush(3)来强制块提前退出(force the block out early)(请参阅fclose(3))。

通常，所有的**文件**都是**块缓冲**的。当对文件执行首个**I/O操作**时，将调用**malloc(3)**，并且会获得一个最佳大小的**缓冲区**。若某个**流指向终端**(像标准输出stdout通常做的那样)，该流就是**行缓冲**的。**标准错误流**stderr始终**不带缓冲**。

可以使用函数**setvbuf()**来*改变*某个流的**缓冲行为**。参数type必须是以下三个宏中的一个:

​      **_IONBF**      无缓冲(**unbuffered**)

​      **_IOLBF**       行缓冲(**line buffered**)

​      **_IOFBF**       全缓冲(**fully buffered**)

可以把参数size设置为零，以延迟获取与平常一样的最佳大小缓冲区分配空间。若**size不是零**，则<u>除了不带缓冲的文件外</u>，参数**buf**应该指向**至少size个字节长**的缓冲区——将使用**这一缓冲区**，而非当前缓冲区。若**buf**不是NULL，则在关闭流后，由**函数的调用者**负责**释放**这一**缓冲区**(缓冲区释放通过调用free(3)完成)。（若参数**size不是零**，但**buf是NULL**，将**立即分配**给定大小的**缓冲区**，并在关闭流时释放这一缓冲区。这是ANSI C的一个扩展；可移值代码的size是零时，应该分配NULL缓冲区。）

可以在任何时候使用函数**setvbuf()** ，但如果流是“活动的”，可能出现奇怪的**副作用**(如丢弃输入或刷新输出)。在任何给定的流上，可移值的应用程序应**只调用一次setvbuf()**，而且应在**执行任何I/O操作前**调用。

其他三个调用实际上是setvbuf()调用的别名。除了没有返回值以外，函数setbuf()精确地等同于以下调用:

##### `servbuf(stream,buf,buf?_IOFBF:_IONBF,BUFSIZ);`

函数setbuffer() 和函数setbuf()只有一点不同——setbuffer()的缓冲区的大小取决于调用者，而不是由默认的BUFSIZ所决定的。函数setlinebuf()精确地等同于以下调用:

##### `setvbuf(stream,(char *)NULL,_IOLBF,0);`



##### 返回值

​		当执行成功时，函数**setvbuf()返回零**，若无法执行请求，则返回**EOF**(注意，在这种情形下，**流依然有效**)。

​        函数**setlinebuf()**的返回值**等于**和它等价的**setvbuf()**函数调用的返回值。

##### 另请参阅

​		**fclose(3), fopen(3), fread(3), malloc(3), printf(3), puts(3)**

##### 标准

​        函数setbuf()和setvbuf()遵循**ISO/IEC 9899:1990(''ISO C90'')**这一标准。

##### 缺陷

​       函数setbuffer()和setlinebuf()无法移值到4.2BSD之前的BSD系统上。在4.2BSD和4.3BSD系统上，setbuf()始终使用次优的缓冲区大小，应避免使用。

**BSD              1993 年6月4日              BSD**