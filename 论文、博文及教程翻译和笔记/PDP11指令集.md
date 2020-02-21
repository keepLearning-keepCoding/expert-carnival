## PDP-11 指令集



```
我们解释自然事物的成因，应简洁到既真且足以解释其表象的程度。

													——艾萨克 牛顿，原理：世界的体系
```



​																		`艾萨克·牛顿，原理:世界的体系`

​			本论文描述了**PDP-11/40指令集**，包括**扩展指令集(EIS)**和**内存管理单元(MMU)**。这一特定的配置类似于John Lions于1976/1977年在新南威尔士大学研究**第六版UNIX**期间所使用的机器。自从Ken Thompson和Dennis Ritchie 于20世纪七十年代在这些机器上开发**UNIX V6**和**V7**起，已经添加了更强大的**PDP-11/45**和**PDP-11/70**模型的**特性**。

​			符号: 用**非负整数来**代表**寄存器的内容**、**内存**和**地址**。打头的零代表八进制数，打头的"0x"代表十六进制标记。数字的(水平或垂直)序列总是以**最高有效位**开始。"低内存"是低地址的储存格。"K"等于2^10。若i<k,则整数区间"[i,k)"包括i且不包括k；否则该区间为空。表达式使用了C语言。

0  寄存器

 所有的寄存器都是16位宽。

0.0 通用寄存器 R0, R1, R2, R3, R4, R5 (FP), R6 (SP), R7 (PC)

**PDP-11**有**8个通用寄存器**。通过**3位寄存器数**(用指令字来编码)来**显式寻址**。除了这些，**隐式地**使用**3个寄存器**，即:

R7，程序计数器(PC),指向接下来将要执行的指令。在每次读取由PC隐式寻址的单词后，在被用于地址计算前，**PC增加2**。

R6，堆栈指针(SP),通过应用一种"后进/先出"的内存分配方案，支持子例程、陷阱和中断链接。它被jsr, rts, mark, sys 和 rtt隐式使用。有两种SP，一种在用户模式(USP)活跃，另一种在内核模式(KSP)活跃。"push x"分配内存，并保存值x,"pop y"归还了y，并释放了为y分配的内存。堆栈向低内存方向生长。若**SP**被初始化为i,则该堆栈占据了位于**[SP,i)**区间内的内存。那么SP寻址被最后分配的条目。

R5,**帧指针**，由**标记指令**唯一**隐式使用**，以支持**子例程链接**。

0.1 **处理器状态字PSW**(位于0777776处)

PSW的位被赋值为:

**名称**	**宽度**	**含义**

CM    	2	  当前操作模式，00是内核模式，11是用户模式

PM    	2	 之前的操作模式

****  	4	 未被使用

IPL   	3	  中断优先级

T     	1	   允许追踪陷阱

NZVC	4	 条件代码

如果中断设备的硬连接总线请求数(BR)大于IPL(中断优先级)，将处理未决的中断。

如果设置了T-位，则在执行了一条指令后，在14处捕获陷阱。T-位允许调试器单步执行一个程序。

算数和布尔指令修改了条件代码(CC)(modify condition code)——这些代码将在之后被条件分支指令感知到。



N代表"结果为负数"

Z代表"结果为零"

V代表"有符号溢出"

C代表进位，即，无符号加溢出。

0.2 面板寄存器(位于0777570处)

有两种**面板寄存器**:只读开关寄存器(SR)，它反映了面板开关的状态，和一个只写显示寄存器(DR),它用于控制面板的灯。

在通电后，除两个寄存器外，所有寄存器都被设置为零。PSW中的IPL(中断优先级)被设置为7，开关寄存器并未被改变。

### 1 地址

**16位(虚拟)地址**被转换为**18位(物理)总线地址**。**前58K的地址**被映射到内存，

### 前58K的地址被映射到内存，

剩余8K的地址被用于存取设备寄存器，且被映射到最后8K总线地址。最后的**8K块**被称为"I/O页"。

