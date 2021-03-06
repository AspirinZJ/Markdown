# 方法1

**1、查看Linux硬盘信息：**

```bash
$ sudo fdisk -l 
```

**2、格式化硬盘（根据需要确定文件系统）：**

```bash
sudo mkfs.xfs /dev/sdb
```

**3、创建/data目录**

```bash
sudo mkdir /data
```

**4、挂载分区：**

```bash
sudo mount /dev/sdb /data
```

**5、查看磁盘分区的UUID**

```bash
$ sudo blkid
/dev/sda1: UUID="8048997a-16c9-447b-a209-82e4d380326e" TYPE="ext4"
/dev/sda5: UUID="0c5f073a-ad3f-414f-85c2-4af83f6a437f" TYPE="swap"
/dev/sdb1: UUID="11263962-9715-473f-9421-0b604e895aaa" TYPE="ext4"
/dev/sr0: LABEL="Join Me" TYPE="iso9660" 
```

 

**6、配置开机自动挂载：**

mount命令重启后会失效，将分区信息写入 /etc/fstab 文件启动自动挂载：

```bash
sudo vim /etc/fstab
```

加入：

```bash
UUID=11263962-9715-473f-9421-0b604e895aaa /data xfs defaults 0 1
```

注：`<fs spec> <fs file> <fs vfstype> <fs mntops> <fs freq> <fs passno>`

具体说明，以挂载/dev/sdb1为例：

```bash
<fs spec>：分区定位，可以给UUID或LABEL，例如：UUID=6E9ADAC29ADA85CD或LABEL=software
<fs file>：具体挂载点的位置，例如：/data<fs vfstype>：挂载磁盘类型,linux 分区一般为 ext4，windows 分区一般为 ntfs
<fs mntops>：挂载参数，一般为defaults
<fs freq>：磁盘检查，默认为0
<fs passno>：磁盘检查，默认为0，不需要检查

第一个叫fs_freq,用来决定哪一个文件系统需要执行dump操作，0就是不需要；
第二个叫fs_passno,是系统重启时fsck程序检测磁盘的顺序号 1 是root文件系统，2 是别的文件系统。fsck按序号检测磁盘，0表示该文件系统不被检测 dump 执行ext2的文件系统的备份操作 fsck 检测和修复文件系统
```

 

**7、重启系统**

修改完/etc/fstab文件后，运行

```bash
sudo mount -a
```

验证配置是否正确，配置不正确可能会导致系统无法正常启动。



---

# 方法2

- 先取消挂载盘（先退出硬盘挂载目录）

```shell
$ sudo umount /dev/sdb2
```

- 格式化

```shell
$ sudo mkfs -t ext4 /dev/sdb2
```

- 挂载

```shell
$ sudo mount /dev/sdb2 /home/username/YourMountPath
```

- 更改开机自动挂载配置

```shell
$ sudo gedit /etc/fstab
```

按照下面格式添加内容：(ntfs同理）

> /dev/sdb2 /home/username/YourMountPath ext4 defaults 0 0