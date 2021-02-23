# ldd

* 功能： ldd可以列出一个程序所需要得动态链接库（so）

* 可以通过which找到ldd的位置 `which ldd`

* 在 ldd 命令打印的结果中，“=>”左边的表示该程序需要连接的共享库之 so 名称，右边表示由 Linux 的共享库系统找到的对应的共享库在文件系统中的具体位置。默认情况下， /etc/ld.so.conf 文件中包含有默认的共享库搜索路径

* 如果使用 ldd 命令时没有找到对应的共享库文件和其具体位置，可能是两种情况引起的：

  1. 共享库没有安装在该系统中；
  2. 共享库保存在 /etc/ld.so.conf 文件列出的搜索路径之外的位置。

* 通常情况下，许多开放源代码的程序或函数库都会默认将自己安装到 **/usr/loca**l 目录下的相应位置（如：/usr/local/bin 或 /usr/local/lib），以便与系统自身的程序或函数库相区别。而许多 Linux 系统的 /etc/ld.so.conf 文件中默认又不包含 /usr/local/lib。因此，往往会出现已经安装了共享库，但是却无法找到共享库的情况。具体解决办法如下：

  检查 **/etc/ld.so.conf** 文件，如果其中缺少 **/usr/local/lib** 目录，就添加进去；**注意：**在修改了 **/etc/ld.so.conf**文件或者在系统中安装了新的函数库之后，需要运行一个命令：**ldconfig ，**该命令用来刷新系统的共享库缓存，即 **/etc/ld.so.cache** 文件。为了减少共享库系统的库搜索时间，共享库系统维护了一个共享库 so 名称的缓存文件/etc/ld.so.cache。因此，在安装新的共享库之后，一定要运行 ldconfig 刷新该缓存。

* 缺少映射文件的可以用这个命令：

   `ln [参数][源文件或目录][目标文件或目录]`

  比如：

  `ln -s /usr/lib/i386-linux-gnu/libpangoxft-1.0.so.0.3800.1 /usr/lib/libpangoxft-1.0.so.0`

* ldd 后面可以跟grep来查找指定的库, 如`ldd ./run_video_slam | grep opencv_core`



# others

* `!$`表示上一次输入的最后一个参数

* 想要获取terminal的输入并使用，可以参考里例子

  * ```bash
    jackzhang@Deepin:~$ ls *.py
    kite_tutorial.py
    jackzhang@Deepin:~$ result=$(ls *.py)
    jackzhang@Deepin:~$ echo $result
    kite_tutorial.py
    jackzhang@Deepin:~$ code $result
    
    ```

  * 