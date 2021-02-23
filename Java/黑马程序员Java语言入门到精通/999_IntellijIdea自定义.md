# 快捷键

| 快捷键                        | 功能                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| Alt+/                         | 显示自动补全提示                                             |
| Ctrl+Alt+L / Ctrl+Shift+Alt+L | 格式化代码                                                   |
| Alt+Shift+上下箭头            | 移动当前行                                                   |
| Alt+G                         | 自动生成代码， toString， get， set等方法                    |
| Alt+Enter                     | 自动修正代码，导包，修正包等                                 |
| Alt+D                         | Duplicate line or selection                                  |
| Ctrl+Shift+Enter              | 自动补全结尾(又括号，结尾的分号等)                           |
| Alt+J                         | 自动代码生成模板                                             |
| Alt+E                         | 显示最近修改的文件，显示最近的文件                           |
| Alt+P                         | 显示参数信息                                                 |
| Alt+[                         | 用代码块(if else, while, try catch等)包裹选中代码            |
| Alt+Y                         | 删除行                                                       |
| Alt+W                         | 扩展选中，按一下选中当前word，再按选中当前行，再按选中当前block..., 按住Shift的话缩小选中 |
| Ctrl+Shift+U                  | 全体改变成小写或大写                                         |
| Alt+上下箭头                  | 在方法间跳转光标                                             |
| Alt+B                         | Go to declaration or usages                                  |
| Ctrl+F8                       | 设置调试断点                                                 |
|                               |                                                              |
| Alt+C（可以按多次）           | 查找类                                                       |
| Ctrl+Shift+N                  | 查找文件                                                     |
| 两下Shift                     | 万能查找                                                     |

# 对项目进行打包

1. 设置打包：File | Project Structure | Artifacts | + | JAR | From modules with dependencies | OK | OK 
2. 编译: Build | Build Artifacts | Build
3. 运行：进入jar文件夹， 在终端中`java -p <module名> 包名.类名`

# 设置鼠标悬浮提示

Settings中勾选`Show quick documentation on mouse move`

# 自动导包和删除未使用包

Settings | Editor | General | Auto Import | 勾选 `Add unambiguous imports on the fly`和`Optimize imports on the fly`

# 显示方法分隔符

Settings | Editor | General | Appereance | 勾选`Show Method separators`

# 设置多行打开的文件窗口标签

Settings | Editor | Editor Tabs | 取消勾选`Show tabs in one row`

# 设置自动编译

Settings | Build, Execution, Deployment | Compiler | 勾选`Build Project automatically`和`Compile independent modules in parallel`