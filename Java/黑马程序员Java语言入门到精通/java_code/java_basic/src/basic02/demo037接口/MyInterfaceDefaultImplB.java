package basic02.demo037接口;

public class MyInterfaceDefaultImplB implements MyInterfaceDefault
{
    @Override
    public void methodAbs()
    {
        System.out.println("BBB");
    }

    // 重写接口中的默认方法
    @Override
    public void methodDefault()
    {
        System.out.println("B overrides default method.");
    }
}
