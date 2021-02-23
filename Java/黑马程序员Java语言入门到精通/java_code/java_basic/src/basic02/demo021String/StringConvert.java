/*
 * 字符串转换方法：
 * `public char[] toCharArray()`： 将当前字符串拆分成字符数组返回
 * `public byte[] getBytes()`： 获得当前字符串底层的字节数据
 * `public String replace(CharSequence oldString, CharSequence newString)`： 将所有出现的老字符串替换为新字符串，返回替换之后的结果为新的字符串
 * */
package basic02.demo021String;

public class StringConvert
{
    public static void main(String[] args)
    {
        // 转换成为字符数组, toCharArray()
        char[] charArr = "Hello".toCharArray();

        // 转换成为字节数组， getBytes()
        byte[] byteArr = "Hello".getBytes();
        for (byte i : byteArr) { System.out.print(i); }

        // 替换 replace()
        String str1 = "HelloJava.";
        String str2 = str1.replace("a", "e"); // 一定要用新的字符串接收
        System.out.println(str1);
        System.out.println(str2);

    }
}
