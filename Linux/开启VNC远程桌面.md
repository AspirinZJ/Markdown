1. 安装VNC server， 安装tightvnc或者vnc4server都可以

```bash
sudo apt install tightvncserver
or
sudo apt install vnc4server
```

运行一次vnc server

```bash
vncserver
```

你将会被要求输入vnc的密码

2. 配置vnc server

因为vnc默认开启：1号显示，端口为5901,先杀死当前正在运行的vnc server：

```bash
vncserver -kill :1
```

配置文件在`~/.vnc/xstartup`，修改这个配置文件：

```bash
mv ~/.vnc/xstartup ~/.vnc/xstartup.bak
```

```bash
vim ~/.vnc/xstartup
```

输入以下内容

```bash
#!/bin/bash
xrdb $HOME/.Xresources
startxfce4 &
```

给上面的文件添加执行权限：

```bash
chmod +x ~/.vnc/xstartup
```

重启vncserver，可以自定义分辨率

```bash
vncserver -geometry 1366x768
```

这样远程就能通过`ip_address:5901`远程连接vnc了。

3. 让vnc server作为系统的service启动

创建一个名为`/etc/systemd/system/vncserver@.service`的文件，`@`表示可以在后面传入参数，我们用它传入显示port：

```bash
sudo touch /etc/systemd/system/vncserver@.service
```

在上面的文件中输入以下内容，不要忘了替换**User**, **Group**, **WorkingDirectory**, 和**PIDFILE**里面的username

```json
[Unit]
Description=Start TightVNC server at startup
After=syslog.target network.target

[Service]
Type=forking
User=sammy
Group=sammy
WorkingDirectory=/home/sammy

PIDFile=/home/sammy/.vnc/%H:%i.pid
ExecStartPre=-/usr/bin/vncserver -kill :%i > /dev/null 2>&1
ExecStart=/usr/bin/vncserver -depth 24 -geometry 1280x800 :%i
ExecStop=/usr/bin/vncserver -kill :%i

[Install]
WantedBy=multi-user.target
```

`ExecStartPre`作用是当vnc正在运行时停止它，`ExeStart`作用是运行vnc，后面的颜色深度和分辨率都能调。

接下来让系统意识到有新的配置文件：

```bash
sudo systemctl daemon-reload
```

然后enable这个service

```bash
sudo systemctl enable vncserver@1.service
```

@后面的1表示显示为：1

重启之后就能自动开启vnc了。

---

## 解决vnc远程登录xfce花屏的问题

修改配置文件：

```bash
vim ~/.vnc/xstartup
```

修改为以下内容：

```bash
#!/bin/bash
unset SESSION_MANAGER
unset DBUS_SESSION_BUS_ADDRESS
startxfce4 &
```

保存，重启



## 远程桌面的软件

远程桌面软件建议使用Remmina：

```bash
sudo apt install remmina remmina-plugin-rdp
```

支持rdp， ssh和vnc