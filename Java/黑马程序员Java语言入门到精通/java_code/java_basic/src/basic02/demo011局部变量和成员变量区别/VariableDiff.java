// 成员变量和局部变量的区别：
//1. 定义的位置不同： 局部变量在方法内部，成员变量在方法外部，直接写在类内
//2. 作用域不同： 局部变量只有方法中可以使用，成员变量整个类可以使用
//3. 默认值不同：局部变量没有默认值，使用必须手动赋值，成员变量有默认值，默认值规则和数组相同
//4. 内存位置不同：局部变量在栈内存，成员变量在堆内存
//5. 声明周期不同：局部变量随着方法压栈诞生随着方法弹栈消失，成员变量随着对象创建而诞生随着对象被垃圾回收消失
package basic02.demo011局部变量和成员变量区别;

public class VariableDiff
{
    String name; // 成员变量

    public void methodA()
    {
        int num = 20; // 局部变量
        System.out.println(num);
        System.out.println(name);
    }

    public void methodB(int param) // param是局部变量
    {
        // System.out.println(num); // 错误
        System.out.println(name);
        int age;
        // System.out.println(age); // 不赋值的局部变量无法使用
        System.out.println(param); // 参数在方法调用时必然会被赋值，所以可以使用
    }
}
