# xubuntu主题修改启动背景

```bash
cd /usr/share/plymouth/themes/xubuntu-logo
```

查看当前的启动图片 wallpaper.png 和 logo.png
启动脚本为: xubuntu-logo.script

```bash
ls -l
```

> 方法一（推荐）： 只需替换 wallpaper.png 和 logo.png 就可以了 注：命名不能改变
> 方法二: 修改启动脚本xubuntu-logo.script中 wallpaper.png 和 logo.png 的对应的地方为需要启动的图片名