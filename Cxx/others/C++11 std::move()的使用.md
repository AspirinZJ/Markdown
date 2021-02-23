功能：std::move函数可以以非常简单的方式将左值引用转换为右值引用。

优点：调用此函数不会引起任何数据争用。（Calling this function introduces no data races.）

- 通过std::move，可以避免不必要的拷贝操作。
- std::move是为性能而生。
- std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝。

要注意，在标准库中，移动意味着从中移出的对象处于有效但未指定的状态。 这意味着在执行此操作后，仅应销毁移出对象的值或为其分配新值； 否则访问它会产生未指定的值。

如string类在赋值或者拷贝构造函数中会声明char数组来存放数据，然后把原string中的 char 数组被析构函数释放，如果a是一个临时变量，则上面的拷贝，析构就是多余的，完全可以把临时变量a中的数据直接 “转移” 到新的变量下面即可。

```c++
#include <iostream>
#include <utility>
#include <vector>
#include <string>
int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";
}
```

```c++
// move example
#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

int main()
{
   std::string foo = "foo-string";
   std::string bar = "bar-string";
   std::vector<std::string> myvector;

   myvector.push_back(foo);                    // copies
   myvector.push_back(std::move(bar));         // moves

   std::cout << "myvector contains:";
   for (std::string &x:myvector) std::cout << ' ' << x;
   std::cout << '\n';

   std::cout << "foo:" << foo << '\n';
   std::cout << "bar:" << bar << std::endl;

   return 0;
}
```

输出结果如下：

```cpp
myvector contains: foo-string bar-string
foo:foo-string
bar:
```

看看如果不用std::move()对比一下：

```cpp
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

int main()
{
	std::string foo = "foo-string";
	std::string bar = "bar-string";
	std::vector<std::string> myvector;

	myvector.push_back(foo);                    // copies
	myvector.push_back(bar);         // moves

	std::cout << "myvector contains:";
	for (std::string &x:myvector) std::cout << ' ' << x;
	std::cout << '\n';

	std::cout << "foo:" << foo << '\n';
	std::cout << "bar:" << bar << std::endl;

	return 0;
}
```

输出结果如下：

```cpp
myvector contains: foo-string bar-string
foo:foo-string
bar:bar-string
```

参考中对于这个例子的解释：

第一次调用myvector.push_back会将foo的值复制到向量中（foo保留调用前的值）。
第二次调用将bar的值移动到向量中。 这会将其内容传输到向量中（而bar失去其值，并且现在处于有效但未指定的状态）。