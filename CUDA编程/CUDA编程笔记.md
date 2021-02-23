# GPU 硬件架构综述

## 术语

-   SPA: Streaming Processor Array
-   TPC/GPC: Texture(Graphics) Processor Cluster
-   SM: Streaming Multiprocessor, Multi-threaded processor core, Fundamental processing unit for CUDA thread block
-   SP: Streaming Processor(CUDA core)

## Overview

![image-20200907181310714](CUDA编程笔记/pics/image-20200907181310714.png)

每32个线程是一个Warp

## Thread Life

![image-20200907181541775](CUDA编程笔记/pics/image-20200907181541775.png)

![image-20200907182109296](CUDA编程笔记/pics/image-20200907182109296.png)

![image-20200907182231693](CUDA编程笔记/pics/image-20200907182231693.png)

![image-20200907182337700](CUDA编程笔记/pics/image-20200907182337700.png)

 

![image-20200907183138933](CUDA编程笔记/pics/image-20200907183138933.png)

![image-20200907183351745](CUDA编程笔记/pics/image-20200907183351745.png)

![image-20200908113830629](CUDA编程笔记/pics/image-20200908113830629.png)

![image-20200908113932415](CUDA编程笔记/pics/image-20200908113932415.png)

每个块尽量少使用寄存器

![image-20200908114003900](CUDA编程笔记/pics/image-20200908114003900.png)

![image-20200908114228765](CUDA编程笔记/pics/image-20200908114228765.png)

![image-20200908114245943](CUDA编程笔记/pics/image-20200908114245943.png)

![image-20200908114328156](CUDA编程笔记/pics/image-20200908114328156.png)

![image-20200908114455915](CUDA编程笔记/pics/image-20200908114455915.png)

![image-20200908114743602](CUDA编程笔记/pics/image-20200908114743602.png)

![image-20200908115324745](CUDA编程笔记/pics/image-20200908115324745.png)



---

# CUDA编程模型

![image-20200908115107596](CUDA编程笔记/pics/image-20200908115107596.png)

![image-20200908115856833](CUDA编程笔记/pics/image-20200908115856833.png)

![image-20200908122642102](CUDA编程笔记/pics/image-20200908122642102.png)

`__global__`返回类型必须为`void`

![image-20200908122959806](CUDA编程笔记/pics/image-20200908122959806.png)

向量长1000000, 每个块256个线程，gs是块数 

![image-20200908132632399](CUDA编程笔记/pics/image-20200908132632399.png)

![image-20200908132815936](CUDA编程笔记/pics/image-20200908132815936.png)

![image-20200908132857758](CUDA编程笔记/pics/image-20200908132857758.png)

 ![image-20200908133124286](CUDA编程笔记/pics/image-20200908133124286.png)

![image-20200908140542188](CUDA编程笔记/pics/image-20200908140542188.png)

CPU调用完核函数不会等待GPU运行完成而是直接运行接下来的代码

![image-20200908140833118](CUDA编程笔记/pics/image-20200908140833118.png)

![image-20200908141121311](CUDA编程笔记/pics/image-20200908141121311.png)

因为不能调用host函数，所以将`get_tid`和`get_bid`写成了宏的格式

`if (i < n)`是防止线程数大于向量长度



## 向量加法程序解析

![image-20200908141713096](CUDA编程笔记/pics/image-20200908141713096.png)



## Grid Block Warp Thread 介绍

![image-20200908181831994](CUDA编程笔记/pics/image-20200908181831994.png)

Index首先`x`方向增加，之后是`y`，之后是`z`。这样的话就可以用宏获得位置。

threadIdx是线程在某一个块中的位置。



# GPU内存模型

![image-20200909103446016](CUDA编程笔记/pics/image-20200909103446016.png)

![image-20200909103545868](CUDA编程笔记/pics/image-20200909103545868.png)

共享内存速度非常快， 可以被线程块中所有线程共享。

全局内存速度慢。

SP共享L2缓存

![image-20200909104111103](CUDA编程笔记/pics/image-20200909104111103.png)

![image-20200909104137091](CUDA编程笔记/pics/image-20200909104137091.png)

![image-20200909104207700](CUDA编程笔记/pics/image-20200909104207700.png)

全局内存使用完需要释放。

![image-20200909104316702](CUDA编程笔记/pics/image-20200909104316702.png)

![image-20200909104431427](CUDA编程笔记/pics/image-20200909104431427.png)

![image-20200909104516743](CUDA编程笔记/pics/image-20200909104516743.png)

共享内存需要用`__shared__` 标记

![image-20200909104701932](CUDA编程笔记/pics/image-20200909104701932.png)

![image-20200909104812327](CUDA编程笔记/pics/image-20200909104812327.png)

![image-20200909104943203](CUDA编程笔记/pics/image-20200909104943203.png)

![image-20200909104956372](CUDA编程笔记/pics/image-20200909104956372.png)

![image-20200909105225459](CUDA编程笔记/pics/image-20200909105225459.png)

