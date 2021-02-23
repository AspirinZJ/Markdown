package basic02.demo027区分子类方法中重名的三种变量;

public class Derived extends Base
{
    int num = 20; // 子类变量

    public void methodDerived()
    {
        int num = 30; // 局部变量
        System.out.println(num); // 局部变量
        System.out.println(this.num); // 子类变量
        System.out.println(super.num); // 父类变量
    }
}