这个映射被定义为:

​	[0,   56K) --> [0,     56K),	x --> x
​	[56K, 64K) --> [248K, 256K),	x --> x + 192K (== x | 0600000)

可以启用内存管理单元(MMU),以使这一映射处于软件控制下。MMU处理两种**映射**(又名**地址空间**)——一个在**用户模式**活跃，另一个在**内核模式**活跃。在通电后，**禁用MMU**。

2  **操作数**和**操作**

操作数被存储在**8位字节**、**16位字**和**32位长字**中。乘法指令**乘**、**除**和**"算数移位连接"**(即，mul,div,ashc)——只有这几个指令在长字上操作。

此指令集提供了对**长度为8**或**16**的**布尔数组**的**有符号整数算数(字节，字和长字)操作**，和对**无符号整数**的**加法算数操作**。

大多数的**一元和二元操作**都是针对**字节大小**和**字大小**的**操作数**实现的。加法和减法只操作**字**。

**字**被储存在**内存或寄存器**上，**字节**只储存在**内存**中。**字**的**地址**是**偶数**，且等于该字的**低字节("小端")地址**。如果**寄存器**是某个字节操作的**目标**，该字节的**有符号值**被储存在**寄存器**中，即，**符号位**被扩展为该**寄存器的高字节**。如果某个**寄存器**是**字节操作**的源，则该**寄存器**被缩减为它的**低字节**。

一个**长字操作数**被储存在一对**通用寄存器RS**中——r,R的数值为偶数,S的数值为r+1。**R**保存着**高位字**("大端")。

3 **指令格式**和**地址模式**

   **指令字**的组成部分是:

名称	宽度	含义	
w 	1	 **操作数宽度**，0指定字，1指定字节
ss 	6	**源操作数规范**
dd	6	**目的操作数规范**
a	   3	   **地址模式**
r	   3	      **寄存器编号**
o	变化的	**操作码**
nn	8	 有符号的**字偏移量**(在分支中);**系统调用数**(在sys中)
nn	6	     **无符号数**
m	4	    在**CC操作**中，**选择条件标志NZVC**的掩码

**操作数规范ss**和**dd**由**地址模式**和**寄存器数**组成。

符号:包含**4位**或**8位**部分的指令被标记为**十六进制**，其他的则被标记为**八进制**。如果是**八进制**，则第一个字符代表1位，且其它的字符代表3位；如果是**十六进制**，则每个字符代表**4位**。**十六进制符号**的前缀是"**0x**"。

名称													格式	       								示例
**双操作数**										 **wossdd**  								**mov src,dst**
**寄存器和操作数**				  		   **woordd**  							       **jsr r5,subr**
**寄存器和操作数**					          **woorss**									  **ash 2,r0**
**单操作数**										 **wooodd**  									**inc a**
**单寄存器**										   **ooooor**  									**rts r5**
**零操作数**										   **oooooo**  									**halt**
**分支**												   **0xoonn**									**br label**
**CC操作**											  **0xooom**									  **sec**

根据**地址模式**来指定**操作数**:

**地址模式**											**操作数**										**名称**
**0**															 **R**											**寄存器**
**1**														  **m[R]**								   **寄存器间接寻址**
**2**													**m[R]; R=R+w** 							**自增	(pop)**
**3**													**m[m[R]]; R=R+2**						**自增间接寻址(pop)**
**4**													**R=R-w; m[R]**								**自减(push)**
**5**													**R=R-2; m[m[R]]**						**自减间接寻址(push)**
**6**													**m[m[PC]+R]**								   **索引**
**7**													**m[m[m[PC]+R]]**						**索引间接寻址**

此处，R是**操作数规范**中的**所选寄存器**，m是**内存**，w是**操作数宽度**，即，w等于1(代表**字节操作数**)，且2代表**字操作数**。如果R是**SP**(堆栈指针寄存器)，w == 2,即便是对**字节操作数**也是如此。
4  **指令**

