下面这篇 Jupyter Notebook 入门指南由 Pranav Dar 撰写。当你读完这篇文章时，你将会了解，为什么你应该利用它来搭建你的机器学习项目，以及为什么 Jupyter Notebook 比这个领域的其他标准工具更好！



## 

**▌什么是 Jupyter Notebook？**



Jupyter Notebook 是一款开放源代码的 Web 应用程序，可让我们创建并共享代码和文档。



它提供了一个环境，你可以在其中记录代码，运行代码，查看结果，可视化数据并在查看输出结果。这些特性使其成为一款执行端到端数据科学工作流程的便捷工具 ，可以用于数据清理，统计建模，构建和训练机器学习模型，可视化数据以及许多其他用途。



当你还在构建项目原型时，Jupyter Notebooks 真的特别好用，因为你的代码是被写入独立的单元中并被单独执行的。这允许用户测试项目中的特定代码块，而无需从脚本的开始执行代码。许多其他的 IDE 环境（Integrated Development Environment， 集成开发环境）（如 RStudio ）也以其他几种方式做到这一点，但我发现 Jupyter 的单个单元结构是最好的。



正如你在本文中将会看到的，这些 Notebooks 是数据科学家手中非常灵活、可交互和强大的工具。他们甚至允许你运行除 Python 以外的其他语言，比如 R 、SQL 等。由于它们比 IDE 平台更具交互性，因此它们被广泛地应用于教学场景。



## 

**▌如何安装 Jupyter Notebook？**



首先你需要在机器上安装 Python，Python 2.7或Python 3.3（或更高版本）都可以。



**Anaconda**



新用户可以使用 Anaconda 发行版来同时安装 Python 和 Jupyter Notebooks。



Anaconda 安装了这两种工具，并包含了数据科学和机器学习社区中常用的很多软件包。你可以从这里下载最新版本的Anaconda 。



下载地址：https://jupyter.readthedocs.io/en/latest/install.html



**pip 安装方法**



如果出于某种原因，你决定不使用 Anaconda，那么你需要确保你的机器正在运行最新版本的 pip。 怎么做？如果你已经安装了 Python，那么 pip 已经安装好了。要升级到最新的版本，请参照下面的代码：



```

```

*#Linux and OSX*pip install -U pip setuptools*#Windows*python -m pip install -U pip setuptools



一旦 pip 安装完毕，你可以继续安装 Jupyter：



```

```

*#For Python2*
pip install jupyter
*#For Python3*
pip3 install jupyter



你可以在这里（地址：https://jupyter.readthedocs.io/en/latest/install.html）查看官方的 Jupyter 安装文档。



## 

**▌开始！**



现在我们已经了解了 Notebooks 是什么，以及如何在自己的机器上安装和设置 Notebooks。是时候开始动动手了！



要运行 Jupyter Notebooks，只需输入以下命令就可开始使用！



```

```

jupyter notebook



执行上面命令之后， Jupyter Notebook 将在你的默认浏览器中打开，网址为：http://localhost:8888/tree



在某些情况下，它可能无法自动打开。这种情况下，你的终端或者命令提示符中将会生成一个带有令牌密钥（ token key ）的网址。要打开 Notebook，你需要将整个 URL（包括令牌密钥）复制粘贴到浏览器中。



Notebook 打开后，你会在顶部看到三个选项卡：Files（文件），Running（运行）和 Clusters（集群）。Files 基本上列出了所有的文件，Running 显示你当前已经打开的终端和Notebooks，Clusters 由 IPython parallel 包提供，用于并行计算。



要打开一个新的 Jupyter Notebook，请单击页面右侧的“New”选项卡。在这里，你有四个选项可供选择：



⦁	Python 3

⦁	Text File (文本文件)

⦁	Folder (文件夹)

⦁	Terminal (终端)



在 "Text File" 选项中，你会得到一个空白的文档。输入你喜欢的任何字母，单词和数字。它基本上是一个文本编辑器（类似于 Ubuntu 上的应用程序）。你也可以选择一种语言（支持非常多的语言），然后用该语言来写一个脚本。你还可以查找和替换文件中的单词。



