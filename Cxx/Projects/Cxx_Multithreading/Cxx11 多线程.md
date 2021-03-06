# 1.创建一个简单的多线程案例：

首先导入==#include<thread>---用于创建线程==

其次导入==#include<chrono>--用于时间延时 获取时间之类==的

> 定义一个线程对象t1，这就自动创建了一个线程，参数就是你要线程去执行的函数，t1是变量名字 随便取
>
> std::thread t1(func);
>
> 下面这里返回一个毫秒级别的时间间隔参数值，间隔10毫秒 
>
> std::chrono::milliseconds(10)
>
> this_thread::sleep_for()就是让此线程休眠，可以传入休眠的时间
>
> this_thread::sleep_for(std::chrono::milliseconds(10));让本线程休眠10毫秒

好了知道这些参数意思就行了，看一下代码：

```c++
#include<windows.h>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int number = 1;

int ThreadProc1()
{
    while (number < 100)
    {
        cout << "thread 1 :" << number << endl;
        ++number;
       this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}

int ThreadProc2()
{
    while (number < 100)
    {
        cout << "thread 2 :" << number << endl;
        ++number;
        this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;理侯爵是一个暴虐的父亲，与道格拉斯长期以来争
}

int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);

    t1.join();
    t2.join();

    system("pause");
    return 0;
}
```



　　==join()就是阻塞线程，直到线程函数执行完毕==，如果函数有返回值，在这里会直接忽略。==阻塞的目的就是让Main主线程等待一下创建的线程==，免得我函数还在跑，程序就直接结束了。

　　如果==不想阻塞在这里就将join()换成使用线程的detach()方法，将线程与线程对象分离==，线程就可以继续运行下去，并且不会造成影响。

 

# 2.互斥量的使用

　　跟往常的多线程一样，==多线程在运行过程中都会对临界区进行访问，也就是一起访问共享资源==。这样就会造成一个问题，当两个线程都要对一个变量int value值假如为11，加一时，线程一取出11 进行加一还没有存入value,这时候线程二又取得value的11进行加一，然后线程一存入12，线程二又存入12，这就导入两个线程访问冲突，也就是==临界区问题==。所以==引进互斥量来解决。==

==导入#include <mutex>==

```c++
//一个线程对变量number进行加一100次，另外一个减一100次，最后结果应该还是原来的值0。
#include<windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

int number = 0;
mutex g_lock;

int ThreadProc1()
{
    for (int i = 0; i < 100; i++)
    {
        g_lock.lock();
        ++number;
        cout << "thread 1 :" << number << endl;
        g_lock.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}

int ThreadProc2()
{
    for (int i = 0; i < 100; i++)
    {
        g_lock.lock();
        --number;
        cout << "thread 2 :" << number << endl;
        g_lock.unlock();
        this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}

int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);

    t1.detach();
    t2.detach();

    system("pause");
    return 0;
} 
```

上面的每次都要对mutex变量进行锁以及解锁，有时候==忘记解锁就凉凉了==。所以c++11还提供了一个==lock_guard类，它利用了RAII机制可以保证安全释放mutex==。

==在std::lock_guard对象构造时，传入的mutex对象(即它所管理的mutex对象)会被当前线程锁住。在lock_guard对象被析构时，它所管理的mutex对象会自动解锁，不需要程序员手动调用lock和unlock对mutex进行上锁和解锁操作。==l==ock_guard对象并不负责管理mutex对象的生命周期，lock_guard对象只是简化了mutex对象的上锁和解锁操作，方便线程对互斥量上锁，即在某个lock_guard对象的生命周期内，它所管理的锁对象会一直保持上锁状态；而lock_guard的生命周期结束之后，它所管理的锁对象会被解锁。程序员可以非常方便地使用lock_guard，而不用担心异常安全问题。==

