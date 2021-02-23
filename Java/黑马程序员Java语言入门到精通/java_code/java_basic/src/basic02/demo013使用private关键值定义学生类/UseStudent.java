package basic02.demo013使用private关键值定义学生类;

public class UseStudent
{
    public static void main(String[] args)
    {
        Student stu = new Student();
        stu.setName("Alice");
        stu.setAge(20);
        stu.setMale(false);

        System.out.println("Name: " + stu.getName() + ". Age: " + stu.getAge() + ". Male: " + stu.isMale());

        // this
        System.out.println(stu);
        stu.printThis();
    }
}
