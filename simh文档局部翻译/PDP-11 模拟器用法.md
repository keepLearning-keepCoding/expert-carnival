# 		     		PDP-11 模拟器用法

### 										   2018-06-02

## 目录

#### 1.模拟器文件

#### 2. PDP-11 特性

##### 	2.1 CPU和系统

##### 		 2.1.1  CPU

##### 		 2.1.2 系统寄存器

##### 	2.2 I/O设备

##### 		2.2.1 Unibus和Qbus DMA设备

##### 		2.2.2  I/O设备寻址

##### 	2.3 可编程I/O设备

##### 		2.3.1 PC11纸带阅读器（PTR）

##### 		2.3.2 PC11纸带打孔机 （PTP）

##### 		2.3.3 DL11终端输入  (TTI)

##### 		2.3.4 DL11终端输出  (TTO)

##### 		2.3.5 LP11行式打印机(LPT)

##### 		2.3.6 KW11-L线时钟(CLK)

##### 		2.3.7 KW11-P可编程时钟(PCLK)

##### 		2.3.8 TA11/TA60 盒式磁带(CT)

##### 	2.4 软盘驱动器

##### 		2.4.1 RX11/RX01软磁盘(RX)

##### 		2.4.2 RX211/RX02软磁盘(RY)

##### 	2.5 盒式磁盘驱动器

##### 		2.5.1 RK11/RK05盒式磁盘(RK)

##### 		2.5.2 RK611/RK06,RK07盒式磁盘(HK)

##### 		2.5.3 RL11(RLV12)/RL01,RL02 盒式磁盘 (RL)

##### 	2.6 大容量总线子系统

##### 		2.6.1 RH70/RH11大容量总线适配器 (RHA, RHB, RHC)

##### 		2.6.2 RP04/05/06/07, RM02/03/05/80 磁盘组驱动器 (RP)	

##### 		2.6.3 TM02/TM03/TE16/TU45/TU77 磁带 (TU)	

##### 		2.6.4 RS03/RS04 固定头磁盘

##### 	2.7 RQDX3/UDA50 MSCP 磁盘控制器 (RQ, RQB, RQC, RQD)

##### 	2.8 固定头磁盘

## 2     PDP-11 特性

​	PDP-11模拟器的配置如下:

| 设备名称 | simulates                                                |
| -------- | -------------------------------------------------------- |
| CPU      | 带有256KB内存的PDP-11CPU                                 |
| PTR,PTP  | PC11 纸带阅读器/打孔机                                   |
| TTI,TTO  | DL11 控制台终端                                          |
| CR       | CR11/CD11 读卡器                                         |
| LPT      | LP11行式打印机                                           |
| CLK      | KW11-L线频时钟                                           |
| PCLK     | KW11-P可编程时钟                                         |
| DCI,DCO  | DC11附加串行线（多达16根）                               |
| DLI,DLO  | KL11/DL11 附加串行线(up to 16)                           |
| DZ       | DZ11  8线终端多路复用器（多达4个）                       |
| VH       | DHU11/DHQ11 8线终端多路复用器（多达4个）                 |
| RK       | 带有8个驱动的RK11/RK05盒式磁盘控制器                     |
| HK       | 带有8个驱动的RK611/RK06,RK07盒式磁盘控制器               |
| RC       | RC11固定头磁盘                                           |
| RF       | RF11/RS11固定头磁盘                                      |
| RL       | 带有四个驱动的RL11(RLV12)/RL01,RL02盒式磁盘控制器        |
| RH       | RH11/RH70大容量总线适配器（多达两个）                    |
| RP       | 带有八个驱动的RP04/05/06/07, RM02/03/05/80大容量总线磁盘 |
| RQ       | 带有四个驱动的RQDX3/UDA50 MSCP控制器                     |
| RQB      | （第二个)带有四个驱动的RQDX3/UDA50 MSCP控制器            |
| RQC      | （第三个)带有四个驱动的RQDX3/UDA50 MSCP控制器            |
| RQD      | （第四个)带有四个驱动的RQDX3/UDA50 MSCP控制器            |
| RX       | 带有两个驱动的RX11/RX01软盘控制器                        |
| RY       | 带有两个驱动的RX211/RX01软盘控制器                       |
| TA       | 带有两个驱动的TA11/TU60盒式控制器                        |
| TC       | 带有8个驱动的TC11/TU56 DEC磁带控制器                     |
| TM       | 带有8个驱动的TM11/TU10磁带控制器                         |
| TS       | 带有1个驱动的TS11/TSV05磁带控制器                        |
| TQ       | 带有四个驱动的TQK50/TU81 TMSCP磁带控制器                 |
| TU       | 带有8个驱动的TM02/TM03磁带信息格式转换器                 |
| XQ       | DELQA/DEQNA Qbus以太网控制器                             |
| XQB      | 第二个DELQA/DEQNA Qbus以太网控制器                       |
| XU       | DELUA/DEUNA Unibus 以太网控制器                          |
| XUB      | （第二个）DELUA/DEUNA Unibus 以太网控制器                |
| KE       | KE11A扩展算术选项                                        |
| KG       | KG11A通信算术选项                                        |

 DZ, VH, DCI/DCO, DLI/DLO, RK, HK, RC, RF, RL, RP, RQ, RQB, RQC, RQD, RX, RY, TA, TC, TM, TS, TQ, XQ, XQB, XU, XUB, KE和 KG 这些设备可被设置为禁用（DISABLED）。

