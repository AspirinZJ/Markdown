package basic02.demo022static关键字;

public class MyClass
{
    int num;
    static int staticNum;

    public void method() {
        System.out.println("common method.");
        System.out.println(num); // 成员方法可以访问成员变量
        System.out.println(staticNum); // 成员方法可以访问静态变量
    }

    public static void staticMethod() {System.out.println("static method");
        System.out.println(staticNum); // 静态方法可以访问静态变量
        // System.out.println(num); // ~~~~错误~~~~~，静态方法不能直接访问非静态变量
        // System.out.println(this); // ~~~静态方法中不能使用this关键字~~
    }
}