在 "Folder" 选项中， 顾名思义它的功能就是创建文件夹。你可以创建一个新文件夹来放入文件，重新命名或者删除它。



"Terminal" 的工作方式与你的 Mac 电脑或 Linux 电脑上的终端完全相同（或者 Windows 上的 cmd ）。它在你的Web浏览器中支持终端会话。在这个终端中输入 python ，瞧！现在你已经可以开始写 python 脚本了。



但在本文中，我们将重点介绍 Notebooks，因此我们将从“New”选项中选择 "Python 3" 选项。你会看到如下的截图：



![img](figures/20180529192359638)



然后，你可以导入最常见的 Python 库——pandas 和 numpy——来开始你的项目。代码上方的菜单栏提供了操作单元格的各种选项：insert (添加)，edit (编辑)，cut (剪切)，move cell up/down (上下移动单元格)，run cells(在单元格中运行代码)，interupt (停止代码)，save (保存工作)，以及 restart (重新启动内核)。

﻿

![img](figures/20180529192410909)



在下拉菜单中（如上所示），你有四个选项：



- Code - 这是你输入代码的地方
- Markdown - 这是你输入文本的地方。你可以在运行代码后添加结论，添加注释等。
- Raw NBConvert - 这是一个命令行工具，可将你的笔记本转换为另一种格式（如 HTML）
- Heading - 你可以将标题添加到单独的小节并使你的 Notebook 看起来干净整洁。这个选项现在已经集成到 Markdown 选项中。添加一个“##”，以确保在你之后输入的内容将被视为标题



## 

**▌使用 Magic Functions**



开发人员已经插入了预定义的 magic functions，使你的工作更方便和更具交互性。你可以运行以下命令来查看这些函数的列表（注意：通常不需要输入“％”，因为通常 Automagic 是默认打开的）：



```

```

%lsmagic



你会看到许多选项，你甚至可能认识其中的 ％clear， ％autosave， ％debug 和 ％mkdir 等函数。magic command 有两种运行方式：



- 逐行运行（ Line-wise ）
- 逐块运行（ Cell-wise ）



顾名思义， Line-wise 是当你想要执行一个单行命令的时候使用，而 Cell-wise 是你想要执行的命令不仅仅是一行，而是整个单元格中的整个代码块时使用。



在逐行运行模式中，所有给定的命令都必须以 ％ 字符开始，而在逐块运行模式下，所有命令都必须以 %% 开头。让我们看看下面的例子来更好的理解：



逐行模式：



```

```

%time a = range(10)



逐块模式：



```

```

%%timeit a = range (10)

```

```

min(a)



我建议你运行这些命令，看看其中的区别！



## 

**▌不仅限于 Python - 在 Notebooks 中使用 R，Julia 和JavaScript**



Notebooks 的魔术并不止于此。你甚至可以在 Notebooks 中使用其他语言，如 R，Julia，JavaScrip t等。我个人喜欢 R 中的 ggplot2 软件包，因此使用 Notebooks 来进行探索性数据分析非常方便。



要在 Jupyter 中启用 R，你需要 GitHub上提供的 IRKernel（ R 的专用内核）。这里有一份详细的指南（地址：https://discuss.analyticsvidhya.com/t/how-to-run-r-on-jupyter-ipython-notebooks/5512），总共需要八个步骤，还有截图来引导你一步一步进行操作。



如果你是 Julia 用户，你也可以在 Jupyter Notebooks 中使用它！查看这篇详尽的文章（地址：地址：https://discuss.analyticsvidhya.com/t/how-to-run-r-on-jupyter-ipython-notebooks/5512），它重点介绍了 Julia 用户如何学习数据科学，并包括了一章节介绍如何在 Jupyter 环境中使用 Julia。



如果你更喜欢使用 JavaScript，我推荐使用 IJavascript 内核。查看这个 GitHub 库（地址：https://github.com/n-riesco/ijavascript），它会引导你在不同操作系统上安装此内核。 请注意，你需要先安装 Node.js 和 npm 才能使用它。



## 

**▌Jupyter Notebooks 中的交互式命令板**



在开始添加小插件（widget）之前，你需要导入 widgets 包：



```

```

from ipywidgets import widgets