```c++
#include<windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

int number = 0;
mutex g_lock;

int ThreadProc1()
{
    lock_guard<mutex> loker(g_lock);
    for (int i = 0; i < 100; i++)
    {
        ++number;
        cout << "thread 1 :" << number << endl;
    }
    //this_thread::sleep_for(std::chrono::milliseconds(100));
    return 0;
}

int ThreadProc2()
{
    lock_guard<mutex> loker(g_lock);
    for (int i = 0; i < 100; i++)
    {
        --number;
        cout << "thread 2 :" << number << endl;
        //this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}

int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);

    t1.detach();
    t2.detach();

    system("pause");
    return 0;
}
```

除了lock_guard，之外c++11还提供了==std::unique_lock==

> 类 unique_lock 是通用互斥包装器，允许`延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用`。
> unique_lock比lock_guard使用更加灵活，功能更加强大。
> 使用unique_lock需要付出更多的时间、性能成本。

```c++
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock
#include <vector>

std::mutex mtx;           // mutex for critical section
std::once_flag flag;        //定义一个once_flag类型的变量作为call_once参数，    
                                    //用std::call_once来保证多线程环境中只被调用一次
void print_block (int n, char c) {
    //unique_lock有多组构造函数, 这里std::defer_lock不设置锁状态
    std::unique_lock<std::mutex> my_lock (mtx, std::defer_lock);
    //尝试加锁, 如果加锁成功则执行
    //(适合定时执行一个job的场景, 一个线程执行就可以, 可以用更新时间戳辅助)
    if(my_lock.try_lock()){
        for (int i=0; i<n; ++i)
            std::cout << c;
        std::cout << '\n';
    }
}

void run_one(int &n){
    std::call_once(flag, [&n]{n=n+1;}); //只执行一次, 适合延迟加载; 多线程static变量情况
}

int main () {
    std::vector<std::thread> ver;
    int num = 0;
    for (auto i = 0; i < 10; ++i){
        ver.emplace_back(print_block,50,'*');  
        ver.emplace_back(run_one, std::ref(num));
  //emplace_back比push_back更好 是c++11增加的
    }

    for (auto &t : ver){
        t.join();
    }
    std::cout << num << std::endl;
    return 0;
}                    
```

 



**条件变量std::condition_variable的使用**

这里还要补充一下跟互斥量很像的条件变量的知识。std::condition_variable 是为了解决死锁而生的。当互斥操作不够用而引入的。比如，线程可能需要等待某个条件为真才能继续执行，而一个忙等待循环中可能会导致所有其他线程都无法进入临界区使得条件为真时，就会发生死锁。所以，==condition_variable实例被创建出现主要就是用于唤醒等待线程从而避免死锁==。std::condition_variable的 ==notify_one()用于唤醒一个线程；notify_all() 则是通知所有线程==。
C++11中的std::condition_variable==可以让线程休眠，直到别唤醒，现在在从新执行==。线程等待在多线程编程中使用非常频繁，经常需要等待一些异步执行的条件的返回结果。

```cpp
#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<chrono>

std::mutex g_mu;
std::condition_variable g_vc;
bool g_ready = false;

void dispaly_id(int id)
{
    std::unique_lock<std::mutex> lck(g_mu);
    g_vc.wait(lck, []() {return g_ready; });   //线程阻塞，直到第二个参数返回值为真

    std::cout << "id:" << id << std::endl;
}

void ready()
{
    std::unique_lock<std::mutex> lck(g_mu);
    g_ready = true;
    g_vc.notify_all();    //唤醒所有的等待线程
}

int main()
{
    std::thread t[8];
    for (int i = 0; i < 8; i++)
    {
        t[i] = std::thread(dispaly_id, i);
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "all thread lock......" << std::endl;
    
    ready();
    for (auto & th : t) th.join();

    system("pause");

    return 0;
}
```

 

某年滴滴打车公司修改题目：有3个线程A，B， C， 请用多线程编程实现在屏幕上循环打印10次ABCABC...， 其中A线程打印“A”， B线程打印“B”， C线程打印“C”。 滴滴面试题修改为用十个线层，打印字母也变为十个。有兴趣可自行修改

