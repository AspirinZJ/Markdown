package basic02.demo022static关键字;

public class Student
{
    static String classroom;
    private static int idCounter = 0; // 每当new一个新对象的时候， idCounter++
    private int id;
    private String name;
    private int age;

    public Student() { this.id = ++idCounter;}

    public Student(String name, int age)
    {
        this.name = name;
        this.age = age;
        this.id = ++idCounter;
    }

    public String getName() { return name; }

    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }

    public void setAge(int age) { this.age = age; }

    public int getId() { return id; }

    public void setId(int id) { this.id = id; }
}
