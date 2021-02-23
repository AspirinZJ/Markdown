## 1.下载Grub主题包

[点这里](https://www.gnome-look.org/browse/cat/109/order/latest)选择自己喜欢的主题包
我选了这个 Poly light的主题包
![这里写图片描述](更改grub主题/pics/20171224104049291)
点击下面的Files 之后在下面点击下载按钮

------

# 2.创建themes主题文件夹

在终端输入



```
sudo mkdir /boot/grub/themes1
```

------

## 3.解压下载的主题

在主题包所在目录下终端输入命令



```
sudo tar -xf 主题包名 1
```

------

![这里写图片描述](更改grub主题/pics/20171224104704157)
我的主题包名叫 “poly-light-master.zip”

## 4.移动主题包到themes路径下

在主题包目录下终端中输入命令



```
sudo cp 主题包名 /boot/grub/themes/1
```

------

## 5.修改配置文件并更新

1.修改配置文件



```
sudo gedit /etc/grub.d/00_header1
```

![这里写图片描述](更改grub主题/pics/20171224105923084)


2.在注释下添加



```
GRUB_THEME="/boot/grub/themes/主题包名/theme.txt"
GRUB_GFXMODE="1920x1080x32"12
```

![这里写图片描述](更改grub主题/pics/20171224105943268)


3.更新配置文件



```
sudo update-grub1
```