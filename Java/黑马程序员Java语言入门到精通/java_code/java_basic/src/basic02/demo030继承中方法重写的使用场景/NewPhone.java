package basic02.demo030继承中方法重写的使用场景;

// 定义一个新手机类，使用老手机作为基类
public class NewPhone extends Phone
{
    @Override
    public void showIncomingInfo()
    {
        super.showIncomingInfo(); // 父类已经有的功能
        System.out.println("the picture of the caller: ");
    }
}
