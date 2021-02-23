package basic02.demo037接口;

public class MyInterfaceAbstractImpl implements MyInterfaceAbstract
{
    // 重写接口中所有抽象方法
    @Override
    public void methodAbs() { System.out.println("methodAbs"); }

    @Override
    public void methodAbs1() { System.out.println("methodAbs1"); }

    @Override
    public void methodAbs2() { System.out.println("methodAbs2"); }

    @Override
    public void methodAbs3() { System.out.println("methodAbs3"); }
}
