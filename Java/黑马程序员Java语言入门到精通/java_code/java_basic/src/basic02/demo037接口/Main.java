/*
接口就是一种公共的规范标准， 只要符合标准就可以大家通用

==接口是一种引用数据类型==， 接口中最重要的内容，就是其中的抽象方法

定义接口格式：
public interface 接口名称
{
...
}

备注：
* `无论对于类还是对于接口，生成的字节码文件.java-->.class`
* 如果是Java7,接口中可以包含：
  * 常量
  * 抽象方法
* 如果是Java8,还可以额外包含有：
  * 默认方法
  * 静态方法
* 如果是Java9,还可以额外包含：
  * 私有方法

定义接口抽象方法：`public abstract 返回值类型 方法名称(参数列表);`

接口使用步骤：
* 接口不能直接使用，必须有一个“实现类”来“实现”该接口， ==实现类命名推荐`接口名Impl， 如MyInterfaceImpl`==
  * 格式：`public class 实现类名称 implements 接口名称 {..}`
* 接口的实现类必须重写(实现)接口中所有的抽象方法
* 创建实现类的对象进行使用

注意事项：
* 接口中的抽象方法，修饰符必须是两个固定的关键字: public abstract，这两个关键字可以选择性省略
* 如果实现类没有重写全部的抽象方法，那么这个实现类就必须是抽象类



从Java8开始，允许接口定义默认方法，默认方法可以有方法体， 格式：
public default 返回值类型 方法名称(参数列表)
{方法体}

接口中的默认方法，可以解决接口升级的问题，如果接口升级，如新添加了一个抽象方法，那么之前接口所有的实现类都要改动重写新的抽象方法，不便于维护，所以可以为接口提供带有方法体的默认方法
默认方法会被实现类继承

注意：
* 接口的默认方法可以通过接口实现类对象直接调用
* 接口的默认方法也可以被接口实现类进行重写
* */
package basic02.demo037接口;

public class Main
{
    public static void main(String[] args)
    {
        // 用实现类调用接口
        MyInterfaceAbstractImpl impl = new MyInterfaceAbstractImpl();

        impl.methodAbs();
        impl.methodAbs1();
        impl.methodAbs2();
        impl.methodAbs3();
        System.out.println("------------");

        MyInterfaceDefaultImplA implA = new MyInterfaceDefaultImplA();
        implA.methodAbs();
        implA.methodDefault(); // 调用默认方法，如果实现类没有，则向上从接口中找

        MyInterfaceDefaultImplB implB = new MyInterfaceDefaultImplB();
        implB.methodAbs();
        implB.methodDefault(); // 调用默认方法，B重写了默认方法，调用B的
    }
}