DCI/DCO, DLI/DLO, RC, RF, RQB, RQC, RQD, RY, TA, TS, VH, XQB, XU, XUB, KE和 KG 这些设备默认是禁用的。

PDP-11模拟器实现了几个唯一的终止条件：

——在异常向量获取期间终止，并设置了寄存器STOP_VEC

——在异常栈压入期间终止，并设置了寄存器STOP_SPA

——陷阱条件‘n'触发；且设置了寄存器STOP_TRAP\<n\>

——等待进入状态，且没有未完成的I/O操作（即，永远不会发生中断）

——模拟的DECtape运行到了卷筒的末端，并设置了STOP_OFFR标志

LOAD命令支持标准二进制格式磁带。

DUMP命令未实现。

### 2.1 CPU和系统

#### 2.1.1  CPU

**CPU选项**包括**CPU类型**、**指定类型**的**CPU指令集选项**及**主存**的大小。

​    **SET CPU 11/03			设置 CPU 类型为11/03**

​	**SET CPU 11/04			设置 CPU 类型为 11/04**

​	**SET CPU 11/05			设置 CPU 类型为 11/05**

​	**SET CPU 11/20			设置 CPU 类型为 11/20**

​	**SET CPU 11/23			设置 CPU 类型为 11/23**

​	**SET CPU 11/23+			设置 CPU 类型为 11/23+**

​	**SET CPU 11/24			设置 CPU 类型为 11/24**

​	**SET CPU 11/34			设置 CPU 类型为 11/34**

​	**SET CPU 11/40			设置 CPU 类型为 11/40**

​	**SET CPU 11/44			设置 CPU 类型为 11/44**

​	**SET CPU 11/45			设置 CPU 类型为 11/45**

​	**SET CPU 11/53			设置 CPU 类型为 11/53**

​	**SET CPU 11/60			设置 CPU 类型为 11/60**

​	**SET CPU 11/70			设置 CPU 类型为 11/70**

​	**SET CPU 11/73			设置 CPU 类型为 11/73**

​	**SET CPU 11/73B			设置 CPU 类型为 11/73B**

​	**SET CPU 11/83			设置 CPU 类型为 11/83**

​	**SET CPU 11/84			设置 CPU 类型为 11/84**

​	**SET CPU 11/93			设置 CPU 类型为 11/93**

​	**SET CPU 11/94			设置 CPU 类型为 11/94**

​	**SET CPU U18				弃用; 等价于 11/45**

​	**SET CPU URH11			弃用; 等价于 11/84**

