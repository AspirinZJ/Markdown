package basic02.demo035抽象类和抽象方法注意事项;

public class Derived extends Base
{
    public Derived() {
        // super(); 默认隐藏赠送的父类构造方法
        System.out.println("Derived constructor.");}

    @Override
    public void eat() { System.out.println("Eat.");}
}
