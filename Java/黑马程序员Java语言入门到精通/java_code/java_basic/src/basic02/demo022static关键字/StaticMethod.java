// 如果一个成员方法使用类static关键字， 那么这就成了静态方法，静态方法不属于对象， 而属于类
//* 如果没有static关键字，那么要先创建对象，再通过对象使用
//* static修饰的静态方法，可以通过对象调用，也可以通过类名直接调用（不需要创建对象再调用）
//* 静态方法中不能用this， 因为this代表当前对象

package basic02.demo022static关键字;

public class StaticMethod
{
    public static void main(String[] args)
    {
        MyClass obj = new MyClass();
        obj.method(); // 普通方法必须先创建对象再通过对象调用

        // 静态方法调用，推荐使用`类名称.静态方法调用`
        obj.staticMethod(); // 不推荐
        MyClass.staticMethod(); // 推荐使用, 不需要创建对象也能使用

        // 对于本类当中的静态方法，可以省略类名称
        myMethod();
        StaticMethod.myMethod();
    }

    public static void myMethod() {System.out.println("myMethod");}
}
