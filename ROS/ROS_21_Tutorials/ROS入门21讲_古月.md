# 1. ROS中的核心概念

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

<img src="pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121122026467.png" alt="image-20210121122026467"  />



------------



# 2. ROS命令行工具的使用

![image-20210121140633314](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121140633314.png)

```c
rosrun <功能包名> <节点名>  // 运行节点
rqt_graph // 基于qt的可视化工具，显示系统计算图

rosnode [list|ping|info|kill|machine]
rosnode list // 显示所有节点
rosnode info // 显示节点信息

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
rosservice call <服务名> // call the service with the provided args
rosservice find // find services by service type
rosservice info // print information about service
rosservice list // list active services
rosservice type // print service type

rosbag // 话题记录
rosbag record <话题名> -O <输出文件名>
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

# 3. 创建工作空间与功能包

工作空间(workspace)是一个存放工程开发相关文件的文件夹

* src : 代码空间 source space
* build : 编译空间 build space
* devel : 开发空间 development space
* install: 安装空间 install space



创建工作空间

```bash
mkdir -p ~/catkin_ws/src // 路径可以自己指定
cd ~/catkin_ws/src
catkin_init_workspace
```

编译工作空间

```bash
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

```bash
cd ~/catkin_ws/src
catkin_create_pkg test_pkg std_msgs rospy roscpp
```

编译功能包

```bash
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash
```

注意：同一个工作空间下，不允许存在同名功能包，不同工作空间下，可以存在同名功能包

---

# 4. Publisher的编程实现

![image-20210121151436608](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210121151436608.png)

创建功能包

```bash
cd ~/catkin_ws/src
catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim
```

**如何创建一个Publisher**

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

C++示例代码：

```cpp
#include <ros/ros.h>
// 包含相关message的头文件
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	// ROS节点初始化，第三个参数是节点名称
	ros::init(argc, argv, "velocityPublisher");

	/// 创建节点句柄，用于管理节点资源
	ros::NodeHandle nodeHandle;

	/// 创建一个Publisher， 消息类型为geometry_msgs:Twist第一个参数是topic name， 第二个参数是queue长度
	ros::Publisher velocityPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// 设置循环的频率
	ros::Rate loopRate(10);

	while (ros::ok())
	{
		// 创建消息对象
		geometry_msgs::Twist velMsg;
		velMsg.linear.x = 0.5;
		velMsg.angular.z = 0.1;

		// 发布message
		velocityPublisher.publish(velMsg);
		ROS_INFO("Published turtle velocity command [%.2f m/s %.2f rad/s]\n", velMsg.linear.x, velMsg.angular.z);

		// 按照设定的频率延时
		loopRate.sleep();
	}

	return 0;
}
```

python示例代码

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist


def velocity_publisher():
    # ROS节点初始化
    rospy.init_node("velocity_publisher", anonymous=True)

    # 创建一个Publisher， topic名为/turtle1/cmd_vel， message类型为Twist， 队列长度为10
    turtle_vel_publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)

    # 循环频率为10
    loop_rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # 创建消息对象
        vel_msg = Twist()
        vel_msg.linear.x = 0.5
        vel_msg.angular.z = 0.5

        # 发布消息
        turtle_vel_publisher.publish(vel_msg)
        rospy.loginfo("Published turtle velocity command: [%.2f m/s, %.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z)

        # 延迟一段时间
        loop_rate.sleep()


if "__main__" == __name__:
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass

```

# 5. Subscriber的编程实现

![image-20210310172441762](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210310172441762.png)

如何创建Subscriber：

1. 初始化ROS节点
2. 订阅需要的话题
3. 循环等待话题消息，接受到消息后进入回调函数
4. 在回调函数中完成消息处理



C++示例代码：

```cpp
#include <ros/ros.h>
#include "turtlesim/Pose.h" // 引入消息类型的头文件

// 接收到订阅的消息后，会进入消息回调函数
void poseCallBack(const turtlesim::Pose::ConstPtr &msg)
{
	ROS_INFO("Turtle Pose: x: %.2f, y: %.2f", msg->x, msg->y); // 打印接受到的消息
}

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "poseSubscriber");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 创建一个Subscriber， 订阅的topic为/turtle1/Pose， 队列长度为10, 回调函数为poseCallBack
	ros::Subscriber poseSubscriber = nodeHandle.subscribe("/turtle1/pose", 10, poseCallBack);

	// 循环等待回调函数
	ros::spin();

	return 0;
}
```

python示例代码：

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from turtlesim.msg import Pose


def pose_callback(msg):
    rospy.loginfo("Turtle pose: x: %.2f, y: %.2f", msg.x, msg.y)


def pose_subscriber():
    # ROS节点初始化
    rospy.init_node("pose_subscriber", anonymous=True)

    # 创建一个Subscriber，订阅topic为/turtle1/pose，message类型为Pose, 处理消息的回调函数为pose_callback
    rospy.Subscriber("/turtle1/pose", Pose, callback=pose_callback)

    # 循环等待回调函数
    rospy.spin()


if "__main__" == __name__:
    pose_subscriber()
```

