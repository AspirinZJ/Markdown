/*
* 字符串截取方法：
* `public String substring(int index)`：从index位置开始截取到字符串末尾，返回==新字==符串
* `public String substring(int begin, int end)`： 截取从`[begin, end)`区间的字符串，返回新的字符串，左闭右开
* */
package basic02.demo021String;

public class SubstringDemo
{
    public static void main(String[] args)
    {
        // substring(int index)
        String str1 = "HelloWorld.";
        String str2 = str1.substring(4);
        System.out.println(str2);

        // substring(int begin, int end)
        String str3 = str1.substring(1, 4);
        System.out.println(str3);


        // 下面这种写法，字符串的内容仍然是没有改变的
        // 下面有两个字符串， “hello" 和 "java"
        // strA中保存的是地址值
        // 本来的是"hello"的地址
        // 后来的是"java"的地址
        String strA = "hello";
        strA = "java";
        System.out.println(strA);
    }
}
