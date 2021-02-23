## TRANSMISSION主要配置

| 选项                                                 | 解释                                                         |
| :--------------------------------------------------- | :----------------------------------------------------------- |
| "blocklist-enabled": false,                          | 是否启用黑名单，可以在web界面里修改                          |
| "blocklist-url": "http://www.example.com/blocklist", | 黑名单地址，可以在web界面里修改                              |
| "dht-enabled": true,                                 | 启动DHT，可以在web界面里修改                                 |
| "download-dir": "/PATH/TO/DIR",                      | 默认下载目录                                                 |
| "incomplete-dir": "/var/ftp/pub",                    | 未下载完成文件存放目录                                       |
| "incomplete-dir-enabled": false,                     | 是否启用未下载完成目录                                       |
| "lpd-enabled": false,                                | 本地节点发现，只有在内网里有多个BT服务器的情况下有用，可以在web界面里修改 |
| "peer-port": 51413,                                  | 传入端口号，注意检查这个端口有没有被阻塞，可以在web界面里修改 |
| "preallocation": 1,                                  | 预分配下载空间，防止下载到一半发现空间不足无法继续下载。     |
| "rename-partial-files": true,                        | 重命名未完成的文件，会在末尾加上.part                        |
| "rpc-authentication-required": true,                 | 启用远程控制，建议开启                                       |
| "rpc-bind-address": "0.0.0.0",                       | 远程控制地址，默认代表所有IP都可以进行控制                   |
| "rpc-enabled": true,                                 | 是否启用远程连接，建议开启                                   |
| "rpc-password": "PASSWORD",                          | 认证用户用的密码                                             |
| "rpc-port": 9091,                                    | web界面的端口                                                |
| "rpc-username": "USERNAME",                          | 认证用户用的用户名                                           |
| "rpc-whitelist": "127.0.0.1",                        | 允许远程连接的IP地址白名单，支持通配符，多个IP以逗号分隔     |
| "rpc-whitelist-enabled": false,                      | 是否启用远程连接白名单                                       |
| "script-torrent-done-enabled": false,                | 在torrent完成时运行脚本，默认关闭                            |
| "script-torrent-done-filename": "",                  | 脚本路径                                                     |
| "umask": 18,                                         | 下载文件的权限掩码，默认18下载后就是755权限。                |

## 配置TRANSMISSION

环境：

- CentOS7/RedHat7
  安装Transmission

```
[root@lynk ~]# yum install -y epel-release wget
[root@lynk ~]# yum install -y transmission transmission-daemon
```

安装web界面

```
[root@lynk ~]# wget https://github.com/ronggang/transmission-web-control/raw/master/release/install-tr-control-cn.sh
[root@lynk ~]# bash install-tr-control-cn.sh
```

配置Transmission

```
#关闭Transmission进程
[root@lynk ~]# systemctl stop transmission-daemon.service
#编辑配置文件
[root@lynk ~]# vim /var/lib/transmission/.config/transmission-daemon/settings.json
#修改如下内容
"rpc-host-whitelist-enabled": false,           #关闭ip白名单模式
"rpc-authentication-required": true,           #开启用户认证
"rpc-username": "你的用户名",                  #登录用的用户名
"rpc-password": "你的密码",                    #登录用的密码，在运行过一次之后会自动变成HASH码
"rpc-whitelist-enabled": false,                #关闭白名单模式
#启动Transmission进程
[root@lynk ~]# systemctl start transmission-daemon.service
```

在浏览器上尝试用 服务器ip:9091 进入Transmission界面验证安装

配置FTP匿名访问以方便下载，关于FTP的更多内容可以参考我的另一篇博客：
[FTP服务与配置](https://www.cnblogs.com/lynk/p/10396714.html)

```
[root@lynk ~]# yum -y install vsftpd
[root@lynk ~]# vim /etc/vsftpd/vsftpd.conf
1.修改 listen=YES #让FTP服务监听在ipv4
2.注释 listen_ipv6=YES #不允许在ipv6监听（ipv6和ipv4不能共存）
3.添加 anon_root=/var/lib/transmission/Downloads #把匿名用户的默认目录改到Transmission的默认下载目录。

[root@lynk ~]# chmod 755 /var/lib/transmission/Downloads

#启动ftp服务
[root@lynk ~]# systemctl restart vsftpd
```

如果觉得从服务器里下载文件太慢也过于消耗服务器流量，也可以通过脚本每次在Transmission下载完成后将下载的文件备份到OSS，
然后从OSS获取下载地址。
这种方式这里只提供一个思路吧：）