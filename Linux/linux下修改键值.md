# 第一种方式

前言： linux 下键盘 有3层 scancode，keycode，symbol  随便修改那一层都可以，我们现在是通过修改symbol的方式来修改的；

## 第一步 查看键值

查看的方法1：可以通过xev | grep keycode（如果没有xev功能的话，可以网上下载一个，运行install.sh即可）

然后点击键盘，就可以得到对应按键的键值，比如

```
state 0x0, keycode 108 (keysym 0xff1b, Escape), same_screen YES,
  XKeysymToKeycode returns keycode: 9
  state 0x8, keycode 108 (keysym 0xff1b, Escape), same_screen YES,
  XKeysymToKeycode returns keycode: 9
  state 0x0, keycode 9 (keysym 0xff1b, Escape), same_screen YES,
  state 0x0, keycode 9 (keysym 0xff1b, Escape), same_screen YES,
```



查看的方法2：另外一种简便的方法查看键值可以查看：/usr/include/X11/keysymdef.h ，里面包含所有的符号名，在其中可以找到你想要的键名，里面也有些简短的注释。

查看的方法3：通过xmodmap -pk  来显示整个键盘的布局，我的电脑如下：

第一列是keycode  第二列表示keysym对应的值，第三列表示按下shift对应的内容；


## 第二步 把需要修改的键值改成你需要设置的键值，

得到键值之后，就在 “~” 目录下创建 .xmodmaprc文件，内容如下

keycode 10= 0x32 0x40 

保存之后，在终端输入

xmodmap ~/.xmodmaprc  

然后1键就变成2键了 同时！也会变成@  ^_^  

其实，你不用每次都运行

xmodmap ~/.xmodmaprc

这个命令，可 以把上面的命令做成一个脚本程序，例如：在 /usr/bin/ 目录下创建 key文件，内容如下

```bash
1. \#!/bin/sh 
2. xmodmap ~/.xmodmaprc 
```

保存后添加执行权限  `chmod +x /usr/bin/key`

然后把key程序添加到系统自动启动的程序里面就大功告成了！！！



注意：对于一些修饰符的键值设置比较麻烦  

直接输入 xmodmap, 不带参数, 输出结果是你当前键盘的一些修饰键的信息
比如我的机器上的输出是这样的:
xmodmap: up to 4 keys per modifier, (keycodes in parentheses):

shift    Shift_L (0x32), Shift_R (0x3e)
lock    Caps_Lock (0x42)
control   Control_L (0x25), Control_R (0x69)
mod1    Alt_L (0x40), Alt_R (0x6c), Meta_L (0xcd)
mod2    Num_Lock (0x4d)
mod3   
mod4    Super_L (0x85), Super_R (0x86), Super_L (0xce), Hyper_L (0xcf)
mod5    ISO_Level3_Shift (0x5c), Mode_switch (0xcb)



把键码(keycode) 事件 转换为 keysym.这是第一层
然后 再参考 修饰 映射 modifier,来确定按下ctrl shift 之类按键后的反应
所以以上表第二行的内容为例.它表示的是大小写切换键Capslock
lock    Caps_Lock (0x42)
括号里的0x42 从十六进制转换到 十进制 就是 66 , 也就是 CapsLock 这个按键对应keycode 66
按下Capslock 后, 系统接受到 keycode 66 , 系统转换为 Caps_Lock 这个keysym.
然后按照 modifier 映射表 把 Caps_Lock 转换为 lock 功能, 就是大小写转换.
 layer1       layer2    layer3
keycode      keysym     modifier
 keycode 66 ----> Caps_Lock ----> lock
所以,要修改键位, 就要把这两层映射关系都要改掉. 但是修改之前,要知道被修改按键现有的对应关系.
可以使用 "xmodmap -pke " 来输出现在所有keycode -> keysym 的映射.

首先从修改 keycod -> keysym 入手.
比如 我的需求1:调换esc 和 ~
这两个键都不在modifier 里面, 所以直接调换一下这两个按键的keycode 和keysym 就可以了,
在你的.Xmodmap 文件里面写入

! first , exchange (1) esc (2) grave ,"~",
! keycode  9 = Escape NoSymbol Escape
! keycode 49 = grave asciitilde grave asciitilde


keycode 49 = Escape NoSymbol Escape
keycode 9 = grave asciitilde grave asciitilde

注: 感叹号! 在配置文件中是被当成注释,不运行的.

涉及到modifier的按键修改就麻烦一点了, 要用 add remove 来修改 modifier 映射
比如把 casplock 改成 delete. 我们要做的事情就要分成两步.
既要把 capslock 的keysym 改成 delete 的keysym , 又要把capslock 从 modifier中的lock 组里移除.
否则你直接运行
"xmodmap -e "keycode 66 = BackSpace BackSpace BackSpace BackSpace ""
你会发现, capslock 键已经可以当backspace 来删除之前的字符了.但同时, 它还起着 原来的Capslock的大小写切换功能,
再用"xmodmap"查看一下
shift    Shift_L (0x32), Shift_R (0x3e)
lock    BackSpace (0x42)
control   Control_L (0x25), Control_R (0x69)
mod1    Alt_L (0x40), Alt_R (0x6c), Meta_L (0xcd)
mod2    Num_Lock (0x4d)
mod3   
mod4    Super_L (0x85), Super_R (0x86), Super_L (0xce), Hyper_L (0xcf)
mod5    ISO_Level3_Shift (0x5c), Mode_switch (0xcb)