```c++
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>

#define NUM_PRINT 10

std::mutex g_mu;
std::condition_variable g_cond;
int g_chDiff = 0;

void printChar(char);

int main()
{
	std::vector<std::thread> vThread;

	vThread.emplace_back(printChar, 'A');
	vThread.emplace_back(printChar, 'B');
	vThread.emplace_back(printChar, 'C');

	std::for_each(begin(vThread), end(vThread), std::mem_fn(&std::thread::join));

	return 0;
}

void printChar(char ch)
{
	int chDiff = ch - 'A';
	for (int i = 0; i < NUM_PRINT; ++i)
	{
		std::unique_lock<std::mutex> locker(g_mu);
		g_cond.wait(locker, [chDiff]() -> bool { return chDiff == g_chDiff; });
		std::cout << ch;
		g_chDiff = (chDiff + 1) % 3;
		locker.unlock();
		g_cond.notify_all();
	}
}
```

# 3.原子变量的使用

在新标准C++11，引入了原子操作的概念，原子操作更接近内核，并通过这个新的头文件提供了多种原子操作数据类型，例如，==atomic_bool,atomic_int==等等，如果我们在==多个线程==中对这些类型的共享资源进行操作，编译器将保证这些操作都是原子性的，也就是说，==确保任意时刻只有一个线程对这个资源进行访问==，编译器将保证，多个线程访问这个共享资源的正确性。从而==避免了锁的使用，提高了效率==。

　　上面我们用互斥锁来实现加一百次，减少一百次。使用原子变量会更加简洁。

```c++
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

atomic<int> number(0);//定义原子变量 一次只允许一个线程对其进行访问
//int number = 0;
//mutex g_lock;

int ThreadProc1()
{
    //lock_guard<mutex> loker(mutex);
    for (int i = 0; i < 100; i++)
    {
        ++number;
        cout << "thread 1 :" << number << endl;
        
    }
    //this_thread::sleep_for(std::chrono::milliseconds(100));
    return 0;
}

int ThreadProc2()
{
    //lock_guard<mutex> loker(mutex);
    for (int i = 0; i < 100; i++)
    {
        --number;
        cout << "thread 2 :" << number << endl;
        //this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    return 0;
}

int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);

    t1.detach();
    t2.detach();

    system("pause");
    return 0;
} 
```

可以看到使用了原子变量之后，代码简化了很多，以及以后对某些共享资源我们都可以酌情的定义为原子变量类型，很方便

#  4.future与promise的使用

在c++11中增加的线程库很方便的让我们去使用线程，但是因为做出了一些改变，我们并不能像往常一样直接使用thread.join()获取线程函数的返回值了，而我们有时候又确实要利用线程==函数的返回值==。

而thread库提供了==future用来访问异步操作的结果，因为一个异步操作的结果往往不能立即获取，只能在未来的某个时候从某个地方获取，这个异步操作的结果是一个未来的期待值，所以被称为future==

==future和promise的作用是在不同线程之间传递数据==。

==假设线程1需要线程2的数据，那么组合使用方式如下：==

1.   ==线程1初始化一个promise对象和一个future对象，promise传递给线程2，相当于线程2对线程1的一个承诺；future相当于一个接受一个承诺，用来获取未来线程2传递的值==
2.   ==线程2获取到promise后，需要对这个promise传递有关的数据，之后线程1的future就可以获取数据了。==
3.   ==如果线程1想要获取数据，而线程2未给出数据，则线程1阻塞，直到线程2的数据到达==

![img](pics/Cxx11%20%E5%A4%9A%E7%BA%BF%E7%A8%8B/1251892-20190528161035487-750404552.png)

示例代码：

```c++
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <vector>

void disPlay(std::future<int>& value)
{
    std::cout << "wait some times......" << std::endl;
    auto result = value.get();    //没有获取到值会阻塞等待获取
    std::cout << "Value:" << result << std::endl;
}


int main()
{
    std::promise<int> promise;    
    std::future<int> value = promise.get_future(); //将promise与future绑定
    
    std::thread t1(disPlay, std::ref(value));  //创建线程并且函数传参，ref()是传一个引用
    std::this_thread::sleep_for(std::chrono::seconds(1)); //线程延时1秒

    //给线程传值进去
    promise.set_value(15);
    t1.join();
    
    
    system("pause");

    return 0;
}
```

