概述：

* 算法主要是由头文件`<algorithm> <functional> <numeric>`组成
* `algorithm`是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等
* `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
* `<functional>`定义了一些模板类，可以声明函数对象

# 常用遍历算法

* `for_each` // 遍历容器
* `transform` // 搬运容器到另一个容器中

## for_each

函数原型：

* `for_each(iterator beg, iterator end, _func);`

  * 遍历算法，遍历容器元素
  * beg, 开始迭代器
  * end， 结束迭代器
  * _func，函数或者函数对象

  

## transform

函数原型:

* `transform(iterator beg1, iterator end1, iterator beg2, _func)`
  * beg1源容器起始迭代器
  * end1源容器结束迭代器
  * beg2目标容器起始迭代器
  * _func函数或者函数对象

搬运的目标容器需要提前开辟空间，否则无法搬运

# 常用查找算法

算法简介：

* `find` //查找元素
* `find_if` // 按条件查找元素
* `adjacent_find` // 查找相邻重复元素
* `binary_search` // 二分查找
* `count`// 统计元素个数
* `count_if` // 按条件统计元素个数

## find

功能： 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器.end()

函数原型：

* `find(iterator beg, iterator end, value)`
  * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器
  * beg开始迭代器
  * end结束迭代器
  * value按值查找的元素

==查找自定义数据类型需要在自定义数据类型里重载`==`运算符==

## find_if

功能：按条件查找元素

函数原型：

* `find_if(iterator beg, iterator end, _Pred); `
  * 按值查找元素，找到返回指定位置的迭代器，找不到返回结束迭代器.end()
  * beg开始迭代器
  * end结束迭代器
  * _Pred函数或者谓词(返回bool类型的仿函数)

## adjacent_find

功能：查找==相邻重复==的元素

函数原型：

* `adjacent_find(iterator beg, iterator end);`
  * 查找相邻重复元素，返回相邻重复元素的第一个元素位置的迭代器，找不到返回结束迭代器.end()
  * beg 开始迭代器
  * end  结束迭代器

## binary_search

功能：二分法查找指定元素

函数原型：

* `bool binary_search(iterator beg, iterator end, value)`
  * 查找指定的元素，找到返回true，否则反狐false
  * 注意： ==在无序序列中使用此函数，返回结果不一定正确==
  * beg开始迭代器
  * end结束迭代器
  * value查找的元素

## count

功能：统计元素个数

函数原型:

* `count(iterator beg, iterator end, value)`
  * 统计元素出现次数
  * beg开始迭代器
  * end结束迭代器
  * value统计的元素

==统计自定义数据类型时，需要重载自定义数据类型的====

## count_if

函数原型：

* `count_if(iterator beg, iterator end, _Pred)`
  * 按条件统计元素出现的次数
  * beg 开始迭代器
  * end 结束迭代器
  * _Pred谓词

# 常用排序算法

算法：

* `sort(); // 对容器内元素进行排序`
* `random_shuffle(); // 洗牌 指定范围内的元素随机调整次序`
* `merge(); // 容器元素合并， 并存储到另一个容器中`
* `reverse(); // 反转指定范围内的元素`

## sort

功能：对容器内元素进行排序

函数原型：

* `sort(iterator beg, iterator end, _Pred)`
  * beg开始迭代器
  * end结束迭代器
  * _Pred谓词

## random_shuffle

功能：洗牌，随机打乱容器内元素顺序

函数原型：

* `random_shuffle(iterator beg, iterator end)`

## merge

功能：两个容器元素合并，并存储 到另一个容器中

注意：两个容器必须是有序的，合并完成之后依然有序

函数原型：

* `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dst)`
  * beg1, end1, 容器1开始和结束迭代器
  * beg2, end2, 容器2开始和结束迭代器
  * dst目标容器开始迭代器， 目标容器要提前分配空间

## reverse

功能：将容器内元素反转排序

函数原型：

* `reverse(iterator beg, iterator end)`

# 常用拷贝和替换算法

* `copy() // 拷贝`
* `replace() // 替换`
* `replace_if() // 按条件替换`
* `swap() // 互换`

## copy

功能：容器内指定范围的元素拷贝到另一个容器之中

函数原型：

* `copy(iterator beg, iterator end, iterator dst)`
  * beg 开始迭代器
  * end 结束迭代器
  * dst 目标容器起始迭代器

## replace

功能： 将容器内指定范围内的旧元素替换为新元素， 满足条件的区间内元素都会被替换

函数原型：

* `replace(iterator beg, iterator end, oldvalue, newvalue)`

## replace_if

功能：将容器内指定范围内的满足条件的旧元素替换为新元素

函数原型：

* `replace_if(iterator beg, iterator end, _Pred, newvalue)`
  * beg起始迭代器
  * end结束迭代器
  * _Pred谓词
  * newvalue新值

## swap

功能：交换两个容器内元素, 两个容器要同种类型, 两个人容器size可以不同

函数原型:

* `swap(container c1, container c2)`
  * c1 c2容器

# 常用算术生成算法

注意：算术生成算法属于小型算法，使用时包含的头文件为`#include <numeric>`

* `accumulate // 计算容器内元素的总和`
* `fill // 想容器内添加元素`

## accumulate

功能：计算区间内容器的元素总和

函数原型：

* `accumulate(iterator beg, iterator end, value)`
  * beg开始迭代器
  * end结束迭代器
  * value 起始值

## fill

功能：向容器区间内填充指定的元素

函数原型：

* `fill(iterator beg, iterator end, value)`

# 常用集合算法

* `set_intersection交集`
* `set_union并集`
* `set_difference差集`

## set_intersection

功能：求两个容器的交集

函数原型：

* `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator  dst)`
  * 返回交集的结束迭代器

注意：==源容器必须是有序序列==

## set_union

功能：求两个容器的并集

函数原型：

* `set_union(iterator beg1, iteratoe end1, iterator beg2, iterator end2, iterator dst)`
* 注意：两个集合必须是有序序列
* 返回并集的结束迭代器

## set_difference

功能：求两个容器的差集, 差集与顺序有关

函数原型:

* `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dst)`
* 注意：两个集合必须是有序序列
* 返回差集的结束迭代器