设置UNIX ——第六版

随附:

1. ​	UNIX程序员手册，第六版

2. ​	带有如下标题的文档:

   -  设置UNIX——第六版
   -  UNIX分时系统
   -  C参考手册
   - C语言编程——教程
   - UNIX汇编器参考手册
   - ED文本编辑器入门手册
   - UNIX初学者教程
   - *RATFOR*——用于*Rational Fortran*的预处理器
   - *YACC*——另一个编译器的编译器
   - *NROFF*用户手册
   - UNIX I/O 系统
   - *Tmg*编译器编写语言手册
   - UNIX安全
   - M6宏处理程序
   - 数学排版系统
   - DC——交互式桌面计算器
   - BC——任意精度的桌面计算器语言
   - 便携式C库(UNIX中)
   - UNIX总结

3. 磁带或磁盘组上的UNIX软件

   ​		如果你准备这样做，立即制作磁盘或磁带的副本以防灾难，不失为一个好主意。该磁带包含12100个521字节记录，其后紧随着一个文件标记；只有磁盘上前4000个512字节的块是重要的。

   ​	  发行的系统对应于三个相当完整的RK包。第一个PK包包含所有程序的二进制版本，以及操作系统本身的源码；第二个PK包包含所有的剩余源程序；第三个PK包包含被用于使用格式化程序roff或nroff来打印的手册。"二进制"磁盘足以运行系统，但你几乎必然地想要修改一些源代码。

#### 从磁带制作一个磁盘

​	如果你的系统在磁带上，执行以下引导过程，以获取带有二进制的磁盘。

​			1.在加载点，将磁盘安装在驱动0上。

​			2.在驱动0上安装格式化的磁盘包。

​			3.键入，并在100000处执行。

​				 TU10                TU16
​    			 012700          (待添加的)
​    			 172526
​     			010040
​     			012740
​     			060003
​     			000777

​			磁盘应移动，并且CPU循环。(TU10代码不是用于磁带的DEC批量ROM；它读取块零，而非块1)。

​			4.停止，并在0处重启CPU。磁带应倒带。控制台应输出'='。

​			5.按以下指导，把磁带复制到磁盘。这假定TU10和RK05；关于其他设备的信息，请看第6条。机器的打印输出以斜体显示。通过回车或换行来终止你键入的每一行。

​				

```
					= tmrk
          disk offset
          0
          tape offset
          100       (See 6 below 参阅以下第6条)
          count
          1         (The tape should move 磁带应该移动)
          = tmrk
          disk offset
          1
          tape offset
          101       (See 7 below 参阅以下第7条)
          count
          3999      (磁带移动更多)
          =
```

解释：**tmrk**程序用给定的**偏置(offsets)**和**数目(counts),**来把磁带复制到磁盘。第一次使用tmrk，把引导程序复制到磁盘块区0；第二次使用tmrk,把文件系统本身复制到磁盘。通过从137000开始，你可能返回'='层级。

​			6.如果你的磁带型号是TU16,则在以上的例子中，应使用'htrk',而非'tmrk'。如果你有个RP03磁盘，应使用'tmrp'或'htrp',并使用99，而非100磁带偏置。如果你有个RP04磁盘，应使用'tmhp'或'hthp'，而非'tmrk',并使用98，而非100磁带偏置。不同的偏置将加载适合它们将驻留的磁盘的引导程序。

​			7.这一过程生成"二进制"磁盘；通过使用4101(而非101)的磁带偏置，可能在另一个PK包上，生成'源'磁盘。'文档'磁盘在偏置8101处，而非偏置101处。除非你只有单个RK驱动，否则等待生成这些磁盘可能是明智的。使用UNIX本身，可以获得更好的工具。

#### 引导UNIX

一旦获得了UNIX**"二进制"磁盘**，通过键入并在100000处执行以下命令中的一条，引导系统。这些程序对应于磁盘的DEC大块ROM，因为它们在位置零处读取并执行块0。

```
  RK05           RP03           RP04
     012700         012700         (待添加的)
     177414         176726
     005040         005040
     005040         005040
     010040         005040
     012740         010040
     000005         012740
     105710         000005
     002376         105710
     005007         002376
                    005007
```

现在按照指示的对话框进行操作，此处'@'和‘#’是命令提示符:

```
@ rkunix       (or `rpunix' or `hpunix')
     mem= xxx
     login:  root
     #
```

mem信息以.1K为单位给出了用户程序可用的内存。



### UNIX is now running,and the UNIX Programmer's manual applies;references below of the form X-Y mean the subsection named X in section Y of the manual.



### 重新配置

### 	The UNIX system running is configured to run on an 11/40 with the given disk,TU10 magtape and TU56 DECtape.This is almost certainly not the correct configuration.Print(cat -l) the file /usr/sys/run.This file is a set of Shell commands that will completely recompile the system source,install it in the correct libraries and build the three configuration for rk,rp and hp.





































​	