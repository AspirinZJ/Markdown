package basic02.demo012面向对象三大特性之封装;

// 用private将需要保护的成员变量修饰

public class Person
{
    String name;
    private int age; // private修饰的成员变量只有本类范围内能访问

    public void showPerson() { System.out.println("My name is: " + this.name + ". My age is: " + this.age);}

    // Getter方法, 必须叫getXxx, 不能有参数，返回值类型和变量类型相同
    public int getAge() { return this.age;}

    // Setter方法, 必须叫setXxx, 不能有返回值，参数与变量类型相同
    public void setAge(int age)
    {
        if (age < 100 && age >= 0) {this.age = age;}
        else
        {
            System.out.println("Invalid age!");
        }
    }
}