　　==获取future的结果有三种方式上面是get()获取异步结果值返回，还有wait()等待异步操作完成，以及wait_for（）超时等待返回结果。==

 

#  5.future与package_task的使用

==std::packaged_task包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果。==
==std::packaged_task将其包装的可调用对象的执行结果传递给一个std::future对象，与std::promise某种程度上是很像的，promise保存一个共享状态的值，而package_task保存的是一个函数。==

示例代码：

```c++
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <vector>

inline int func(int x)
{
    return x + 6;
}

int main()
{
    std::packaged_task<int(int)> tsk(func);
    std::future<int> fut = tsk.get_future(); //获取future绑定起来
    
    std::thread(std::move(tsk), 2).detach();//直接将task转移作为线程函数使用

    auto value = fut.get();
    std::cout << "result:" << value << std::endl;
    
    system("pause");

    return 0;
} 
```

#  6.线程异步操作函数async的用法



==std::async比std::packaged_task，std::promise中，std::thread更高一层，它可以直接用来创建异步的task，异步的结果也保存在future中。完成后，外面再通过future.get/wait来获取这个未来的结果，强烈推荐使用async，我们不需要关注异步任务的结果，只要等待任务完成获取值就行了。==

现在来看看==std::async的原型async(std::launch::async | std::launch::deferred, f, args...)，第一个参数是线程的创建策略，有两种策略，默认的策略是立即创建线程：==

- ==std::launch::async：在调用async就开始创建线程。==
- ==std::launch::deferred：延迟加载方式创建线程。调用async时不创建线程，直到调用了future的get或者wait时才创建线程。==

第二个参数是线程函数，第三个参数是线程函数的参数。

代码示例：

```c++
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <vector>


int main()
{
    std::future<int> fut = std::async(std::launch::async, []() {
        return 9;
    });
    
    std::cout << "result:" << fut.get() << std::endl;
    system("pause");

    return 0;
}
```

[]()这是c++11里面lambda表达式用法

 

# 7.std::future::wait_for函数

函数原型：

template< class Rep, class Period >
[std::future_status](http://zh.cppreference.com/w/cpp/thread/future_status) wait_for( const [std::chrono::duration](http://zh.cppreference.com/w/cpp/chrono/duration)<Rep,Period>& timeout_duration ) const;

　　==等待结果变得可用。阻塞直至经过指定的 `timeout_duration` ，或结果变为可用，两者的先到来者。返回值鉴别结果的状态。==此函数可能由于调度或资源争议延迟而阻塞长于 `timeout_duration` 。

推荐标准库用稳定时钟度量时长。若实现用系统时钟代替，则等待时间可能也对时钟调整敏感。若调用此函数前 valid()== false 则行为未定义。

**参数**

timeout_duration: 要阻塞的最大时长

**返回值**

| 常量                    | 解释                     |
| ----------------------- | ------------------------ |
| future_status::deferred | 要计算结果的函数仍未启动 |
| future_status::ready    | 结果就绪                 |
| future_status::timeout  | 已经过时限               |

**异常**

时钟、时间点或时长在执行中可能抛的任何异常（标准库提供的时钟、时间点和时长决不抛出）。

**注意**

鼓励==实现在调用前检测 valid == false 的情况并抛出以 future_errc::no_state 为 error_condition 的 future_error==

 

代码示例：

```c++
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
 
int main()
{
    std::future<int> future = std::async(std::launch::async, [](){ 
        std::this_thread::sleep_for(std::chrono::seconds(3));  return 8;}); 
 
    std::cout << "waiting...\n";
    std::future_status status;
    do {
        status = future.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred) {
            std::cout << "deferred\n";
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout\n";
        } else if (status == std::future_status::ready) {
            std::cout << "ready!\n";
        }
    } while (status != std::future_status::ready); 
 
    std::cout << "result is " << future.get() << '\n';
}
```

可能结果：

```c++
waiting...
timeout
timeout
ready!
result is 8
```
