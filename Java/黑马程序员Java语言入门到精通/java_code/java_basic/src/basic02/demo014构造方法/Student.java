/* 构造方法
格式：`public 类名称(参数列表) {方法体}`
注意：
1. 构造方法名称和类名完全相同
2. 构造方法没有返回类型， 连void也没有
3. 如果没有编写任何构造方法，那么编译器将会默认提供一个构造方法， 没有参数，方法体什么事情都不做
4. 一旦编写了至少一个构造方法，那么编译器将不再提供构造方法
* */
package basic02.demo014构造方法;

public class Student
{
    private String name;
    private int age;

    public Student() {System.out.println("Student default Constructor");}

    public Student(String name, int age)
    {
        System.out.println("Student Constructor with parameters.");
        this.name = name;
        this.age = age;
    }

    public String getName() { return this.name;}

    public void setName(String name) { this.name = name;}

    public int getAge() { return this.age;}

    public void setAge(int age) { this.age = age;}
}
