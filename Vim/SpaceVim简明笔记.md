# 安装SpaceVim

1. 安装SpaceVim

```bash
curl -sLf https://spacevim.org/install.sh | bash
vim
```

2. 卸载SpaceVim

```bash
curl -sLf https://spacevim.org/install.sh | bash -s -- --uninstall
```

# 基础内容

## Shortcuts

There are different kinds of shortcuts, start with different prefix:

| Prefix  | Prefix name | Example   | Description                     | More info                                                    |
| ------- | ----------- | --------- | ------------------------------- | ------------------------------------------------------------ |
| `space` | `[SPC]`     | `spc f t` | open/close filetree             | just press space key and wait 1s                             |
| `s`     | `[WIN]`     | `s v`     | split window, equal to `:split` | [link](https://spacevim.org/documentation/#window-manager)   |
| `\`     | `<Leader>`  | `\ [0-9]` | jump to other tab or buffer     | just press `\` key and wait 1s                               |
| `g`     | go to       | `g 0`     | go to first tab                 | [link](https://spacevim.org/documentation/#commands-starting-with-g) |
| `z`     | fold        | `z a`     | toggle a fold                   | [link](https://spacevim.org/documentation/#commands-starting-with-z) |

Just press the button `spc`, wait 1 second, you will see useful hint to shortcuts, explore by yourself.

## Key conceptions

| Name      | Description                                       |
| --------- | ------------------------------------------------- |
| Window    | A window can split into more windows              |
| Buffer    | A buffer is a file loaded into memory for editing |
| Tab/Frame | A tab could contain different file                |
| Tagbar    | Display tags of current file                      |
| Filetree  | File browser                                      |



## For old vimer

As you could see above, spacevim's shortcuts are confict with origin vim's shortcuts such as shortcuts start with `s` and `g`, if you want to use origin vim key bindings, you can enable vimcompatible mode, add below code to `~/.SpaceVim.d/init.toml`

```bash
[options]
  vimcompatible = true
```

For more infomation about vim compatible mode, see [vimCompatible mode](https://spacevim.org/documentation/#vim-compatible-mode) if you just want to disable specific shortcut.

Spacevim's default file tree plugin is `vimfiler`, for those who used to using `nerdtree` plugin to explore file, set

```bash
[options]
  filemanager = "nerdtree"
```

## The most frequently used shortcuts

Be carefully, if you use vim compatible mode, in vim normal mode, the following shortcuts starts with `s` and `q` won't work.

| Shortcuts        | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| Basic            |                                                              |
| `spc`            | wait 1 second to get hint for more shortcuts                 |
| `<F3> / spc f t` | trigger file tree                                            |
| `spc t t`        | Open tab manager                                             |
| `F2`             | Open tagbar                                                  |
| `<Leader> [1-9]` | switch to different tabs or buffers                          |
| `spc [1-9]`      | switch to different windows                                  |
| `ctrl j/h/k/l`   | switch to different windows                                  |
| Filetree         | [Link](https://spacevim.org/documentation/#file-tree)        |
| `spc f o`        | open file tree and locate to current directory               |
| `s g`            | open file and split window horizontally                      |
| `s v`            | open file split window vertically                            |
| Comment code     | [Link](https://spacevim.org/documentation/#commenting)       |
| `spc c l`        | comment/uncomment current line                               |
| `spc c p/P`      | comment/uncomment current paragraph                          |
| `spc ; [num] j`  | comment *num* lines                                          |
| Tab Manager      | [Link](https://spacevim.org/documentation/#tabline)          |
| `spc w F`        | open a new tab, equal to `spc t t + n`                       |
| `spc w o`        | switch tab                                                   |
| Display          | [Link](https://spacevim.org/documentation/#ui-toggles)       |
| `spc s c`        | clear search highlight                                       |
| `SPC t 8`        | highlight any character past the 80th column                 |
| `SPC t h h`      | toggle highlight of the current line                         |
| `SPC t h c`      | toggle highlight indentation current column                  |
| Search           | [Link](https://spacevim.org/documentation/#searching)        |
| `spc s s`        | Searching in current file                                    |
| `spc s d`        | Searching in current directory                               |
| `spc s b`        | Searching in all loaded buffers                              |
| `spc s p`        | Searching in current proj, equal to `spc /`                  |
| Useful shortcuts | [Link](https://spacevim.org/documentation/#unimpaired-bindings) |
| `[ spc`          | insert space above                                           |
| `] spc`          | insert space below                                           |

In the list above, I only listed shortcuts I use the most. The best way to explore shortcuts is just press the `Space bar` in the spacevim, wait a second, you will see a prompt window, try all kinds of shortcuts by yourself!







# 常用命令

U	=>撤销对当前行做的所有更改

0	=>硬行首

cw	=>更改当前单词从光标处到下个单词开始的内容(不仅删除了一个单词，也进入了插入模式)

ce	=>更改当前单词从光标处到当前单词尾部的内容(不仅删除了一个单词，也进入了插入模式)

c	=>更改指令，后面同样跟数字和motion，如c$更改光标到行尾处的内容，c2w更改两个单词

ctrl+g	=>显示当前行的信息

ctrl+o	=>光标跳回到上一次的位置

ctrl+i	=>光标跳出到下一次的位置

%	=>在一个[, (, 或{处按%会跳转到匹配的括号



:s/旧内容/新内容	=>会替换光标所在行的第一个匹配的旧内容为新内容

:s/旧内容/新内容/g	=>会替换光标所在行的所有匹配的旧内容为新内容

:行号1,行号2s/旧内容/新内容/g	=>会替换行号1和2之间匹配的旧内容为新内容

:%s/旧内容/新内容/g	=>替换整个文本中匹配的旧内容为新内容

:%s/旧内容/新内容/gc	=>会找到整个文本中匹配的字符串，并在替换之前提问是否替换

`:s/\<旧内容\>/新内容/g` =>使用 \< 来匹配单词的开头和 \> 以匹配结尾, 这样就是只匹配整个单词而不匹配出现的一部分



:!外部命令	=>执行外部命令， 如:!ls

:w 文件名	=>保存当前文件为文件名

v motion :w 文件名	=>先按v进入选择模式，选取内容之后按`:w 文件名`将选择的内容保存到文件名之中

:r filename	=>将filename文件中的内容插入到光标所在处

:r !外部命令	=>同样可以读取外部命令的输出并将之插入到光标所在处

R	=>替换模式，会一直替换知道按Esc

:set ic	=>ignore case，设置为忽略大小写

:set noic	=>设置为忽略忽略大小写，即大小写敏感

:set hls	=>设置查找的匹配内容为高亮显示, highlight search

:set is	=>查找短语时显示部分匹配incsearch

:nohlsearch 或者 :noh	=>取消查找的匹配内容高亮显示

/查找内容\c	=>仅在这次查找时忽略大小写

