package basic02.demo034抽象方法和抽象类;

public class Cat extends Animal
{

    // 子类必须实现父类中的所有抽象方法
    @Override
    public void eat() { System.out.println("Cat eats fish."); }
}
