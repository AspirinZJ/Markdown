// 对于基本类型中的boolean型，Getter方法一定要写成isXxx的形式，而Setter规则不变
package basic02.demo013使用private关键值定义学生类;

public class Student
{
    private int age;
    private String name;
    private boolean male;    // is male

    public void setName(String name) { this.name = name;}
    public String getName() { return this.name;}

    public void setAge(int age) { this.age = age;}
    public int getAge() { return this.age;}

    public void setMale(boolean sex) {this.male = sex;}
    public boolean isMale() { return this.male;}

    public void printThis() { System.out.println(this);}
}
