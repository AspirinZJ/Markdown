/*
 * 题目：定义一个方法，把数组{1, 2, 3}按照指定格式拼接成一个字符串，格式参照如下：
 * [word1#word2#word3]
 * */
package basic02.demo021String.Questions;

public class Question1
{
    public static void main(String[] args)
    {
        int[] intArr = new int[]{1, 2, 3};
        String str = fromArrayToString(intArr);
        System.out.println(str);
    }

    public static String fromArrayToString(int[] arr)
    {
        String str = "[";
        for (int i = 0; i < arr.length; i++)
        {
            if (i != arr.length - 1) {str += "word" + arr[i] + "#";}
            else {str += "word" + arr[i] + "]";}
        }

        return str;
    }
}
