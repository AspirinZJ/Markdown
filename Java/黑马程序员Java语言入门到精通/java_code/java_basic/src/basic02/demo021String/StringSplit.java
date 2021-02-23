/*
* `public String[] split(String regex)`：按照正则表达式参数的规则，将字符串切分成若干部分
 * split方法的参数是正则表达式, `.`必须用`\\.`表示*/
package basic02.demo021String;

public class StringSplit
{
    public static void main(String[] args)
    {
        String str1 = "aaa,bbb,ccc";
        String[] strArr1 = str1.split(",");
        for (String str : strArr1) {System.out.println(str);}

        String str2 = "aaa bbb ccc";
        String[] strArr2 = str2.split(" ");
        for (String str : strArr2) {System.out.println(str);}

        String str3 = "aaa.bbb.ccc";
        String[] strArr3 = str3.split("\\."); // split方法的参数是正则表达式, .必须用\\.表示
        for (String i : strArr3) {System.out.println(i);}
    }
}
