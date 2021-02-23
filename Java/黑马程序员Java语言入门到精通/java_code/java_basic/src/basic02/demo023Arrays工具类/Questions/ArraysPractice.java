// 题目：利用Arrays的API， 将一个随机字符串中所有字符升序排列，并倒序打印
package basic02.demo023Arrays工具类.Questions;

import java.util.Arrays;

public class ArraysPractice
{
    public static void main(String[] args)
    {
        String str = "fdsidsFNjkIJF93eje";
        char[] chArr = str.toCharArray();
        Arrays.sort(chArr); // 对数组升序排序

        //倒序遍历
        // ～～～～～～～～～～～～～～～～～～～～～～～
        // Intellij Idea 输入技巧,输入chArr.fori会自动生成正序代码，输入chArr.forr自动生成倒序代码
        // ～～～～～～～～～～～～～～～～～～～～～～～
        for (int i = chArr.length - 1; i >= 0; i--) { System.out.print(chArr[i]); }

    }
}