![image-20200909105309712](CUDA编程笔记/pics/image-20200909105309712.png)

![image-20200909105349581](CUDA编程笔记/pics/image-20200909105349581.png)

![image-20200909110135889](CUDA编程笔记/pics/image-20200909110135889.png)

![image-20200909110218573](CUDA编程笔记/pics/image-20200909110218573.png)



# GPU内存管理

![image-20200909110337129](CUDA编程笔记/pics/image-20200909110337129.png)

CPU与GPU是异构的，内存是独立的。

![image-20200909112336862](CUDA编程笔记/pics/image-20200909112336862.png)

![image-20200909112917211](CUDA编程笔记/pics/image-20200909112917211.png)

![image-20200909113016618](CUDA编程笔记/pics/image-20200909113016618.png)

![image-20200909113343129](CUDA编程笔记/pics/image-20200909113343129.png)

flag默认是cudaMemAttachGlobal

一般新型的GPU才能分配统一内存。

![image-20200909113552394](CUDA编程笔记/pics/image-20200909113552394.png)

同步：数据全被拷贝完才执行下面的语句

![image-20200909113737761](CUDA编程笔记/pics/image-20200909113737761.png)

异步：运行完指令后直接执行下面的指令，异步拷贝一般需要检测一下是否拷贝完成

![image-20200909113834309](CUDA编程笔记/pics/image-20200909113834309.png)

共享内存编译时确定

**![image-20200909113935834](CUDA编程笔记/pics/image-20200909113935834.png)**



# 内存使用

```cpp
#include <stdio.h>
#include <cuda.h>

typedef double FLOAT;

__global__ void sum(FLOAT *x)
{
    int tid = threadIdx.x;

    x[tid] += 1;
}

int main()
{
    int N = 32;
    int nbytes = N * sizeof(FLOAT);

    FLOAT *dx = NULL, *hx = NULL;
    int i;

    /* allocate GPU mem */
    cudaMalloc((void **)&dx, nbytes);

    if (dx == NULL) {
        printf("couldn't allocate GPU memory\n");
        return -1;
    }

    /* alllocate CPU host mem: memory copy is faster than malloc */
    hx = (FLOAT *)malloc(nbytes);

    if (hx == NULL) {
        printf("couldn't allocate CPU memory\n");
        return -2;
    }

    /* init */
    printf("hx original: \n");
    for (i = 0; i < N; i++) {
        hx[i] = i;

        printf("%g\n", hx[i]);
    }

    /* copy data to GPU */
    cudaMemcpy(dx, hx, nbytes, cudaMemcpyHostToDevice);

    /* call GPU */
    sum<<<1, N>>>(dx);

    /* let GPU finish */
    // cudaThreadSynchronize(); // deprecated
    cudaDeviceSynchronize();

    /* copy data from GPU */
    cudaMemcpy(hx, dx, nbytes, cudaMemcpyDeviceToHost);

    printf("\nhx from GPU: \n");
    for (i = 0; i < N; i++) {
        printf("%g\n", hx[i]);
    }

    cudaFree(dx);
    free(hx);

    return 0;
}
```



# CUDA程序执行与硬件映射

![image-20200909124825140](CUDA编程笔记/pics/image-20200909124825140.png)

![image-20200909150519376](CUDA编程笔记/pics/image-20200909150519376.png)

![image-20200909150936014](CUDA编程笔记/pics/image-20200909150936014.png)

![image-20200909151147925](CUDA编程笔记/pics/image-20200909151147925.png)



# 规约算法和并行

![image-20200909151302060](CUDA编程笔记/pics/image-20200909151302060.png)

![image-20200909151345757](CUDA编程笔记/pics/image-20200909151345757.png)

![image-20200909151404164](CUDA编程笔记/pics/image-20200909151404164.png)

![image-20200909151510570](CUDA编程笔记/pics/image-20200909151510570.png)

![image-20200909151524763](CUDA编程笔记/pics/image-20200909151524763.png)

![image-20200909151920345](CUDA编程笔记/pics/image-20200909151920345.png)

![image-20200909152000250](CUDA编程笔记/pics/image-20200909152000250.png)

![image-20200909152103010](CUDA编程笔记/pics/image-20200909152103010.png)

![image-20200909154141041](CUDA编程笔记/pics/image-20200909154141041.png)

![image-20200909155031327](CUDA编程笔记/pics/image-20200909155031327.png)

![image-20200909155136853](CUDA编程笔记/pics/image-20200909155136853.png)

![image-20200909155220657](CUDA编程笔记/pics/image-20200909155220657.png)



# 并行规约算法-二叉树算法

![image-20200909163244691](CUDA编程笔记/pics/image-20200909163244691.png)

![image-20200909163449361](CUDA编程笔记/pics/image-20200909163449361.png)

![image-20200909165200369](CUDA编程笔记/pics/image-20200909165200369.png)

![image-20200909165329387](CUDA编程笔记/pics/image-20200909165329387.png)

![image-20200909165452747](CUDA编程笔记/pics/image-20200909165452747.png)