​		指令被分为四种列表:

- 陷阱和其他特殊指令
- 算数、布尔值和数据转移
- 跳转和子例程链接
-  分支

符号:在整个**指令列表**中，**s**和**d**分别表示**源**和**目的操作数**。在**赋值操作符**("=")的**右侧**，**d**代表着**应用赋值操作前**的值。

4.0 **陷阱**和**其他特殊指令**

位于[0,0400)这个区间里的内存——"**黄色堆栈**"——被保留下来，用于**中断向量**。

一个条目跨越两个字。第一个字保存**中断服务例程(ISR)**的**陷阱程序地址**；第二个保存**程序状态(PS)**,这是**PSW的低字节**。

当执行一个**陷阱**或**中断**，**CPU**切换到**内核模式**，把前一个**PSW**和**PC**压入**内核堆栈**，把**前一个操作模式**赋给**PM**，并使用向量中的**PS设置**来执行**陷阱例程**。这一序列是由"trap at n"缩写而成，此处，n是向量条目的地址。

返回被中断/进入陷阱的程序(rti,rtt)，弹出了PC和PSW，因此撤销了由陷阱和中断造成的状态改变。在用户模式下，当这些指令从堆栈中弹出**PSW**时，将不会改变**CM**，**PM**和**IPL**。

rtt与rti的不同之处在于——即便在执行过程中设置了**T-位**，它也将不会进入陷阱。这启用了调试器，以执行被调试程序的一条指令。

用一个古怪的地址来存取字操作数或指令，存取不存在的内存，在用户模式执行暂停指令,或在内核模式下推入黄色堆栈，将在4处被陷阱捕获，而执行一个非法(即未实现的)指令被捕获在10处。

如果保存PSW和PC时，出现**内存错误**，陷阱的执行可能会失败。在那一情形下，两个字都被保存在位于[0,4)区间内的紧急堆栈内，并在4处执行"**红色堆栈陷阱**"。

在模拟器和系统陷阱指令中，它的低字节都被保留给操作系统。

在UNIX中，它保存着系统调用码。

#### ass		读作		      					代码								操作
halt			**停止**(halt)				   			 000000  								  **停止处理器(特许的)**
wait		   **等待**(wait)				  	 		 000001  										**等待中断**
rti		**返回中断**(return to intr)  			 000002 								 **PC = SP++*; PSW = SP++***
bpt		**断点**(breakpoint)						000003  							 **在14处陷入陷阱(用于调试)**
iot    		**i/o陷阱**(i/o trap)			  		 000004  								  **在20处陷入陷阱**
reset		**重置**(reset)				    			000005						 **重置I/O设备(在用户模式无操作)**
rtt		**返回陷阱**(return to trap)  	   	 000006  								**PC = SP++*; PSW = SP++***
emt	  **模拟器陷阱**(emulator trap)	 	0x88nn							**在30处陷入陷阱(DEC使用)**
sys		**系统陷阱**(system trap)		        0x89nn						    **在34处陷入陷阱(Unix使用)**


### 4.1 算数，布尔和数据转移

**移位/旋转:**ror, rot, asr, asl, ash, ashc

这些指令实现了乘法操作，其中一个操作数是2的幂。C标志被设置为移出的位。

整数除法:div, asr, ror, ash, ashc

div向零截断(标记为"/"),而右移则截断为更小的整数，标记为"//"。

通过**前一个地址空间**存取内存:mfpi, mtpi。由前一个模式地址空间，而非当前的模式地址空间来控制**操作数虚拟地址**的映射。前一个模式由**PM(previous mode)**决定。如果操作数是SP，则选择前一个模式的SP。使用当前堆栈，mfpi推入及mtpi弹出操作数。

CC操作:cln, clz, clv, clc, sen, sez, sev, sec。

