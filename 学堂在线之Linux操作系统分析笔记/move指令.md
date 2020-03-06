1.寄存器模式：以%开头的寄存器标示符。

2.立即数是以$开头的数值。

3.直接寻址：直接访问一个指定的内存地址的数据。

5.变址寻址：在间接寻址之时改变寄存器的数值。

| 编号 | 汇编指令          | 等价的C代码                 | 名称          |
| ---- | ----------------- | --------------------------- | ------------- |
| 1    | movl %eax, %edx   | edx = eax;                  | register mode |
| 2    | movl $0x123, %edx | edx=0x123;                  | immediate     |
| 3    | movl 0x123, %edx  | edx = \*(int32_t\*)0x123;   | direct        |
| 4    | movl (%ebx),%edx  | edx = \*(int32_t\*)ebx;     | indirect      |
| 5    | movl 4(%ebx),%edx | edx = \*(int32_t\*)(ebx+4); | displaced     |

- 内存指令：MOV,PUSH,POP,etc
- 对于x86而言，大多数指令都能直接访问内存地址。
- b, w, l, q分别代表8、16、32、64位。



AT&T 汇编格式与Intel汇编格式略有不同。

Linux内核使用的是AT&T汇编格式。