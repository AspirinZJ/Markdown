package basic02.demo026继承中成员变量访问特点;

public class Derived extends Base
{
    int derivedNum = 20;
    int num = 200;

    public void derivedMethod() {System.out.println(num);} // 因为本类中有num，所以用本类的num
}
