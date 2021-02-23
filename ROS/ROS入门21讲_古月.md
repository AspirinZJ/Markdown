# ROS中的核心概念

## 通信机制

### 节点与节点管理器

节点（node）： 执行单元

* 执行具体任务的进程、独立运行的可执行文件
* 不同节点可以使用不同的编程语言，可分布式运行在不同的主机
* 节点在系统中的名称必须是唯一的



节点管理器（ROS Manage）：控制中心

* 为节点提供命名与注册服务
* 跟踪和记录话题/服务信息，辅助节点相互查找、建立链接
* 提供参数服务器，节点使用此服务器存储和检索运行时的参数

<img src="pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121115950351.png" alt="image-20210121115950351" style="zoom: 67%;" />

### 话题通信

==话题（topic）： 异步通信机制==

* 节点间用来传输数据的重要总线
* 使用==发布/订阅==模型，数据由发布者传输到订阅者，同一个话题的订阅者或发布者==可以不唯一==

![image-20210121120334670](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121120334670.png)

==消息（message）：话题数据==

* 具有一定的类型和数据结构，包括ROS提供的标准类型和用户自定义类型
* 使用编程语言无关的==.msg文件==定义，编译过程中生成对应的代码文件

![image-20210121120536501](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121120536501.png)

### 服务通信

==服务（service）：同步通信机制==

* 使用==客户端/服务器（C/S）模型==，客户端发送==请求==数据，服务器完成处理后返回==应答==数据
* 使用编程语言无关的==.srv文件==定义请求和应答数据结构，编译过程中生成对应的代码文件

![image-20210121120928640](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121120928640.png)

<img src="pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121120955680.png" alt="image-20210121120955680" style="zoom: 50%;" />

话题信息是单向的，服务信息是双向的，而且只收发一次

![image-20210121121250720](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121121250720.png)

### 参数

==参数（parameter）：全局共享字典==

* 可通过==网络==访问的==共享、多变量字典==
* 节点使用此服务器来存储和检索==运行时的参数==
* 适合存储静态、非二进制的==配置参数==，不适合存储动态配置的数据
* 底层通讯机制是RPC

![image-20210121121623887](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121121623887.png)

### 文件系统

==功能包（package）==

* ROS软件中的基本单元，包含节点源码、配置文件、数据定义等

==功能包清单（package manifest）==

* 记录功能包的基本信息，包含作者信息、许可信息、依赖选项、编译标志等

==元功能包（meta packages）==

* 组织多个用于同一目地的功能包

![image-20210121122026467](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121122026467.png)



------------



# ROS命令行工具的使用

![image-20210121140633314](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121140633314.png)

```c
rosrun <功能包名> <节点名>  // 运行节点
rqt_graph // 基于qt的可视化工具，显示系统计算图

rosnode [list|ping|info|kill|machine]
rosnode list // 显示节点信息
rosnode info

rostopic // 话题
rostopic list // 显示所有话题
rostopic pub <话题名> <信息结构> <"具体信息内容"> // 发布一次消息
rostopic pub -r <频率(/s)> <话题名> <信息结构> <"具体信息内容"> // 以指定频率发布消息

rosmsg // 信息结构
rosmsg show <信息结构> // show message description
rosmsg info = rosmsg show
rosmsg list // list all messages
rosmsg package // list messages in a package
rosmsg packages // list packages that contain messages

rosservice // 服务
rosservice args // print service arguments
rosservice call // call the service with the provided args
rosservice find // find services by service type
rosservice info // print information about service
rosservice list // list active services
rosservice type // print service type

rosbag // 话题记录
rosbag record -a -O <fileName> // 记录 -a记录所有的数据 -O <filename>指定输出的保存文件名
rosbag plag <bagfileName> // 复现
```

## 以小海龟为例

查看话题列表

`rosnode list`

发布话题消息

```c
rostopic -r 10 /turtle1/cmd_vel geometry_msgs/Twist "linear:
x:1.0
y:0.0
z:1.0
angular:
x:0.0
y:0.0
z:1.0
"
```

发布服务请求

```c
rosservice call /spawn "x:5.0
y:0.0
theta:0.0
name:'turtle2'"
```

话题记录

`rosbag record -a -O cmd_vel_save`

话题复现

`rosbag play ./cmd_vel_save.bag`



--------

# 创建工作空间与功能包

工作空间(workspace)是一个存放工程开发相关文件的文件夹

* src : 代码空间 source space
* build : 编译空间 build space
* devel : 开发空间 development space
* install: 安装空间 install space



创建工作空间

```c
mkdir -p ~/catkin_ws/src // 路径可以自己指定
cd ~/catkin_ws/src
catkin_init_workspace
```

编译工作空间

```c
cd ~/catkin_ws
catkin_make
```

设置环境变量

`source ./devel/setup.bash`

检查环境变量

`echo $ROS_PACKAGE_PATH`



创建功能包

`catkin_create_pkg <packageName> [depend1] [depend2]...`

创建功能包

```c
cd ~/catkin_ws/src
catkin_create_pkg test_pkg std_msgs rospy roscpp
```

编译功能包

```c
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash
```



注意：同一个工作空间下，不允许存在同名功能包，不同工作空间下，可以存在同名功能包



---

# Publisher的编程实现

![image-20210121151436608](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121151436608.png)

创建功能包

```
cd ~/catkin_ws/src
catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim
```



* 如何创建一个Publisher
  * 初始化ROS节点
  * 向ROS Master注册节点信息，包括发布的话题名和话题中的消息类型
  * 创建消息数据
  * 按照一定频率循环发布消息

## 配置发布者代码编译规则

如何配置CMakeLists.txt中的编译规则

* 设置需要编译的代码和生成的可执行文件
* 设置链接库

```cmake
add_executable(velocity_publisher src/velocity_publisher.cpp)
target_link_libraries(velocity_publisher ${catkin_LIBRARIES})
```

编译并运行publisher

```c
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash
roscore
rosrun turtlesim turtlesim_node
rosrun learning_publisher velocity_publisher
```

运行publisher

```
rosrun learning_topic velocity_publisher // 运行c++编译的
rosrun learning_topic velocity_publisher.py // 直接将py文件放在package的src/scripts下面，即可运行
```

---



# Subscriber的编程实现

