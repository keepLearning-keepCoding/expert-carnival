### 原文链接：http://gunkies.org/wiki/Installing_Unix_v6_(PDP-11)_on_SIMH

### 						在SIMH上安装Unix v6 (PDP-11)

​		我将要尝试描述[蒂姆·纽斯海姆](http://mailman.trailing-edge.com/pipermail/simh/2010-October/006009.html)所使用的在[PDP-11/40](http://gunkies.org/wiki/PDP-11/40)上安装[Unix v6](http://gunkies.org/wiki/Unix_System_6)的步骤。

## 内容

##### 1.[资料](#material)

##### 2.[磁带引导](#disk_booting)

##### 3.[磁盘安装](#disk_install)

##### 	3.1[引导到单用户模式](#boot_to_single_user_mode)

##### 	3.2 [修复终端](#repairing_terminal)

##### 	3.3 [重新构建内核](#rebuild_kernel)

##### 	3.4 [构建设备文件](#build_device_file)

##### 	3.5 [恢复OS的其余部分](#restore_other_part_of_os)

##### 	3.6 [配置引导](#configuring_boot)

##### 	3.7 [重新构建df命令](#rebuild_df_cmd)

##### 	3.8 [检查文件系统](#ck_file_sys)

##### 	3.9 [启用多用户](#multi-user)

##### 	3.10 [重引导](#reboot)

##### 4.[正常运行](#running_normally)

### <span id="material">资料</span>

​		我期待你使用3.8-1或更高版本的[SIMH](http://gunkies.org/wiki/SIMH)模拟器，和一个Unix v6 磁带 [Unix-v6-Ken-Wellsch.tap](http://sourceforge.net/projects/bsd42/files/Install tapes/Research Unix/Unix-v6-Ken-Wellsch.tap.bz2/download)。

### <span id="disk_booting">磁带引导</span>

​		这里我们加载引导块，并把根分区加载到rk磁盘文件中。

​		首先运行tboot.ini文件。在最近的simh构建中，移除分号及其后的注释。

```
set cpu 11/40					; 设置CPU类型为11/40
set tm0 locked				; 把TM11/TU10磁带控制器的第0个驱动设置为写锁定
attach tm0 dist.tap		; 把单元tm0和文件dist.tap联系起来
attach rk0 rk0				; 新建文件rk0,并将其与单元rk0联系起来  rk为RK11/RK05盒式磁盘控制器
attach rk1 rk1
attach rk2 rk2
d cpu 100000 012700        ; mov #172526,R0
d cpu 100002 172526
d cpu 100004 010040        ; mov R0,-(R0)
d cpu 100006 012740        ; mov #60003,-(R0)
d cpu 100010 060003
d cpu 100012 000777        ; br 100012
g 100000
```

一旦运行完这个文件，模拟将会”锁定“，按下CTRL+E中断模拟程序，然后执行这个单机程序，为硬盘做好准备。输入：

```
g 0
```

此时单机程序将准备好应答。以下是我的安装会话:

```
PDP-11 simulator V3.8-1
sim> set cpu 11/40
Disabling XQ
sim> set tm0 locked
sim> attach tm0 dist.tap
sim> attach rk0 rk0
RK: creating new file
sim> attach rk1 rk1
RK: creating new file
sim> attach rk2 rk2
RK: creating new file
sim> d cpu 100000 012700
sim> d cpu 100002 172526
sim> d cpu 100004 010040
sim> d cpu 100006 012740
sim> d cpu 100010 060003
sim> d cpu 100012 000777
sim> g 100000

Simulation stopped, PC: 100012 (BR 100012)
sim> g 0
=tmrk
disk offset
0
tape offset
100
count
1
=tmrk
disk offset
1
tape offset
101
count
3999
=                                              [## Hit CTRL-E here]
Simulation stopped, PC: 137300 (BGE 137274)
sim> q
Goodbye
```

### <span id="disk_install">磁盘安装</span>

这是我的dboot.ini，它用于从硬盘引导：

```
set cpu 11/40
set tto 7b						; 设置DL11 控制台终端
set tm0 locked				; 写锁定TM11/TU10磁带控制器的第0个驱动
attach tm0 dist.tap		; 把dist.tap附接到tm0上
attach rk0 rk0			
attach rk1 rk1
attach rk2 rk2
dep system sr 173030	; sr 开关寄存器
boot rk0							; 重置所有设备，引导盒式磁盘控制器0.
```

#### <span id="boot_to_single_user_mode">引导到单用户模式</span>

​		这将我们引导至引导装载程序，它是"unix"要加载到的地方。

```
PDP-11 simulator V3.8-1
sim> set cpu 11/40
Disabling XQ
sim> set tto 7b								; tto:控制台终端
sim> set tm0 locked						; 锁定TM11/TU10磁带控制器的第0个驱动
sim> attach tm0 dist.tap			; 把dist.tap附加到TM11/TU10磁带控制器的第0个驱动
sim> attach rk0 rk0						; 把文件rk0附加到RK11/RK05盒式磁盘控制器的第0个驱动
sim> attach rk1 rk1
sim> attach rk2 rk2
sim> dep system sr 173030     ; sr:系统开关寄存器   保存173030至sr
sim> boot rk0									; 重置所有设备，引导RK11/RK05盒式磁盘控制器的第0个驱动
@rkunix
mem = 1030
RESTRICTED RIGHTS

Use, duplication or disclosure is subject to
restrictions stated in Contract with Western
Electric Company, Inc.
#
```

#### <span id="repairing_terminal">修复终端</span>

​		对于已加载的UNIX，我们要做的第一件事情是把终端设置回小写。用小写模式输入以下命令，控制台将回显大写，但这只是它工作的方式。

```
# STTY -LCASE
```

#### <span id="rebuild_kernel">重新构建内核</span>

我们将重新构建内核，以支持适应SIMH所提供的硬件。首先，我们必须构建mkconf程序:

```
chdir /usr/sys/conf
cc mkconf.c
mv a.out mkconf
```

当mkconf程序构建完成后，我们就可以为其提供一个基本的配置文件了。要实现这一点，我们只需运行mkconf，然后输入我们想要的设备列表。

```
rk
tm
tc
8dc
lp
done
```

然后，你将看到如下显示：

```
# ./mkconf
rk
tm
tc
8dc
lp
done
#
```

现在，我们可以编译配置文件，并将其链接到内核的其余部分，然后将结果复制到根目录。

```
as m40.s
mv a.out m40.o
cc -c c.c
as l.s
ld -x a.out m40.o c.o ../lib1 ../lib2
mv a.out /unix
```

并验证下，我们的内核大小应该为30kb。

```
# ls -l /unix
-rwxrwxrwx  1 root    30346 Oct 10 12:43 /unix
```

### <span id="build_device_file">构建设备文件</span>

现在，我们即将构建设备文件。只用把以下代码复制粘贴即可。

```
/etc/mknod /dev/rk0 b 0 0
/etc/mknod /dev/rk1 b 0 1
/etc/mknod /dev/rk2 b 0 2
/etc/mknod /dev/mt0 b 3 0
/etc/mknod /dev/tap0 b 4 0
/etc/mknod /dev/rrk0 c 9 0
/etc/mknod /dev/rrk1 c 9 1
/etc/mknod /dev/rrk2 c 9 2
/etc/mknod /dev/rmt0 c 12 0
/etc/mknod /dev/lp0 c 2 0
/etc/mknod /dev/tty0 c 3 0
/etc/mknod /dev/tty1 c 3 1
/etc/mknod /dev/tty2 c 3 2
/etc/mknod /dev/tty3 c 3 3
/etc/mknod /dev/tty4 c 3 4
/etc/mknod /dev/tty5 c 3 5
/etc/mknod /dev/tty6 c 3 6
/etc/mknod /dev/tty7 c 3 7
chmod 640 /dev/*rk*
chmod 640 /dev/*mt*
chmod 640 /dev/*tap*
```

### <span id="restore_other_part_of_os">恢复OS的其余部分</span>

```
dd if=/dev/mt0 of=/dev/rk1 count=4000 skip=4100
/etc/mount /dev/rk1 /usr/source
dd if=/dev/mt0 of=/dev/rk2 count=4000 skip=8100
mkdir /usr/doc
```

### <span id="configuring_boot">配置引导</span>

我只使用cat附加了其他磁盘的引导语句。

```
/etc/mount /dev/rk1 /usr/source
/etc/mount /dev/rk2 /usr/doc
```

而且我像下面这样附加了这些语句:

```
# cat >> /etc/rc
/etc/mount /dev/rk1 /usr/source
/etc/mount /dev/rk2 /usr/doc
```

然后点击 CTRL+D

### <span id="rebuild_df_cmd">重新构建df命令</span>

要配置df,请执行以下操作:

```
# chdir /usr/source/s1
# ed df.c
/rp0/d
.-2a
  "/dev/rk0",
  "/dev/rk1",
.
w
q
# cc -s -O df.c
# cp a.out /bin/df
# rm a.out
```

### <span id="ck_file_sys">检查文件系统</span>

那时候fsck不存在...所以我们运行 icheck/dcheck:

```
icheck /dev/rrk0
dcheck /dev/rrk0
icheck /dev/rrk1
dcheck /dev/rrk1
icheck /dev/rrk2
dcheck /dev/rrk2
```

### <span id="multi-user">启用多用户</span>

默认的/etc/ttys文件并未监听串口，所以我们仅仅通过编辑文件来改变它。

```
# ed /etc/ttys
1,8s/^0/1/p
w
q
# 
```

### <span id="reboot">重引导</span>

并不存在重引导命令，所以运行几次sync命令，然后点击 Control+E中断并退出模拟器。

```
# sync
# sync
# sync
# sync
#                               [## Hit CTRL-E here]
Simulation stopped, PC: 002502 (MOV (SP)+,177776)
sim> q
Goodbye

C:\temp\v6\myv6>
```

### <span id="running_normally">正常运行</span>

当所有的安装完成时，使用以下的ini文件来进行正常操作。

```
set cpu 11/40
set cpu idle
set tto 7b
set tm0 locked
attach rk0 rk0
attach rk1 rk1
attach rk2 rk2
attach lpt printer.txt
set dci en
set dci lines=8
set dco 7b
att dci 5555
boot rk0
```

当我们启动模拟器后，即可附接到tcp端口5555，以供其他用户使用。要引导UNIX，只需把名字unix传递给引导装载程序。

```
PDP-11 simulator V3.8-1
Disabling XQ
Listening on port 5555 (socket 108)
@unix

login: root
#
```

**值得注意的是没有根用户密码。**















