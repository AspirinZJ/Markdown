## 前言

之前在做测试的时候提交了很多无用的记录，现在准备将这些无用的垃圾commit记录删除。

## 解决方法

具体步骤如下。

```shell
#Clone your git repo
git clone https://github.com/lestatzhang/lestatzhang.github.io.git;
#Entre your local repo
cd lestatzhang.github.io;
#Checkout
git checkout --orphan latest_branch;
#Add all the files
git add -A;
#Commit the changes
git commit -am "Reinitialize";
#Delete the branch
git branch -D master;
#Rename the current branch to master
git branch -m master;
#Finally, force update your repository
git push -f origin master;
```