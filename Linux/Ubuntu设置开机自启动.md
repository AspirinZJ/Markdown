# Ubuntu设置开机自启动

## 1 修改/etc/rc.local

rc.local脚本是一个ubuntu开机后会自动执行的脚本（重启后），我们可以在该脚本内添加命令行指令

![img](https://img-blog.csdnimg.cn/20190212192045144.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM1NzIwMzA3,size_16,color_FFFFFF,t_70)

在exit 0前添加命令即可

 

## 2 新建脚本，将脚本添加到启动脚本（推荐，可控，而且非常清楚）

### 2.1 在/etc/init.d/ 下新建脚本xxx 或者 xxx.sh 

```
#!/bin/bash
# command content
# Your Command
exit 0
```

### 2.2 设置文件权限

```bash
chmod 755 xxx
```

### 2.3 将脚本添加到启动脚本

```bash
update-rc.d xxx defaults 90
```

（移除开机脚本：update-rc.d -f xxx remove）

 

## 3 适用于Ubuntu 和 Centos 

参考：https://blog.csdn.net/qq_35720307/article/details/87644054

在**/etc/init.d**编写脚本命令后，比如命名为**test**，然后直接运行 **systemctl enable test 或 systemctl enable test.service**

 

## 4 查看开机启动项

```bash
systemd-analyze blame
```

![img](https://img-blog.csdnimg.cn/20190213123241605.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM1NzIwMzA3,size_16,color_FFFFFF,t_70)