小插件的基本类型是典型的文本输入框和按钮。请参阅以下来自Dominodatalab 的示例，了解一下交互式小插件是怎么使用的：



![img](figures/20180529192433657)



你可以在这里（地址：https://blog.dominodatalab.com/interactive-dashboards-in-jupyter/）查看详尽的开发指南。



## 

**▌键盘快捷键——节省时间并提高效率！**



快捷键是 Jupyter Notebooks 最好用的功能之一。当你想运行任何代码块时，你只需要按下Ctrl + Enter 即可。Jupyter Notebooks 提供的键盘快捷键非常多，为我们节省了大量时间。



以下是我们挑选的一些快捷键，你在开始使用 Notebooks 时会经常用到这些快捷键。我强烈建议你阅读这些内容的时候一个一个地尝试一下这些快捷键。



Jupyter Notebook 提供了两种不同的键盘输入模式 - 命令和编辑。命令模式将键盘与 Notebook 命令绑定，并由具有蓝色左边距的带有灰色单元格边框来表示。编辑模式允许你将文本（或代码）输入活动单元格，并以绿色单元格边框表示。



**使用 Esc 和 Enter 在命令和编辑模式之间跳转。现在就试试吧！**



一旦进入命令模式（即没有活动单元格），就可以尝试以下快捷键：



- A 键将在选中单元格上方插入新单元格，B 键将在选中单元格下方插入一个单元格
- 要删除单元格，请连续按两次 D 键
- 要撤消已删除的单元格，请按 Z 键
- Y 键将当前的选中单元格变成代码单元格
- 按住 Shift + 向上或向下箭头键可以选择多个单元格。在多选模式下，按 Shift + M 会合并选中的单元格
- F 键会弹出 “查找和替换” 菜单



处于编辑模式时（在命令模式下按 Enter 键进入编辑模式），你会发现以下快捷键非常好用：



- Ctrl + Home 转到单元格的开头
- Ctrl + S 会保存你的工作
- 和上面提过的一样，Ctrl + Enter 将运行你的整个单元格
- Alt + Enter 不仅会运行你的单元格，它还会在下方添加一个新的单元格
- Ctrl + Shift + F 打开命令选项板



要查看整个键盘快捷键列表，请在命令模式下按 H 或转到 Help 菜单栏下的 Keyboard shortcuts。请经常检查这些内容，因为经常会有新的快捷键被加进来。



## 

**▌有用的 Jupyter Notebooks 扩展**



扩展可以有效提高你的 Jupyter Notebooks 的生产力。安装和使用扩展的最佳工具之一是 Nbextensions。它需要两个简单的步骤来安装（也有其他方法，但我发现这是最方便的）：



第1步：用 pip 来安装它：



```
pip install jupyter_contrib_nbextensions
```





第2步：安装关联的 JavaScript 和 CSS 文件：



```
jupyter contrib nbextension install --user
```





完成此操作后，你会在 Jupyter Notebook 主页顶部看到一个 Nbextensions 选项卡。这里面有很多非常棒的扩展供你使用。



![img](figures/20180529192622512)



要启用一个扩展，只需点击它来激活。我在下面提到了4个我认为最有用的扩展：



- Code prettify：重新格式化和美化代码块的内容。

![img](figures/20180529192637494)

- Printview：这个扩展添加了一个工具栏按钮来调用当前 Notebook 的 jupyter nbconvert，并可选择在新的浏览器标签中显示转换后的文件。
- Scratchpad：这个扩展增加一个便捷单元格，它可以让你运行你的代码而不必修改你的 Notebook。这是一个非常方便的扩展，特别是当你想要测试你的代码，但不想在你的活动Notebook上做这件事。
- Table of Contents (2)：这个扩展可以收集你的 Notebook 中的所有标题，并将它们显示在一个浮动窗口中。



这些只是你可以使用的其中一些扩展。我强烈建议查看整个扩展列表并对它们进行测试。



## 

**▌保存和共享你的 Notebook**



