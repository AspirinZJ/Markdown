/*Java程序中所有的字符串字面值如"abc"都作为String类的实例实现
* 程序中所有“”包括的字符串都是String类的对象，就算没有new，也是
* 字符串是常量， 值在创建后不可以更改
* 正是因为字符串不可改变，所以字符串是可以共享使用的
* 字符串效果上相当于是char[] 型字符数组，但是底层上是byte[] 字节数组

String的3种常用构造方法+1种直接创建：
* `public String()`，创建一个空白字符串，不含有任何内容
* `public String(char[] array)`， 根据字符数组内容创建字符串
* `public String(byte[] array)`，根据字节数组的内容创建字符串
* `String str = "字符串"`直接用双引号创建
* */

package basic02.demo021String;

public class StringDemo
{
    public static void main(String[] args)
    {
        String str1 = new String(); // 构造空字符串
        // String str1 = "";
        System.out.println("str1: " + str1);

        char[] charArr = {'A', 'B', 'C'};
        String str2 = new String(charArr); // char[] array 构造
        System.out.println("str2: " + str2);

        byte[] byteArr = {65, 66, 67};
        String str3 = new String(byteArr); // byte[] arr 构造
        System.out.println("str3: " + str3);

        String str4 = "Hello"; // 没有new也是字符串对象
    }
}
