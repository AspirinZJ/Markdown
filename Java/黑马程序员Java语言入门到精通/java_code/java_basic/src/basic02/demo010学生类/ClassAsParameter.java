// 类作为方法参数
// 类作为方法的参数传递的是地址值
// 与c++不同，c++会调用拷贝构造函数
package basic02.demo010学生类;

public class ClassAsParameter
{
    public static void main(String[] args)
    {
        Student stu = new Student();
        stu.m_name = "Alice";
        stu.m_age = 18;
        method(stu); // 传递进去的参数是地址值
    }

    public static void method(Student stu)
    {
        System.out.println(stu.m_name);
        System.out.println(stu.m_age);
    }
}
