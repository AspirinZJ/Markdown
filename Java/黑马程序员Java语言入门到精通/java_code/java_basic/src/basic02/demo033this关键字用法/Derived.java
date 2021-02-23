/*
this关键字三种用法：
* 在本类成员方法中，访问本类的成员变量
* 在本类的成员方法中，访问本类的另一个成员方法
* 在本类的构造方法中，访问本类的另一个构造方法
  * 注意，this()调用也必须是构造方法中的第一个语句
  * 注意，super()调用和this()调用不能同时使用，因为他们两个必须是第一个语句
* */
package basic02.demo033this关键字用法;

public class Derived extends Base
{
    int num = 20;

    public Derived()
    {
        // super(); // 不再赠送，super()和this()只能调用一个
        this(10); // 本类的无参构造调用本类的有参构造
    }

    public Derived(int n) { }

    public void showNum()
    {
        int num = 10;
        System.out.println(num); // 局部变量
        System.out.println(this.num); // 本类中的成员变量
        System.out.println(super.num); // 父类中的成员变量
    }

    public void methodA() {System.out.println("A");}

    public void methodB()
    {
        this.methodA(); // 访问本类中的另一个成员方法
        System.out.println("B");
    }
}
