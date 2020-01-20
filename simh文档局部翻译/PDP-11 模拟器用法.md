## 2     PDP-11 特性

​	PDP-11模拟器的配置如下:

#### 	  设备名称																模拟

​			CPU																			PDP-11 带有256KB内存的CPU

​			PTR,PTP																     PC11 纸带阅读器/打孔机

​			TTI，T为                                                                   DL11 控制终端

​			CR                                                                                 

### 2.1 CPU和系统

#### 2.1.1  CPU

**CPU选项**包括**CPU类型**，用于**特定类型**的**CPU指令集选项**，**主存**的大小。

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

**type	bus	mem	MMU?	Umap?	EIS?	FIS?	FPP?	CIS?**

 **11/03	 Q	64K	no	no	std	opt	no	no**

**11/04	 U	64K	no	no	no	no	no	no**

**11/05	 U	64K	no	no	no	no	no	no**

**11/20	 U	64K	no	no	no	no	no	no**

**11/23	 Q	4M	std	no	std	no	opt	opt**

**11/23+ Q	4M	std	no	std	no	opt	opt**

**11/24	 U	4M	std	std	std	no	opt	opt**

**11/34	 U	256K	std	no	std	no	opt	no**

**11/40	 U	256K	std	no	std	opt	no	no**

**11/44	 U	4M	std	std	std	no	opt	opt**

**11/45	 U	256K	std	no	std	no	opt	no**

**11/53	 Q	4M	std	no	std	no	std	opt**

**11/60	 U	256K	std	no	std	no	std	no**

**11/70	 U	4M	std	std	std	no	opt	no**

**11/73	 Q	4M	std	no	std	no	std	opt**

**11/73B Q	4M	std	no	std	no	std	opt**

**11/83	 Q	4M	std	no	std	no	std	opt**

**11/84	 U	4M	std	std	std	no	std	opt**

**11/93	 Q	4M	std	no	std	no	std	opt**

**11/94	 U	4M	std	std	std	no	std	opt**

如果某个**功能**是标准的，则无法**禁用**它；如果**某个功能未包含在内**，则**不能启用**它。

**CPU**实现了一个**SHOW命令**来展示**I/O地址赋值**:

**SHOW CPU IOSPACE**     **显示I/O空间地址赋值**

























