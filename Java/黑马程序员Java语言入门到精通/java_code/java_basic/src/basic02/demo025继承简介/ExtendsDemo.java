/*
关系： 子类和父类： 子类就是父类， is-a， 如老师就是员工

格式：
public class 父类{}
public class 子类 extends 父类 {}
* */
package basic02.demo025继承简介;

public class ExtendsDemo
{
    public static void main(String[] args)
    {
        Teacher teacher = new Teacher(); // 创建了一个子类对象
        teacher.method();

        TeachingAssistent ta = new TeachingAssistent();
        ta.method();
    }
}
