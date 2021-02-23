package basic02.demo028继承中成员方法的访问特点;

public class ExtendsMethod
{
    public static void main(String[] args)
    {
        Derived derived = new Derived();
        derived.methodBase();
        derived.methodDerived();

        // 创建的是new了子类对象，所哟优先用子类方法
        derived.method();
    }
}
