/*
区分子类方法中重名的三种变量（父类、子类、局部）：
* 局部变量：直接写
* 子类成员变量：this.成员变量
* 父类成员变量：super.成员变量
* */
package basic02.demo027区分子类方法中重名的三种变量;

public class ExtendsSameNameField
{
    public static void main(String[] args)
    {
        Derived derived = new Derived();
        derived.methodDerived();
    }
}