package basic02.demo028继承中成员方法的访问特点;

public class Derived extends Base
{
    public void methodDerived() {System.out.println("methodDerived calling");}

    public void method() {System.out.println("derived class same name method calling.");}
}
