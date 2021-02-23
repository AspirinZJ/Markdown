// 类作为方法的返回值
// 返回的是地址，与c++不同， c++会调用拷贝构造函数
package basic02.demo010学生类;

public class ClassAsReturn
{
    public static void main(String[] args)
    {
        Student stu = getStudent();
        System.out.println(stu.m_age);
        System.out.println(stu.m_name);
    }

    public static Student getStudent()
    {
        Student stu = new Student();
        stu.m_name = "Default";
        stu.m_age = 0;
        return stu;
    }
}
