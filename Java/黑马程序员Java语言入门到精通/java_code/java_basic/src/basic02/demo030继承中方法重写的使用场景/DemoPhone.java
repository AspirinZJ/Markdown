package basic02.demo030继承中方法重写的使用场景;

public class DemoPhone
{
    public static void main(String[] args)
    {
        Phone oldPhone = new Phone();
        oldPhone.call();
        oldPhone.sendMessage();
        oldPhone.showIncomingInfo();
        System.out.println("-------------");

        NewPhone newPhone = new NewPhone();
        newPhone.call();
        newPhone.sendMessage();
        newPhone.showIncomingInfo();
    }
}
