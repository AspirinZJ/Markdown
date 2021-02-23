/*
* 题目：输入一个字符串，统计其中各种字符出现的次数
* 种类有： 大写字母， 小写字母， 数字，其他
* */
package basic02.demo021String.Questions;

import java.util.Scanner;

public class Question2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please input a string:");
        String strInput = sc.next();

        int upperCount = 0;
        int lowerCount = 0;
        int digitCount = 0;
        int othersCount = 0;

        char[] charArr = strInput.toCharArray();

        for (char i : charArr)
        {
            if (i >= 'A' && i <= 'Z') { upperCount++;}
            else if (i >= 'a' && i <= 'z') { lowerCount++;}
            else if (i >= '0' && i <= '9') { digitCount++;}
            else {othersCount++;}
        }

        System.out.println("Upper number: " + upperCount);
        System.out.println("Lower number: " + lowerCount);
        System.out.println("Digit number: " + digitCount);
        System.out.println("Others number: " + othersCount);
    }
}
