/*
程序当中直接写上的双引号字符串，就在字符串常量池中
对于基本类型来说， `==`是进行值的比较
对于引用类型来说，`==`是进行地址的比较
* */
package basic02.demo021String;

public class StringPoolDemo
{
    public static void main(String[] args)
    {
        String str1 = "Hello"; // 字符串对象，在字符串常量池中, 保存的是一个地址值
        String str2 = "Hello";

        char[] charArr = {'H', 'e', 'l', 'l', 'o'};
        String str3 = new String(charArr);

        System.out.println(str1 == str2); // true, 地址相同
        System.out.println(str3 == str2); // false, 地址不同
        System.out.println(str1 == str3); // false
    }
}