​	**SET CPU URH70			弃用; 等价于 11/70**

​	**SET CPU Q22				弃用; 等价于 11/73**

​	**SET CPU NOEIS			禁用 EIS 指令**

​	**SET CPU EIS				启用 EIS 指令**

​	**SET CPU NOFIS			禁用 FIS 指令**

​	**SET CPU FIS				启用 FIS 指令**

   	**SET CPU NOFPP			禁用 FPP 指令**

​	**SET CPU FPP				启用 FPP 指令**

​	**SET CPU NOCIS			禁用 CIS 指令**

​	**SET CPU CIS				启用 CIS 指令**

​	**SET CPU 16K				设置内存大小 = 16KB**

​	**SET CPU 32K				设置内存大小 = 32KB**

​	**SET CPU 48K				设置内存大小 = 48KB**

​	**SET CPU 64K				设置内存大小 = 64KB**

​	**SET CPU 96K				设置内存大小 = 96KB**

​	**SET CPU 128K			设置内存大小 = 128KB**

​	**SET CPU 192K			设置内存大小 = 192KB**

​	**SET CPU 256K			设置内存大小 = 256KB**

​	**SET CPU 384K			设置内存大小 = 384KB**

​	**SET CPU 512K			设置内存大小 = 512KB**

​	**SET CPU 768K			设置内存大小 = 768KB**

​	**SET CPU 1024K (or 1M)		设置内存大小 = 1024KB**

​	**SET CPU 2048K (or 2M)		设置内存大小 = 2048KB**

​	**SET CPU 3072K (or 3M)		设置内存大小 = 3072KB**

​	**SET CPU 4096K (or 4M)		设置内存大小 = 4096KB**

下表展示了**CPU类型**和它们的**功能**:

| 类型   | bus  | mem  | MMU? | Umap? | EIS? | FIS? | FPP? | CIS? |
| ------ | ---- | ---- | ---- | ----- | ---- | ---- | ---- | ---- |
| 11/03  | Q    | 64K  | no   | no    | std  | opt  | no   | no   |
| 11/04  | U    | 64K  | no   | no    | no   | no   | no   | no   |
| 11/05  | U    | 64K  | no   | no    | no   | no   | no   | no   |
| 11/20  | U    | 64K  | no   | no    | no   | no   | no   | no   |
| 11/23  | Q    | 4M   | std  | no    | std  | no   | opt  | opt  |
| 11/23+ | Q    | 4M   | std  | no    | std  | no   | opt  | opt  |
| 11/24  | U    | 4M   | std  | std   | std  | no   | opt  | opt  |
| 11/34  | U    | 256K | std  | no    | std  | no   | opt  | no   |
| 11/40  | U    | 256K | std  | no    | std  | opt  | no   | no   |
| 11/44  | U    | 4M   | std  | std   | std  | no   | opt  | opt  |
| 11/45  | U    | 256K | std  | no    | std  | no   | opt  | no   |
| 11/53  | Q    | 4M   | std  | no    | std  | no   | std  | opt  |
| 11/60  | U    | 256K | std  | no    | std  | no   | std  | no   |
| 11/70  | U    | 4M   | std  | std   | std  | no   | opt  | no   |
| 11/73  | Q    |      | std  | no    |      |      |      |      |
| 11/73B | Q    | 4M   | std  | no    | std  | no   | std  | opt  |
| 11/83  | Q    | 4M   | std  | no    | std  | no   | std  | opt  |
| 11/84  | U    | 4M   | std  | std   | std  | no   | std  | opt  |
| 11/93  | Q    | 4M   | std  | no    | std  | no   | std  | opt  |
| 11/94  | U    | 4M   | std  | std   | std  | no   | std  | opt  |

如果某个**功能**是标准的，则无法**禁用**它；如果**某个功能未包含在内**，则**不能启用**它。

**CPU**实现了一个**SHOW命令**来展示**I/O地址分配**:

**SHOW CPU IOSPACE**     					**显示I/O空间地址分配**

























