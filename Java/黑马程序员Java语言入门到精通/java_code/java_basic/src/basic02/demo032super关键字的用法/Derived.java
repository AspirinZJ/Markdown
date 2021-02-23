/*
super关键字的用法：
* 在子类的成员方法中，访问父类的成员变量
* 在子类成员方法中，访问父类的成员方法
* 在子类构造方法中，访问父类的构造方法
* */
package basic02.demo032super关键字的用法;

public class Derived extends Base
{
    int num = 20;

    public Derived() {super();} // 访问父类的构造方法

    public void methodDerived() {System.out.println(super.num);} // 访问父类的成员变量

    public void method() {super.method();} // 访问父类的成员方法
}
