## IOCTL(2)                 Linux程序员手册                 IOCTL(2)

## 名称 

​       ioctl - **控制设备**

## 提要    

```
       #include <sys/ioctl.h>

       int ioctl(int fd, unsigned long request, ...);
```

## 描述    

​         **ioctl()**系统调用操作**特殊文件**的**底层设备参数**。尤其是，可以用**ioctl()请求**来控制**字符特殊文件**(如**终端**)的许多**操作特性**。参数fd必须是一个**打开的文件描述符**。

​		第二个**参数**是一个依赖于设备的**请求码**。第三个参数是一个**指向内存**的**无类型指针**。它的**传统记法**为**char *argp**(这来自于**void ***还不是**有效C语言语法**的时代)，在**本次讨论**中也将这样命名。

​         **ioctl()请求**(**request**)已在其内部编码如下:参数是个**输入(in)参数**还是**输出(out)参数**，用**字节表示**的参数**argp**的大小。用于指定**ioctl()请求**的**宏**和**定义**位于文件**<sys/ioctl.h>**中。

## 返回值

​     通常，函数**执行成功**会返回**零**。一些**ioctl()请求**使用**返回值**作为一个**输出参数**，并且当**函数运行成功**时返回一个**非负值**。当**出错**时，会返回**-1**，并为**errno**设置**合适的值**。

## 错误     

​		   **EBADF**      **fd**不是一个**有效的文件描述符**。

​           **EFAULT**    **argp**引用了一块无法访问的**内存区域**。

​           **EINVAL**     **request** 或 **argp** 无效。

​           **ENOTTY**     **fd** 没有和一个**字符特殊设备**相关联。

​           **ENOTTY**      **指定的请求**并不适用于**文件描述符fd**所引用的**那种对象**。

## 遵循    

 没有单一的标准。函数**ioctl()**的**参数、返回值和语义**会随着**所讨论的设备驱动器**而变化(对于那些并不完全符合UNIX**流I/O模型**的操作，这个调用用作**笼统的函数调用**)。参阅**ioctl_list(2)** 来获取许多**知名ioctl()调用**的列表。**ioctl系统调用**出现在**第7版AT&T UNIX**。

## 注释  

​       要使用这一调用，需要一个**打开的文件描述符**。**open(2)**调用通常有**不必要的副作用**——在Linux下通过给它设置**O_NONBLOCK**标志来避免这一副作用。



## 另请参阅

```
       execve(2), fcntl(2), ioctl_console(2), ioctl_fat(2),
       ioctl_ficlonerange(2), ioctl_fideduperange(2), ioctl_getfsmap(2),
       ioctl_iflags(2), ioctl_list(2), ioctl_ns(2), ioctl_tty(2),
       ioctl_userfaultfd(2), open(2), sd(4), tty(4)
```

## 

### Linux                            2017-05-03                         IOCTL(2)

### 原文链接：http://man7.org/linux/man-pages/man2/ioctl.2.html