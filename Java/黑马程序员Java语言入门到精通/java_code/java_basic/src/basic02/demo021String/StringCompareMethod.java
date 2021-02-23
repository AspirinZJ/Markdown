/*
 *
 * */
package basic02.demo021String;

public class StringCompareMethod
{
    public static void main(String[] args)
    {
        // equals()
        String str1 = "Hello";
        String str2 = "Hello";
        char[] charArr = {'H', 'e', 'l', 'l', 'o'};
        String str3 = new String(charArr);

        System.out.println(str1.equals(str2));
        System.out.println(str1.equals(str3));
        System.out.println(str1.equals("Hello"));
        System.out.println("Hello".equals(str2));

        String str4 = "abc"; // 如果将“abc"换成null， str4.equals("abc")将会报错，NullPointerException
        //推荐
        System.out.println("abc".equals(str4));
        // 不推荐
        System.out.println(str4.equals("abc"));

        // String str5 = null;
        // System.out.println(str5.equals("abc")); // 错误


        // equalsIgnoreCase()
        System.out.println("abc".equalsIgnoreCase("AbC"));
    }
}