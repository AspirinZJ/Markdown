package basic02.demo015定义一个标准的类;

public class UseStudent
{
    public static void main(String[] args)
    {
        Student stu = new Student();
        stu.setName("Alice");
        stu.setAge(20);
        System.out.println("Name: " + stu.getName() + ". Age: " + stu.getAge());

        Student stu2 = new Student("Bob", 21);
        System.out.println("Name: " + stu2.getName() + ". Age: " + stu2.getAge());
    }
}
