# GitHub 使用教程

## 安装git: 

```bash
sudo apt install git
```

## 设置用户名和邮箱

```bash
git config --global user.name '用户名'
git config --global user.email '邮箱'
```



## 初始化一个新的Git仓库

1. 创建文件夹

2. 在文件夹内初始化git（创建git仓库）

    ```bash
    cd 文件夹
    git init
    ```

3. .git 文件夹是仓库文件

## 向仓库中添加文件流程

![1563823809974](/home/jackzhang/.config/Typora/typora-user-images/1563823809974.png)

1. 创建文件

    ```bash
    touch testfile
    ```

2. 把文件提交到暂存区

    ```bash
    git add testfile
    ```

3. 把暂存区的文件添加到仓库

    ```bash
    git commit -m '描述'
    ```

## 修改仓库文件

1. 修改文件
2. 添加到暂存区
3. 把暂存区文件添加到仓库

## 删除仓库文件

1. 删除工作目录文件

2. 添加到暂存区

    ```bash
    git rm testfile
    ```

3. 提交操作

    ```bash
    git commit -m '描述'
    ```

## git克隆操作

```bash
git clone 仓库地址
```



## 将本地仓库同步到git远程仓库中

```bash
git push
```



## 常用命令

```bash
git status
git config
git config --list
```

---

# GitHub Pages 搭建网站

### 访问

https://用户名.github.io

## 搭建步骤

### 1. 创建个人站点，新建仓库（注：仓库名必须是[用户名.github.io]）

### 2. 在仓库下新建index.html的文件即可（github pages只支持静态网页）

---

# Project Pages 项目站点

https://用户名.github.io/仓库名

## 搭建步骤

1. 进入项目主页，点击settings
2. 在settings点击Change Theme, 来自动生成主题页面