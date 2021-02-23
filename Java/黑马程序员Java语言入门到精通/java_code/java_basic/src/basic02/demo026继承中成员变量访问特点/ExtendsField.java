/*
在继承关系中，如果成员变量重名
直接通过子类对象访问成员变量：等号左边是谁，就优先用谁，没有则向上找
间接通过成员方法访问成员变量：该方法属于谁，就优先用谁，没有则向上找
* */
package basic02.demo026继承中成员变量访问特点;

public class ExtendsField
{
    public static void main(String[] args)
    {
        Base base = new Base(); // 创建基类
        System.out.println(base.baseNum);

        Derived derived = new Derived();
        System.out.println(derived.baseNum);
        System.out.println(derived.derivedNum);

        // 重名成员变量
        // 直接访问
        System.out.println(base.num); // 优先用基类
        System.out.println(derived.num); // 优先用派生类

        derived.derivedMethod(); // 这个方法是子类的，优先用子类的num，不需要向上找
        derived.baseMethod(); // 这个方法是父类定义的，使用父类的num
    }
}
