/*
 使用一个类步骤：
 1. 导包： import 包名称.类名称;
    对于和当前类属于同一个包的情况，可以省略导包语句
 2. 创建： 类名称 对象名称 = new 类名称();
 3. 使用： 对象名.成员变量名， 对象名.成员方法名()

 注意： 如果成员变量没哟进行赋值，将会有默认值，规则和数组一样
*/

package basic02.demo010学生类;

// 1. 导包
import basic02.demo010学生类.Student;

public class UseStudentClass
{
    public static void main(String[] args)
    {
        // 2. 创建
        Student stu = new Student();

        // 3. 使用
        System.out.println(stu.m_name);
        System.out.println(stu.m_age);
        stu.eat();
        stu.m_name = "Alice";
        System.out.println(stu.m_name);
    }
}