# 6. topic message的定义与使用

![image-20210310180704854](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210310180704854.png)

如何自定义话题消息：

1. 定义msg文件， 如:

   ```c
   string name
   uint8 age
   uint8 sex
   
   uint8 unknown = 0
   uint8 male = 1
   uint8 female = 2
   ```

   此文件与语言无关，此文件推荐放到一个包中的src/msg文件夹下

2. 在package.xml中添加功能包依赖

   * `<build_depend>message_generation</build_depend>`
   * `<exec_depend>message_runtime</exec_depend>`

3. 在CMakeLists.txt中添加编译选项

   * ```cmake
     find_package(...... message_generation)
     
     add_message_files(FILES <message文件名>)
     
     generate_messages(DEPENDENCIES std_msgs)
     
     catkin_package(...... message_runtime)
     ```

4. 编译生成语言相关文件

5. 配置CMakeLists.txt中的编译规则

   ```cmake
   add_executable(exe 文件名)
   target_link_libraries(exe ${catkin_LIBRARIES})
   add_dependencies(exe ${PROJECT_NAME}_generate_messages_cpp)
   ```

   # 7. 客户端Client的编程实现

   ![image-20210310200114454](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210310200114454.png)

创建功能包

```bash
cd catkin_ws/src
catkin_create_package learning_service roscpp rospy std_msgs geometry_msgs turtlesim
```

**如何创建一个Client**

1. 初始化ROS节点
2. 创建一个Client对象
3. 发布服务请求数据
4. 等待Server处理之后的应答结果



C++示例

```cpp
#include <ros/ros.h>
#include <turtlesim/Spawn.h> // 包含服务的头文件

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "turtleSpawn");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 阻塞，等待发现/spawn服务
	ros::service::waitForService("/spawn");

	// 上一步代码通过后，创建一个Client， 连接的service是/spawn
	ros::ServiceClient addTurtle = nodeHandle.serviceClient<turtlesim::Spawn>("/spawn");

	// 创建turtlesim::Spawn类型的服务请求数据
	turtlesim::Spawn srv;
	srv.request.x = 3.0;
	srv.request.y = 3.0;
	srv.request.name = "turtle2";
	ROS_INFO("Call service to spawn turtle [x: %.2f, y: %.2f, name: %s]",
			 srv.request.x, srv.request.y, srv.request.name.c_str());

	// 阻塞，请求服务调用， 等待Server的反馈后才会往下运行
	addTurtle.call(srv);

	// 显示服务调用结果
	ROS_INFO("Spawn turtle successfully! [name: %s]", srv.response.name.c_str());

	return 0;
}
```

python示例：

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Client 示例代码
import rospy
from turtlesim.srv import Spawn


def turtle_spawn():
    # 初始化ROS节点
    rospy.init_node("turtle_spawn", anonymous=True)

    # 阻塞，一直等待直到连接到/spawn服务
    rospy.wait_for_service("/spawn")

    try:
        # 创建Client， 连接的service为/spawn， 服务类型为Spawn
        add_turtle = rospy.ServiceProxy("/spawn", Spawn)
        # 请求服务调用，输入请求数据
        response = add_turtle(2.0, 2.0, 0.0, "turtle2")
        return response.name
    except rospy.ServiceException as e:
        print("Service call failed: %s", e)


if __name__ == "__main__":
    ret = turtle_spawn()
    print("Spawn turtle successfully! name: %s" % ret)
```

# 8. 服务端Server的编程实现

![image-20210310203517565](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210310203517565.png)

**如何实现一个Server**

1. 初始化ROS节点
2. 创建Server实例
3. 循环等待服务请求，等到的话进入回调函数
4. 在回调函数中2完成服务功能的处理，并反馈应答数据

C++示例代码

```cpp
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

bool pubCommand = false; // 用于记录Trigger信息, 为真的话发布海龟运动的速度信息

bool commandCallback(std_srvs::Trigger::Request &request, std_srvs::Trigger::Response &response);

int main(int argc, char **argv)
{
	// 初始化节点
	ros::init(argc, argv, "turtleCommandServer");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 创建一个Server， service名为/turtle_command， 注册回调函数
	ros::ServiceServer commandServer = nodeHandle.advertiseService("/turtle_command", commandCallback);

	// 创建一个Publisher， topic名称为/turtle1/cmd_vel， 队列长度为10
	ros::Publisher turtleVelPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// 设置循环频率
	ros::Rate loopRate(10);

	while (ros::ok())
	{
		// 查看一次回调函数队列
		ros::spinOnce();

		if (pubCommand) // 如果pubCommand为真则发布数据海龟运动的信息
		{
			geometry_msgs::Twist velMsg;
			velMsg.linear.x = 0.5;
			velMsg.angular.z = 0.5;
			turtleVelPublisher.publish(velMsg);
		}

		// 按照设定好的循环频率延时
		loopRate.sleep();
	}

	return 0;
}