这些指令**清除rsp**,**设置条件代码**。通过**指令字**中的**掩码m**来选择**CC**。通过集合或清除类型的或指令可选择多余一个标志。当未选择标志时，CC操作退化为空操作。

通过**指令代码**来排序**列表**。**字节指令**(代码[100000, 104000), [105000, 106400), [110000, 170000))被忽略。

ass	      				read					code				operation					Condition Codes affected

cl?     clear CC	0x00Am			NZVC = NZVC & ~m
se?	set CC		0x00Bm			NZVC = NZVC | m
swab	swab bytes	0003dd	d.hi <-> d.lo	N, Z from low byte; V=C=0
clr(b)	clear (byte)	w050dd	d=0		N, Z, V, C
com(b)  complement	w051dd	d=~d		N, Z; V=0; C=1
inc(b)	increment	w052dd	d=d+1		N, Z, V
dec(b)	decrement	w053dd	d=d-1		N, Z, V
neg(b)  negate		w054dd	d=0-d		N, Z, V, C
adc(b)	add carry	w055dd	d=d+C		N, Z, V, C
sbc(b)  sub carry	w056dd	d=d-C		N, Z, V, C
tst(b)  test		w057dd			N, Z; V=C=0
ror(b)  rotate right	w060dd	d=d//2 - C*2^15 N, Z, V; C=d%2
rol(b)  rotate left	w061dd	d=d*2 + C	N, Z, V, C
asr(b)  shift right	w062dd	d=d//2		N, Z, V; C=d%2
asl(b)  shift left	w063dd	d=d*2		N, Z, V, C
mfpi	mv fr prev i-sp	0065ss	--SP* = s	N, Z; V=0
mtpi	mv to prev i-sp	0066dd	d = SP++*	N, Z; V=0
sxt	sign extend	0067dd  d=-N		N, Z, V
mov(b)	move (byte)	w1ssdd	d=s		N, Z; V=0
cmp(b)	compare		w2ssdd			N, Z, V, C as if d = s-d
bit(b)	bit test	w3ssdd  		N, Z as if d = s&d; V=0
bic(b)	bit clear	w4ssdd	d = d & ~s	N, Z; V=0
bis(b)	bit set		w5ssdd	d = d | s	N, Z; V=0
add	add		06ssdd	d = d + s	N, Z, V, C
sub	subtract	16ssdd	d = d - s	N, Z, V, C
mul	multiply, r evn	070rss  RS = s*R	N, Z, V	(C see next line)
mul	     "	, r odd 070rss  R = s*R		C="s*R does not fit in word"
div	divide		071rss	R=RS/s; S=RS%s	N, Z, V; C="/ by zero"
ash	arith shift     072rss	R=R*2^s		N, Z, V, C
ashc	" conct., r evn 073rss  RS=RS*2^s	N, Z, V, C (C=RS%2 if s > 0)
ashc	" conct., r odd 073rss  R=R*2^s		N, Z, V, C (C=R%2 if s > 0)
xor	exclusive or	074rdd  d = d ^ R	N, Z; V=0

4.2 Subroutine Linkage and Jump

Jump subroutine (jsr) pushes R, saves the return address (i.e., PC, the
address of the next instruction) in R, and jumps to the address of d.
It follows that if R is the PC, jsr simply pushes the PC and jumps.

The destination of jmp and jsr must not be a register, i.e., the
address mode must not equal zero. If it does, a trap at 10 occurs.

Return from subroutine (rts) restores the PC from R and pops R.
It follows that if R is the PC, rts just pops it.

With the mark instruction being the word last pushed, jmp (sp) means:
Free nn+1 (i.e. including mark) words from the stack, restore the
caller's FP and return; nn is a 6-bit unsigned integer.

Subtract one and branch (sob) decrements R and, if R != 0, jumps up
nn words, where nn is a 6-bit unsigned integer.

