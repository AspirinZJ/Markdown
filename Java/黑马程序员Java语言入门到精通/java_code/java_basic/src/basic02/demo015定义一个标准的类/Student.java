/*
一个标准的类通常满足：
1. 所有的成员变量都要使用private修饰
2. 为每一个成员变量编写Getter/Setter
3. 编写一个无参数构造方法
4. 编写一个全参数的构造方法

这样标准的类也叫Java Bean*/
package basic02.demo015定义一个标准的类;

public class Student
{
    String name;
    int age;

    public Student() { }

    public Student(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getAge()
    {
        return age;
    }

    public void setAge(int age)
    {
        this.age = age;
    }
}