/**
 * @brief 用于注册到service的回调函数
 * @param request 向server的请求
 * @param response server的回应
 * @return server处理是否成功
 */
bool commandCallback(std_srvs::Trigger::Request &request, std_srvs::Trigger::Response &response)
{
	pubCommand = !pubCommand;

	ROS_INFO("Publish turtle velocity command [%s]", true == pubCommand ? "Yes" : "No");

	// 设置反馈数据
	response.success = true;
	response.message = "Change turtle command state!";

	return true;
}
```

```bash
cd catkin_ws
catkin_make
source devel/setup.bash
roscore
rosrun turtlesim turtlesim_node
rosrun learning_service turtleCommandServer
rosservice call /turtle_command "{}"
```

# 9.  service数据类型srv的定义与使用

![image-20210311155128105](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210311155128105.png)

例如，自定义src类型 Person.srv:三个横线以上是request数据，三个横线以下是response数据

```c
string name
uint8 age
uint8 sex

uint8 unknown  = 0
uint8 male = 1
uint8 female = 2
---
string result
```

**如何自定义数据类型**

1. 定义srv文件

2. 在package.xml中添加功能包依赖

   ```xml
   <build_depend>message_generation</build_depend>
   <exec_depend>message_runtime</exec_depend>
   ```

3. 在CmakeLists.txt中添加编译选项

   ```cmake
   find_package(... message_generation)
   
   add_service_files(FILES Person.srv)
   generate_messages(DEPENDENCIES std_msgs)
   
   catkin_package(... message_runtime)
   ```

4. 编译生成语言相关文件

5. 配置CmakeLists.txt中的编译规则

   ```cmake
   add_executable(<可执行文件名> <源文件名>)
   target_link_libraries(<可执行文件名> ${catkin_LIBRARIES})
   add_dependencies(<可执行文件名> ${PROJECT_NAME}_gencpp)
   ```

# 10. 参数parameter的使用

参数模型：

![image-20210311180434244](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210311180434244.png)

创建功能包

```bash
cd catkin_ws
catkin_create_package learning_parameter roscpp rospy std_srvs
```

yaml参数文件示例:

```yaml
background_b: 255
background_g: 86
background_r: 69
rosdistro: 'melodic'
roslaunch:
	uris: {host_hcx_vpn_43763: 'http://hcx-vpc:43763'}
rosversion: '1.14.3'
run_id: 11111111-1111-1111-1111-111111111111

```

ros参数命令：

```bash
rosparam list // 列出当前所有参数
rosparam get param_key // 显示某个参数值
rosparam set param_key param_val // 设置某个参数值
rosparam dump file_name // 保存参数到文件
rosparam load file_name // 从文件读取参数
rosparam delete param_key // 删除某个参数
```

**如何编程设置/获取参数**

1. 初始化ROS节点
2. get函数获取参数
3. set函数设置参数

# 11. ROS中的坐标系管理系统tf

# 12.

# 13. launch启动文件的使用方法

launch文件：通过xml文件实现多节点的配置和启动，可自动启动ros master

## launch文件语法

```xml
<launch>
    <node pkg="turtlesim" name = "sim1" type="turtlesim_node"/>
    <node pkg="turtlesim" name = "sim2" type="turtlesim_node"/>
</launch>
```

* `<launch>`: launch文件中的根元素采用`<launch>`标签定义 

* `<node>`：启动节点

  * `<node pkg="package_name" type="executable_name" name="node_name"/>`
  * pkg: 节点所在的功能包名称
  * type: 节点的可执行文件
  * name: 节点运行时的名称，会取代代码中ros::init(argc, argv, nodename)中的节点名
  * output（控制节点日志信息是否打印到终端）、respawn（重启如果停止）、required（必须启动）、ns（命名空间）、args（输入参数）

* `<param>/<rosparam>`: 设置ROS系统运行中的参数，存储在参数服务器中

  * <param name="参数名" value="参数值"/>
  * 加载参数文件中的多个参数：`<rosparam file="param_file.yaml" command="load" ns="params"/>`

* `<arg>`：launch文件内部的局部变量， 仅限于launch文件使用

  * `<arg name="arg_name" defaul="arg_value"/>`

  * 调用: `$(arg 参数名)`

    ```yaml
    <param name="foo" value="$(arg arg_name)"/>
    <node name="node_name" pkg="pkg_name" type="type_name" args="$(arg arg_name)"/>
    ```

* `<remap>`: 重映射ROS计算图资源的命名

  * `<remap from="/turtle1/cmd_vel" to="/cmd_vel"/>`
  * from: 原命名
  * to: 映射之后的重命名

* `<include >`嵌套，包含其他launch文件。类似C语言中的头文件包含

  * `<include file="$(dirname)/other_launch.launch">`
  * file: 包含其他的launch文件的路径

launch文件示例：

![image-20210311193007100](pics/ROS%E5%85%A5%E9%97%A821%E8%AE%B2_%E5%8F%A4%E6%9C%88/image-20210311193007100.png)















