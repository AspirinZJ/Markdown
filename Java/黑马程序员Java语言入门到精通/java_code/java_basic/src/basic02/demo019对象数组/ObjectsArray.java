// 对象数组的使用
package basic02.demo019对象数组;

public class ObjectsArray
{
    public static void main(String[] args)
    {
        Person[] personArr = new Person[3];
        System.out.println(personArr[0]); // 数组引用数据初始化为null

        Person person1 = new Person("Alice", 20);
        Person person2 = new Person("Bob", 21);
        Person person3 = new Person("Charlie", 22);

        personArr[0] = person1; // 将person1中的地址值赋值到personArr中的0号位置
        personArr[1] = person2;
        personArr[2] = person3;

        System.out.println(personArr[0]); // 存放的是地址值

        System.out.println(personArr[0].getName());
    }
}
