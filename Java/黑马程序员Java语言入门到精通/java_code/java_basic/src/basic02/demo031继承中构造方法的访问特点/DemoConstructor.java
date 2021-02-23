/*
继承中，父子类构造方法的访问特点：
* 子类的构造方法之中有默认隐含的`super()调用`， 什么都没写，则默认存在，所以一定先调用父类构造再调用子类构造， 此时如果父类没有无参构造函数，不写会报错
* 可以通过`super`关键字，来子类构造调用父类重载构造
* super的父类构造调用必须是子类构造方法的第一个语句
* 子类构造方法中不能调用多个父类构造方法
* 子类必须调用父类构造方法，不写则赠送父类默认构造方法，写了则用写的指定的父类的构造方法
* */
package basic02.demo031继承中构造方法的访问特点;

public class DemoConstructor
{
    public static void main(String[] args)
    {
        Derived derived = new Derived();
    }
}
