package basic02.demo022static关键字;

public class StaticField
{
    public static void main(String[] args)
    {
        Student stu1 = new Student("Alice", 19);
        System.out.println("stu1 name: " + stu1.getName() + ". age: " + stu1.getAge() + ". id: " + stu1.getId());

        Student stu2 = new Student("Bob", 20);
        System.out.println("stu2 name: " + stu2.getName() + ". age: " + stu2.getAge() + ". id: " + stu2.getId());

        // stu1.classroom = "classroom1";
        System.out.println("stu1 classroom: " + stu1.classroom + ". stu2 classroom: " + stu2.classroom);
        System.out.println(Student.classroom); // 用类名访问static变量
    }
}
