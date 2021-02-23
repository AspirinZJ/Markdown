package basic02.demo034抽象方法和抽象类;

public class Main
{
    public static void main(String[] args)
    {
        // Animal animal = new Animal(); // 错误，不能直接创建抽象类对象
        Cat cat = new Cat();
        cat.eat();
    }
}
