查找当前文件夹下（不包含子文件夹）文件名+内容中包含指定字符的文件

```bash
grep "查询内容" 要查询的目录 
```

查找当前文件夹下（包含子文件夹）文件名+内容中包含指定字符的文件

```bash
grep -r "查询内容" 要查询的目录 
eg：
grep -r "version.app.xinyartech.com"  /data/nginx/conf.d
```

根据时间查找日志
 `grep '2020-02-27 17:5[6,9]' xinyar-erp-auto.log`

查询指定时间段内的日志

` eg、grep -E '2020-02-27 14:5[5-9]|2020-02-28 15:0[0-5]' xinyar-erp-auto.log`

 查找关键字
` grep -C 10 'aaaa' nohup.out`



只显示包含内容的文件名

```bash
grep -r -l "查询内容"  文件目录
eg:
grep -r -l "version.app.xinyartech.com"  /data/nginx/conf.d
```



查找时不区分大小写：

```bash
grep –i "被查找的字符串" 文件名
```



查找匹配的行数：

```bash
grep -c "被查找的字符串" 文件名
```



从文件内容查找匹配指定字符串的行：

```bash
grep "被查找的字符串" 文件

例子：在当前目录里第一级文件夹中寻找包含指定字符串的.in文件
grep "thermcontact" \*/\*.in
```



文件名+内容  

```bash
find 文件目录  -type f |xargs grep "查询内容"; 
eg:
find /data/nginx/conf.d  -type f |xargs grep "version.app.xinyartech.com"; 
```



从根目录开始查找所有扩展名为.log的文本文件，并找出包含”ERROR”的行

```bash
find / -type f -name "\*.log" | xargs grep "ERROR"
例子：从当前目录开始查找所有扩展名为.in的文本文件，并找出包含”thermcontact”的行
find . -name "\*.in" | xargs grep "thermcontact"
```