这是 Jupyter Notebook 中最重要和最棒的功能之一。当我需要写博客文章，但我的代码和注释都保存在 Jupyter 文件中时，我需要先将它们转换为另一种格式。请记住，这些 Notebooks 采用 json 格式，在共享它时这并不是很有帮助。我无法在电子邮件或博客上发布不同的单元格或代码块，对吧？



进入 Files 菜单，你会看到一个 Download As 选项：



![img](figures/20180529192649457)



你可以将你的 Notebook 保存为 7 个选项中的任何一个。最常用的是 .ipynb 文件，这样其他人就可以在自己的机器上复制代码；或者保存为 .html 文件， 这样会打开一个网页（当你想要保存嵌入在 Notebook 中的图像时，这会派上用场）。



你也可以使用 nbconvert 选项手动将你的 Notebook 转换为不同的格式，如 HTML 或 PDF。



你还可以使用 jupyterhub，它允许你在其服务器上托管 Notebooks 并与多个用户共享。许多顶尖的研究项目都使用这个功能用于协作。



## 

**▌JupyterLab**



JupyterLab 于今年 2 月推出，它允许以更灵活和更强大的方式处理项目，但使用的是和 Jupyter Notebooks 相同的组件。JupyterLab 环境与 Jupyter Notebooks 完全相同，但用户会有更高效的体验。



![img](figures/20180529192703307)



在 JupyterLab 中，你只需一个窗口即可安排 Notebook 的工作区域、终端、文本文件和输出！你要做的仅仅是将单元格拖放到你想要的位置。你还可以通过实时预览功能来编辑常用文件格式，如 Markdown、CSV 和 JSON，以便在实际文件中实时查看所发生的变化。



如果你想在你的机器上试用它，你可以在这里查看安装说明（地址：http://jupyterlab.readthedocs.io/en/stable/getting_started/installation.html）。 开发人员的目标是  JupyterLab 最终可以取代 Jupyter Notebooks。但是，要做到这一点还要花点时间。



## 

**▌最佳实践**



虽然单独工作可能很有趣， 但大多数时候你会发现自己是在一个团队中工作。在这种情况下，遵循指导方针和最佳实践非常重要，这样可以确保你的代码和 Jupyter Notebooks 被正确标注，以便与你的团队成员保持一致。下面我列出了一些最佳实践指南，你在 Jupyter Notebooks 上工作时一定要遵循以下指南：



- 对于任何程序员来说最重要的事情之一：始终确保为代码添加合适的注释！

- 确保你有代码所需的文档。

- 考虑一个命名方案，并坚持在所有代码中使用以确保一致性。这样其他人更容易读懂你的代码。

- 无论你需要什么库，在 Notebooks 开始时导入它们（并在它们旁边添加注释，说明导入它们的目的）。

- 确保代码中行与行之间有适当间隔，不要把循环和函数放在同一行中。

- 有时候你会发现你的文件变得非常繁重。看看有没有方法隐藏你认为对于以后参考不太重要的代码。 Notebooks 看起来整洁干净， 让人赏心悦目也非常重要。

- Matplotlib 可以很漂亮整洁地展示你的 Notebook，看看怎么使用它！

    地址：http://nbviewer.jupyter.org/github/jrjohansson/scientific-python-lectures/blob/master/Lecture-4-Matplotlib.ipynb



另一个提示！ 当你想创建演示文稿时，首先想到的工具是 PowerPoint 和 Google Slides。其实你的 Jupyter Notebooks 也可以创建幻灯片！还记得我说它超级灵活吗？ 我一点都没有夸大。



要将你的 Notebooks 转换为幻灯片，请转到  View -> Cell Toolbar，然后单击 Slideshow。看！现在，每个代码块都在右侧显示一个 Slide Type 的下拉选项。它提供了以下 5 个选项：

﻿

![img](figures/20180529192711735)



好好试一试每一个选项以更好地理解它，它会改变你呈现你的代码的方式！



## 

**▌结语**



请注意，这篇文章并没有详尽列出 Jupyter Notebooks 提供的所有功能。还有更多的功能等着你在使用中挖掘。和其他很多事情一样，关键在于实践。



最后分享一个 GitHub 库（地址：https://github.com/jupyter/jupyter/wiki/A-gallery-of-interesting-Jupyter-Notebooks），里面有很多有用的内容。