ass	read		code	operation
------------------------------------------------------------------------------
jmp	jump		0001dd  PC = &d (a-mode > 0)
rts	return fr subr	00020r  PC = R; R = *SP++
jsr     jump subroutine	004rdd  *--SP = R; R = PC; PC = &d (a-mode > 0)
mark    mark		0064nn  SP = PC + 2*nn; PC = FP; FP = *SP++
sob	subtract one    077rnn  R = R - 1; if R != 0: PC = PC - 2*nn 

4.3 Branches

If the condition holds, these instructions set PC = PC - 2*nn.  The
column labeled "s/u" indicates whether the tested condition is
appropiate for signed respective unsigned artithmetic.

ass	read		code	s/u	condition	cmp a, b 	tst a
------------------------------------------------------------------------------
br	branch		0x01nn	s/u	always 
bne	not equal	0x02nn	s/u	!Z		a != b		a != 0
beq	equal		0x03nn	s/u	Z		a == b		a == 0
bge	greater equal	0x04nn	s	N == V  	a >= b
blt	less than	0x05nn	s	N != V  	a <  b
bgt	greater than	0x06nn	s	!Z && N == V	a >  b
ble	less equal	0x07nn	s	Z | N != V	a <= b
bpl	plus		0x80nn	s	!N				a >= 0
bmi	minus		0x81nn	s	N				a <  0
bhi	high		0x82nn	u	!C & !Z		a >  b
blos	lower or same	0x83nn	a	C | Z		a <= b
bvc	overflow clear	0x84nn	s	!V		no overflow
bvs	overflow set	0x85nn	s	V		overflow
bcc	carry clear	0x86nn	u	!C		a >= b
bhis    higher or same		another name for bcc	
bcs	carry set	0x87nn	u	C		a <  b
blo	lower			another name for bcs

5 Memory Management Unit

5.0 The Mapping as Controlled by Paging Registers

The virtual address range [0, 64K) is partitioned into eight pages
	[0*8K, 1*8K), [1*8K, 2*8K), ... , [7*8K, 8*8K) .
Each page is assigned a page description register (PDR) and a page
address register (PAR).  The virtual address in a page are mapped
to a range of physical addresses which starts at p = PAR*64.

The meaning of the PDR bits are:
name	width	meaning
*	1	not used
S	7	with b=64*S, the lower part of page n is [n, n+b].
*	1	not used
C	1	set, when memory addressed by this page is changed
                cleared, when the PDR is changed
**	2	not used
U	1	upper part of the page is valid, i.e., mapped
W	1	write permission
R	1	read permission
*	1	not used

Let v be a virtual address contained in the page [n, n+8K).  This page
is divided into a lower part [n, n+b] and an upper part [n+b, n+8K].  U
controls which part of the page is mapped:

If U off:	[n,   n+b]  --> [p, p+b],    v  --> p + v - n
If U on:	[n+b, n+8K) --> [p, p+8K-b), v  --> p + v - (n+b)

A trap at 0250 is executed if one of the following conditions holds:
	R is off
	v is not mapped, i.e. not in the lower respective upper part
	W is off and the program tried to write to the memory

Physical addresses of the page registers:
kernel:	PDR 0-7: [0772300, 0772320), PAR 0-7: [0772340, 0772360)
user:	PDR 0-7: [0777600, 0777620), PAR 0-7: [0777640, 0777660)

5.1 Control and status registers

MMR0 register (at 0777572) 
The MMU is enabled if the low bit is set. The other bits are set when
the MMU traps. They indicate the reason and identify the page that
caused the trap.

mask	width	meaning
010000	1	write access and !W
004000	1	address not mapped; not in valid part of the page
002000	1	read or write access, and page not readable
000140	2	operation mode to which the page belongs
000020	1	if set, page is from data space (PDP-11/45, /70 only)
000016	3	page number
000001	1	enable MMU 

MMR2 (at 0777576) is a status register that holds the address of an
instruction that caused an MMU trap.

