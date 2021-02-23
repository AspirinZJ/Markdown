package basic02.demo037接口;

public interface MyInterfaceDefault
{
    // 抽象方法
    public abstract void methodAbs();

    // 新添加了一种抽象方法
    // public abstract void methodAbs2();

    // 新添加的方法改成默认方法
    public default void methodDefault()
    {
        System.out.println("New added default method.");
    }
}