你看.
lock    BackSpace (0x42)
 这个 keycode 66 的按键虽然keysym 已经改写成 backspace 了, 但是它依然表示一个大小写切换的功能.
所以先把CapsLock 从 lock 中移除, 然后再修改keysym

remove lock = Caps_Lock
keycode 66 = BackSpace BackSpace BackSpace BackSpace

这样键盘上的那个capslock 按键就完全改成backspace 了.
remove lock = Caps_Lock 这一句表示从 lock 组里移除Caps_Lock 这个keysym.
同样添加一个keysym 也是类似的语法 : add lock = Caps_Lock

---

# 第二种方式

在终端输入

xev | grep keycode

然后点击键盘，就可以得到对应按键的键值

比如

state 0x0, keycode 108 (keysym 0xff1b, Escape), same_screen YES,
  XKeysymToKeycode returns keycode: 9
  state 0x8, keycode 108 (keysym 0xff1b, Escape), same_screen YES,
  XKeysymToKeycode returns keycode: 9
  state 0x0, keycode 9 (keysym 0xff1b, Escape), same_screen YES,
  state 0x0, keycode 9 (keysym 0xff1b, Escape), same_screen YES,

这里，我为了方便，已经将Alt_R (键值108) 修改为了Escape 键，这完全是为了使用VI时更方便！

得到键值之后，就在 “~” 目录下创建 .xmodmaprc 文件，内容如下

keycode 108 = Escape

保存之后，在终端输入

xmodmap ~/.xmodmaprc

然后Alt_R 键就变成Escape键了！^_^

其实，你不用每次都运行

xmodmap ~/.xmodmaprc

这个命令，可 以把上面的命令做成一个脚本程序，例如：在 /usr/bin/ 目录下创建 key文件，内容如下

```php
#!/bin/sh
xmodmap ~/.xmodmaprc
```

保存后添加执行权限  chmod +x /usr/bin/key

然后把key程序添加到系统自动启动的程序里面就大功告成了！！！



# 第三种方式

使用xmodmap工具进行修改，使用man xmodmap，里面就有交换按键caplock（大小写切换键）和右ctrl键的例子，

如果您的修改不同，可以做相应的替换即可。我就是参考这个例子对我的右Alt键和Ctrl键进行修改的。

下面先看man自带的例子

​    ! 
​    ! Swap Caps_Lock and Control_L
​    !
​    remove Lock = Caps_Lock
​    remove Control = Control_L
​    keysym Control_L = Caps_Lock
​    keysym Caps_Lock = Control_L
​    add Lock = Caps_Lock
​    add Control = Control_L

将上面的语句写入文件，例如keymaprc，然后xmodmap keymaprc即可生效，

因为这个是交换键的功能，如果您执行第二次的话，按键就又会恢复回来的。

注意：这个修改只对当前有效，电脑重启会失效，得重新输入命令。



下面是我自己的修改，把keymaprc命名为隐藏文件: .keymaprc，放在$HOME目录下。

$ cat ~/.keymaprc 
remove Control = Control_R
remove mod1 = Alt_R
keysym Control_R = Alt_R
keysym Alt_R = Control_R
add Control = Control_R
add mod1 = Alt_R

然后执行 $ xmodmap ~/.keymaprc

这样就生效了



为了更加修改按键，不想很次都输入xmodmap ~/.keymaprc这么长的命令，可以将命令写入文本，放到$PATH路径下，下面是我的做法

$ touch swkey

$ echo "xmodmap ~/.keymaprc" >  swkey

$ chmod +x swkey

$ sudo mv swkey /usr/bin

$ swkey  #现在想交换两个按键就直接输入这个命令,无论在什么路径下都可以，也不用记文件路径，会比较方便



备注：

alt对就MODIFIERNAME为mod1，可以在man文档中找到其他的MODIFIERNAME，也可以直接xmodmap查看，window键应该对应mod4

$ xmodmap 
xmodmap:  up to 4 keys per modifier, (keycodes in parentheses):


shift    Shift_L (0x32),  Shift_R (0x3e)
lock     Caps_Lock (0x42)
control   Control_L (0x25),  Control_R (0x69)
mod1     Alt_L (0x40),  Alt_R (0x6c),  Meta_L (0xcd)
mod2     Num_Lock (0x4d)
mod3    
mod4     Super_L (0x85),  Super_R (0x86),  Super_L (0xce),  Hyper_L (0xcf)
mod5     ISO_Level3_Shift (0x5c),  Mode_switch (0xcb)