![image-20200909180941615](CUDA编程笔记/pics/image-20200909180941615.png)

![image-20200909181314361](CUDA编程笔记/pics/image-20200909181314361.png)

一个Warp里有的线程执行加和操作，有的不执行，造成了同一个warp里线程没有执行相同的指令。所以效率很低。

一般的GPU理论带宽有几百GB/s，但是此种算法的带宽只有2.083GB/s。

![image-20200909181350728](CUDA编程笔记/pics/image-20200909181350728.png)

绿色表示处于活跃状态的线程。



# 规约算法 优化

![image-20200909181959012](CUDA编程笔记/pics/image-20200909181959012.png)

`s = 1`时，第0个线程访问0和1, 第1个线程访问2和3, 第`ceil(blockDim / 2)`个线程访问最后两个位置。

s = 2时， 第0个线程访问0和2, 第1个线程访问4和6, 第`ceil(ceil(blockDim / 2) / 2)个线程访问倒数-2和倒数的位置`

...

直到只剩1个线程。

![image-20200909192217142](CUDA编程笔记/pics/image-20200909192217142.png)

上图中橙色的圆圈表示线程。

![image-20200909192312840](CUDA编程笔记/pics/image-20200909192312840.png)

上图中绿色的表示活动的线程。

![image-20200909192657854](CUDA编程笔记/pics/image-20200909192657854.png)

同样的线程跨bank访问数据，容易降速。上述算法仍然有值得提升的空间。



# 规约算法 再次优化

![image-20200909192928900](CUDA编程笔记/pics/image-20200909192928900.png)

线程访问前半和后半部分的数据时，内存都是连续的

![image-20200909193358610](CUDA编程笔记/pics/image-20200909193358610.png)

![image-20200909193607862](CUDA编程笔记/pics/image-20200909193607862.png)



# 规约算法 改进全局内存访问

![image-20200911133353049](CUDA编程笔记/pics/image-20200911133353049.png)



# 规约算法 Warp内循环优化

![image-20200911135056250](CUDA编程笔记/pics/image-20200911135056250.png)

![image-20200911144347411](CUDA编程笔记/pics/image-20200911144347411.png)

因为一个warp里执行的相同的指令，所以`_syncthreads()`可以不加

![image-20200911150554843](CUDA编程笔记/pics/image-20200911150554843.png)

![image-20200911153850052](CUDA编程笔记/pics/image-20200911153850052.png)



# 并行规约算法 完全循环展开

![image-20200911154054656](CUDA编程笔记/pics/image-20200911154054656.png)

![image-20200911154935231](CUDA编程笔记/pics/image-20200911154935231.png)

![image-20200911160929391](CUDA编程笔记/pics/image-20200911160929391.png)

![image-20200911161131630](CUDA编程笔记/pics/image-20200911161131630.png)

![image-20200911161256140](CUDA编程笔记/pics/image-20200911161256140.png)



# 并行规约算法： 成功优化的关键

## 规约算法： 循环展开注解

![image-20200911164127559](CUDA编程笔记/pics/image-20200911164127559.png)

![image-20200911164147048](CUDA编程笔记/pics/image-20200911164147048.png)

编译器编译时会优化代码，所以下面的代码

![image-20200911164442533](CUDA编程笔记/pics/image-20200911164442533.png)

可能会被展开成一个表达式，进而造成结果的错误，所以我们要规避掉编译器对上述代码的自动优化

![image-20200911164550941](CUDA编程笔记/pics/image-20200911164550941.png)



# 完整并行规约算法

## CUDA程序优化

**![image-20200911180853347](CUDA编程笔记/pics/image-20200911180853347.png)**

 

![image-20200911181040902](CUDA编程笔记/pics/image-20200911181040902.png)

![image-20200911182312618](CUDA编程笔记/pics/image-20200911182312618.png)

![image-20200911182510432](CUDA编程笔记/pics/image-20200911182510432.png)

核函数用global修饰

![image-20200911182543024](CUDA编程笔记/pics/image-20200911182543024.png)

Host Memory: CPU内存

全局内存的访问注意对齐

![image-20200914111857999](CUDA编程笔记/pics/image-20200914111857999.png)





# 并行规约算法应用：内积

![image-20200914112152350](CUDA编程笔记/pics/image-20200914112152350.png)

![image-20200914112645428](CUDA编程笔记/pics/image-20200914112645428.png)



# CUDA程序优化技巧

### 最大化并行执行

![image-20200916180619653](CUDA编程笔记/pics/image-20200916180619653.png)

![image-20200916181155936](CUDA编程笔记/pics/image-20200916181155936.png)

**![image-20200916181351017](CUDA编程笔记/pics/image-20200916181351017.png)**

![image-20200916181624090](CUDA编程笔记/pics/image-20200916181624090.png)

![image-20200916181812632](CUDA编程笔记/pics/image-20200916181812632.png)

## 优化内存使用

![image-20200916182028843](CUDA编程笔记/pics/image-20200916182028843.png)