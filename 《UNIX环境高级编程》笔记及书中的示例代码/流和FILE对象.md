1.标准**I/O库**的操作是围绕**流(stream)**进行的。当用**标准I/O库**打开或创建一个**文件**时，我们已使一个**流**与一个**文件**相*关联*。

2.对于**ASCII字符集**，一个**字符**用一个**字节**表示；对于**国际字符集**，一个**字符**可用**多个字节**表示。

3.**标准I/O文件流**可用于**单字节**或**多字节**（"宽"）字符集。

4.**流的定向**（stream's orientation)<u>决定了</u>所读、所写的字符是**单字节**还是**多字节**的。

5.若在未定向的流上使用一个**多字节**I/O函数，则将该流的定向设置为**宽定向**的。

若在未定向的流上使用一个**单字节**I/O函数，则将该流的定向设置为**字节定向**的。

6.只有两个函数可改变流的定向。freopen函数清除一个流的定向；fwide函数可用于设置流的定向。

7.当打开一个流时，标准I/O函数fopen返回一个指向<u>**FILE对象**</u>的指针。该对象通常是一个**结构**，它包含了标准I/O库为管理该流需要的所有信息，包括用于实际I/O的文件描述符、指向用于该流缓冲区的指针、缓冲区的长度、当前缓冲区中的字符数及出错标志等。

定义在macOS系统上的C标准库中_stdio.h里的FILE对象:

typedef struct **__sFILE** {

​    unsigned char *_p;  /*     缓冲区中的当前位置*/

​    int _r;     /* read space left for getc()    为getc()留出的读取空间 */

​    int _w;     /* write space left for putc()   为putc()留出的写入空间 */

​    short   _flags;     /* flags, below; this FILE is free if 0      */

​    short   _file;      /* fileno, if Unix descriptor, else -1  fileno,返回Unix描述符，出错时返回-1 */

​    struct  __sbuf _bf; /* the buffer (at least 1 byte, if !NULL)   缓冲区(至少一个字节，如果非NULL)*/

​    int _lbfsize;   /* 0 or -_bf._size, for inline putc  用于inline putc */



​    /* operations  操作*/

​    void    *_cookie;   /* cookie passed to io functions   传递给io函数的cookie*/

​    int (* _Nullable _close)(void *);

​    int (* _Nullable _read) (void *, char *, int);

​    fpos_t  (* _Nullable _seek) (void *, fpos_t, int);

​    int (* _Nullable _write)(void *, const char *, int);



​    /* separate buffer for long sequences of ungetc()  用于长序列ungetc()的单独缓冲区 */

​    struct  __sbuf _ub; /* ungetc buffer    ungetc缓冲区*/

​    struct __sFILEX *_extra; /* additions to FILE to not break ABI  为了不破坏ABI而添加到FILE*/

​    int _ur;        /* saved _r when _r is counting ungetc data */



​    /* tricks to meet minimum requirements even when malloc() fails   即使malloc()失败也可满足最低要求的技巧 */

​    unsigned char _ubuf[3]; /* guarantee an ungetc() buffer  保证ungetc()缓冲区*/

​    unsigned char _nbuf[1]; /* guarantee a getc() buffer 保证getc()缓冲区 */



​    /* separate buffer for fgetln() when line crosses buffer boundary   当行越过缓冲区边界时，为fgetln()提供的单独缓冲区*/

​    struct  __sbuf _lb; /* buffer for fgetln()   用于fgetln()的缓冲区*/



​    /* Unix stdio files get aligned to block boundaries on fseek() */

​    int _blksize;   /* stat.st_blksize (may be != _bf._size) */

​    fpos_t  _offset;    /* current lseek offset (see WARNING)   当前的lseek偏移量*/

} FILE;

8.标准I/O库提供**缓冲**的目的是尽可能**减少**使用read和write**调用的次数**。

9.标准I/O库提供了三种类型的缓冲:

   (1)全缓冲：填满**标准I/O缓冲区**后才进行**实际I/O操作**。

​					 术语冲洗(flush)描述了标准I/O缓冲区的**写操作**。缓冲区可由标准I/O例程自动冲洗（例如，当填满一个缓冲区时），或者可以调用函数fflush冲洗一个流。

​					 在UNIX环境中，flush有两种意思：在标准I/O库方面，flush(冲洗)意味着将缓冲区的内容写到磁盘上(该缓冲区可能只是部分填满的)。在终端驱动程序方面(如函数tcflush),flush(刷新)表示丢弃已存储在缓冲区中的数据。

  (2)行缓冲：当在输入或输出中**遇到换行符**时，标准I/O库执行**I/O操作**。这允许我们一次输出一个字符(用标准I/O函数的fputc函数)，当流涉及一个终端时（如标准输入和标准输出），通常使用行缓冲。

​      使用行缓冲要注意两点：1‘.因为标准I/O库用来收集每一行的**缓冲区的长度**是<u>固定</u>的，所以只要*填满了缓冲区*，即使还没写一个换行符，也进行I/O操作。2’。当标准I/O库从以下两个地方获取输入数据——1.不带缓冲的流。2.从内核请求数据的行缓冲流——就会冲洗所有行缓冲输出流。

  (3)不带缓冲，标准I/O库**不**对字符进行**缓冲存储**。