6 PDP-11/45 and PDP-11/70

6.0 Extensions of the Instruction Set.

Instructions that are illegal on the PDP-11/40 might be implemented by
other PDP-11 models or by optional hardware extensions.

The  MMU in the PDP-11/45/70 supports two mappings per operation mode.
One is used for words addressed by the PC, i.e., instructions, the
other for the rest. This feature is called "separate I/D space".

Floating point instructions are offered either by the "Floating Point
Instruction Set" (FIS), a small extension, or by the "FP11", a full
blown floating point processor.

The mtps/mfps instructions are only needed by models that cannot
access the PSW, and therefore the PS, via the I/O page.

ass	read			 code		implemented in
--------------------------------------------------------------
mfpt	move from processor type 000007		other models
spl	set IPL to m		 00023m		PDP-11/45, PDP-11/70
csm	call supervisor mode	 0070dd		PDP-11/45, PDP-11/70
tstset	test & set		 0072dd		multiprocessor machines
wrtlck	write locked		 0073dd		multiprocessor machines
FIS	floating pt. instr. set	 075000-075777	optional for PDP-11/40
CIS	commercial instr. set	 076000-076777	optional for other models
mtps	move to PS		 1064dd		other models
mfpd	move from prev d-space	 1065dd		PDP-11/45, PDP-11/70
mtpd	move to prev d-space	 1066dd		PDP-11/45, PDP-11/70
mfps	move from PS		 1067dd		other models
FP11	floating pt. processor	 170000-177777	PDP-11/70, optionial for /45

6.1 The MMU of the PDP-11/45 and PDP-11/70

The CPUs with separate I/D space need another four sets of paging
registers, namely PDRs and PARs for the kernel data space and for the
user data space.  Each of these sets is located in the I/O page below
the corresponding set of the instruction space. Since these PDP-11s
offer a third operation mode (supervisor mode), they also have another
two sets of paging registers for this mode. (at [772200, 772300))

MMR1 (at 777574) identifies the registers changed by the incrementing /
decrementing address modes in an instruction that caused an MMU trap.
The increment is in the range [-2, +2] and encoded as a 3-bit integer
which is negative in case of decrementing address modes.

The meanings of the bits are:
width	meaning
2	not used
3	increment from source a-mode
3	register from source a-mode
2	not used
3	increment from destination a-mode
3	register from destination a-mode

MMR3 (at 777516) is a control register used to enable separate I/D
space and the CSM instruction, i.e. the supervisor mode.

The bits are assigned as:
width	meaning
10	not used
1	enable 22bit I/O addresses (PDP-11/70 only)
1	enable 22bit physical addresses (PDP-11/70 only)
1	enable csm
1	enable seperate kernel data space
1	enable seperate supervisor data space
1	enable seperate user data space

7 Assignment of Instruction Codes
"Illegal" means illegal on Lions' PDP-11/40

000000-000006	traps; halt, reset ...
000007-000077	illegal; mfpt
000100-000207	jump, rts 
000210-000237	illegal; spl
000240-000377	arithmetic, boolean and data trnsfr; CC operations, swab bytes
000400-003777	branches
004000-004777	jsr
005000-006377	arithmetic, boolean and data transfer; single word operand
006400-006477	mark
006500-006777	arithmetic, boolean and data transfer; single word operand
007000-007777	illegal, csm, tstset, wrtlck
010000-067777	arithmetic, boolean and data transfer; two word operands
070000-073777	extended instruction set (EIS); mul, div, ash, ashc
074000-074777	boolean; XOR
075000-076777	illegal
077000-077777   sob
100000-103777	branches
104000-104777	traps; emt, sys
105000-106377	arithmetic, boolean and data transfer; single byte operand
106400-107777	illegal; mtps, mfpd, mtpd, mfps
110000-167777	arithmetic, boolean and data transfer; two byte operands
170000-177777	illegal; FP11