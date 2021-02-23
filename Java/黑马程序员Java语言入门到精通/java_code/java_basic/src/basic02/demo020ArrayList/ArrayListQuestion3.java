/*
 * 题目：用一个大集合存入20个随机数字，然后筛选其中的偶数元素放到小集合中
 * 要求使用自定义的方法来实现筛选*/
package basic02.demo020ArrayList;

import java.util.ArrayList;
import java.util.Random;

public class ArrayListQuestion3
{
    public static void main(String[] args)
    {
        ArrayList<Integer> intList = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < 20; i++)
        { intList.add(random.nextInt(101)); }

        ArrayList<Integer> evenLst = getEvenList(intList);

        for (int i : evenLst) { System.out.println(i);}
    }

    // 筛选ArrayList中的偶数
    public static ArrayList<Integer> getEvenList(ArrayList<Integer> lst)
    {
        ArrayList<Integer> evenLst = new ArrayList<>();
        for (int i : lst) { if (0 == i % 2) {evenLst.add(i);} }

        return evenLst;
    }
}
