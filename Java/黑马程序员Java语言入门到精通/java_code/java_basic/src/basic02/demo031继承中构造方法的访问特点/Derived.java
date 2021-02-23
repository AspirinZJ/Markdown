package basic02.demo031继承中构造方法的访问特点;

public class Derived extends Base
{
    public Derived()
    {
        // 父类的构造方法调用必须是子类构造方法中的第一个语句
        //super(); // 默认隐含的父类的默认构造方法
        super(20); // 调用父类重载的构造方法

        System.out.println("Derived constructor.");
    }
}
