一、更改GRUB引导菜单背景图片
1、首先准备一张想要的照片，文件名是啥无所谓，只要格式是*.jpg *.JPG *.jpeg *.JPEG *.png *.PNG *.tga *.TGA都行，都能自动找到，如果有多个，那么显示第一个找到的图片。
例如名字为命名为：xihuan.jpg

复制到grub目录 /boot/grub/
---------------------------------------------
root@ubuntu:~# cp -v xihuan.jpg  /boot/grub/
---------------------------------------------
2、改变一下启动界面的分辨率
-----------------------------------------------------------------
root@ubuntu:~# vi /etc/default/grub

找到#GRUB_GFXMODE=640x480
更改为 GRUB_GFXMODE=1920x1080     #这里的分辨率改成自己电脑的分辨率
-----------------------------------------------------------------
3、重新生成GRUB的启动菜单配置文件(/boot/grub/grub.cfg)
---------------------------------
root@ubuntu:~# update-grub
---------------------------------
通过上面的配置，现在你就可以拥有自己想要的开机界面了。

二、更改GRUB引导菜单默认启动项

更改启动顺序，验证过的两种方式

1、修改 /etc/default/grub 文件

root@ubuntu:~# vi  /etc/default/grub

找到GRUB_DEFAULT=0     #更改数字设置默认启动项，想要改为第N项默认就把0改成N-1看到启动界面是第几项N就是几，将数字减去1

GRUB_TIMEOUT=10 选项是设定菜单等待时间，默认为10秒，设置为-1取消倒计时，这个选项也可以一起更改。


2、重新生成GRUB的启动菜单配置文件(/boot/grub/grub.cfg),如果上面的一起配置，执行一次就可以。

---------------------------------------
root@ubuntu:~# update-grub
---------------------------------------
