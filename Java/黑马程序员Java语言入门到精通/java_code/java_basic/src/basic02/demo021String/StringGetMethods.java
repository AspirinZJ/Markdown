/*
 * `public int length()`： 获取字符串的长度
 * `public String concat(String str)`： 将当前字符串和参数字符串拼接成为新的字符串返回，用+也可以
 * `public char charAt(int index)`：获取指定索引位置的单个字符
 * `public int indexOf(String str)`： 查找参数字符串在本字符串中首次出现的索引位置，没有返回-1
* */
package basic02.demo021String;

public class StringGetMethods
{
    public static void main(String[] args)
    {
        // length()
        System.out.println("Hello World!".length());

        // 拼接字符串concat()
        String str1 = "Hello ";
        String str2 = "World.";
        // 记住：字符串是常量， 要改变的化必定创建了新字符串
        String str3 = str1.concat(str2); // str1和str2都不改变， str3是新字符串

        System.out.println(str1); // Hello
        System.out.println(str2); // World.
        System.out.println(str3); // Hello World.


        // charAt()
        char ch = str3.charAt(1);
        System.out.println(ch);

        // indexOf()
        String original = new String("HelloWorld.HelloWorld.");
        int ind = original.indexOf("llo"); // 只查找第一次出现的位置
        System.out.println(ind);
        System.out.println(original.indexOf("abc")); // 没有返回-1
    }
}
