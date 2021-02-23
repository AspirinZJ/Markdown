package basic02.demo022static关键字;

public class UseStaticBlock
{
    public static void main(String[] args)
    {
        StaticBlock sb = new StaticBlock();
        StaticBlock sb2 = new StaticBlock(); // 静态代码块只会执行一次
    }
}
