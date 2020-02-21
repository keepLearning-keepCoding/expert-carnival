### 1.0.0  Machine Programs and Assembler Programs

### A "machine program" is a sequence of bytes that contain numbers in the range [0,2^8^],that is,8-bit numbers.Each byte is identified by its "address".Instructions are encoded in "words",that is two adjacent bytes.The address of a word is even and equals the address of its "low byte".The odd addressed byte of a word is its "high byte"."Low" and "high" indicate the weight in a base 2^8^ number system.The low byte has the weight one and the high byte has the weight 2^8^.So,the number stored in a word is 

### 				word=lowbyte + highbyte * 2^8^.

### Both words and addresses are in the range [0,2^16^].The instructions  operate on zero,one or two operands,which are byte or word encoded.

### Notation:"Numbers" mean nonnegative integers.The terms "unsigned integers" and "signed integers" are widely used to mean nonnegative integers respective integers.The notation "(un)signed" suggests,that there are signs which are (not) attched to integers.But this is misleading.

### Exercise: A word has the value 1000.What are the values l,h of its low and high bytes?

### The encoding of instructions is defined in the "PDP-11 Instruction Set"(filed in pdp11/doc/cpu),which you should read accompaning this script.

### The PDP-11 supports two operand types,namely integers and boolean arrays.The encoding of integers is explained in section 1 below.A boolean value is encoded as a number with "true"(1) and "false"(0).The PDP-11 instructions support two sizes of boolean arrays,namely eight and 16.These arrays are encoded in bytes respsective words.A word encoded boolean with entries b0,b1,...b15 is represented by the number

### b0∗2^0^ +b1∗2^1^ +...+b15∗2^15^ .

### Note the difference between a number and its notation."Hex" in "hex number" is not an attribute of the number (like e.g. "even") but indicates the notation of a number,namely as a sequence of digits with base 16.Numbers that encode instructions are often notated octal,because the instruction's code is subdivided in fields of three bits each.

### Exercise:The odd numbered entries of a byte encoded boolean array are true,the others false.What is its encoding?

### People and programming tools use octal or hexadecimal notation for a number just because it is stored in words and bytes.This is a bad habit.Use common sense when choosing the base.In this script,the C language convention is used:A leading 0 indicates base 8,a leading 0x indicates base 16.Otherwise decimal notation is used throughtout.Numbers that encode instructions,or numbers in assembler programs however are notated with base 8,even if not starting with a "0".



### An assembler program differs from a machine program by naming numbers(symbols) and operations (mnemonics).The assembler builds instructions,addresses and operands from mnemonics,symbols and numbers and writes a sequence of assembled words,thereby translating an assembler program to a machine program.Symbols,mnemonics and numbers are notated using the ASCII character set.

### The paper "Unix Assembler Reference Manual" (filed in v6/doc/as.ps) defines syntax and meaning of assembler programs-more comprehensive and less verbose as seems appropiate in this tutorial.

### The symbols "r0","r1",..."r7","sp" and "pc" name the general registers.



### The assembler keeps track of the current location,that is ,the address of the currently assembled word,in the "location counter".Its name is ".",also known as "dot".At the start of an assembly dot is set to the first address of the program,known as the program's "origin",dot is then incremented by 2 with every word assembled.



一个"表达式"是一个数字或符号，它可能通过像"+"或"-"一样的运算符与数字和符号结合起来。在汇编期间，对该表达式求值。这不同于像"C"一样的高级语言，在这些语言中，表达式可能被翻译为机器指令的序列，并在运行时求值。

汇编器隐式地分配给符号、数字和表达式某种"类型"。这些类型包括"相对"和"绝对地址"，"寄存器"和指令。此处的"相对"意味着该地址相对于程序的起始处，它的原点。

某个表达式的类型可以被'\^'操作符修改。例如，汇编语句".=400\^."设置地址计数器为0400。类型强制转换运算符"\^",把**左手侧表达式的类型**强制转换为**右手侧表达式的类型**。在示例"400\^."中，"."的类型(即"相对地址")，被强制转换为"400"的类型，即"绝对地址"。以符号起始、后跟":"的行,定义了"标签"。它的值被设置为点，它的类型是相对地址。

汇编器期望数字以八进制表示。

一个"指令语句"由一个助记符和——依赖于操作数的数目——零个、一个或两个操作数字段构成。当有两个操作数字段时，首先出现源字段，紧跟一个",",再跟一个目的字段，如，"mov src,dest"。操作数字段指定地址模式和寄存器。四偶数模式指定了**操作数的地址**(直接寻址)，且四奇数模式指定了**操作数地址的地址**(间接寻址)。PDP-11架构是"常规的"，即，无论什么**指令**，你都可以在某个**操作数字段**中使用所有**寻址模式**。此外，**寄存器**是"通用的",即，无论什么**指令**，你都可以使用**操作数规范**中的所有**八个寄存器**。**规则性**和**通用性**意味着很少的简单规则定义一个强大的系统——好设计的特征。

地址模式，后跟模式名称。 

—— 模式0：   寄存器(register)

​		由以下指定:   一个寄存器

​		含义:该寄存器容纳操作数。

​        示例:r0

——模式1：寄存器间接寻址(register indirect)

​		由以下指定：一个带括号的寄存器。

​		含义：该寄存器容纳操作数的地址。

​		示例：(r0)

——模式2，4： 自增；自减

​		由以下指定:一个带括号的寄存器，后缀为"+";一个带括号的寄存器，前缀为"-"。

​		含义：寄存器在响应后增加，在寄存器被用于寻址操作数前减少。

​		示例: (r0)+,-(r0)

——模式6：  索引

​		由以下指定:一个表达式，后跟一个带括号的寄存器。

​		含义:表达式的值和寄存器寻址操作数。表达式的值在指令后的单词中进行汇编。

​		示例:10(r0)

——模式1，3，5，7： ~indirect

​		由以下指定：一个"*",后跟一个偶数模式(即，直接)规范。

​		含义：在相应的直接模式的语境下，用"操作数地址"替换"操作数"。

​		示例:r0,(r0)+,-(r0),10(r0)

所以，即使在汇编器中，也可以通过带括号的寄存器或”*“后接寄存器语法糖的方式，来指定地址模式1。当你在模式7中放置表达式时，假定为"0"。

练习:如果你在模式6中放置表达式，将得到什么?

在模式6和7中，会隐式地使用**程序计数器**来寻址**保存表达式值的字**。当**隐式**地使用**程序计数器**时，它会被**立即加2**。每当**获取指令字**或**遇到地址模式6或7**时，都会出现这种情形。



练习:在地址零处执行每个指令，在该指令执行以后，PC将会是什么?

a) inc r0

b) inc 10(r0)  （注意：'10'是八进制数，这是一个汇编器语句)

c) inc *10(r0)

d) inc pc

e) inc (pc)

f) inc 10(pc)

g) inc *10(pc)

h) inc (pc)+

**汇编器**提供了**以地址模式**显式指定PC的快捷方式；与从**地址计数器**处进一步计算**PC-相关偏置**的方式。

模式2： 立即(寄存器间接)

被指定为:字母"$",后跟一个表达式。

含义：表达式的值是操作数。它被储存在紧跟指令的字中。

例子：$10,"(r7)+;10"的简写



模式6:相对(索引)

被指定为：一个表达式。

含义:此表达式代表**操作数的地址**。相对于点+2的偏移量在指令后跟着的字里进行组合。

示例: 10,"2(r7)"的简写

在这个(和下个例子中)，假定保存偏移量的字位于4处。该偏移量相对于.+2,即6，因此结果是6.