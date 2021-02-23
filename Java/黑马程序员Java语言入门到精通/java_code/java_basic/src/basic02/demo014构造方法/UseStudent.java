package basic02.demo014构造方法;

public class UseStudent
{
    public static void main(String[] args)
    {
        Student stu = new Student();
        Student stu2 = new Student("Alice", 20);
        System.out.println("Name: " + stu2.getName() + ". Age: " + stu2.getAge());
        stu2.setAge(21);
        System.out.println("Name: " + stu2.getName() + ". Age: " + stu2.getAge());
    }
}
