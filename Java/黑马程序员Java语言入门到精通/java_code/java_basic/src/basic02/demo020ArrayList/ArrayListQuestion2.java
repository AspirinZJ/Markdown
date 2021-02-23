/*
 * 定于以指定格式打印集合的方法，ArrayList作为参数，使用{}括起来集合， 使用@分割每个元素
 * 格式参照： {元素1@元素2@...}*/
package basic02.demo020ArrayList;

import java.util.ArrayList;

public class ArrayListQuestion2
{
    public static void main(String[] args)
    {
        ArrayList<String> strList = new ArrayList<>();
        strList.add("Hello");
        strList.add("World");
        strList.add("Java");

        printArrayList(strList);
    }

    public static void printArrayList(ArrayList<String> lst)
    {
        System.out.print("{");
        for (int i = 0; i < lst.size() - 1; i++)
        { System.out.print(lst.get(i) + "@"); }

        System.out.print(lst.get(lst.size() - 1) + "}");
    }
}
