// 题目：生成6个1～33之间的随机int数，添加到集合，并遍历集合
package basic02.demo020ArrayList;


import java.util.ArrayList;
import java.util.Random;

public class ArrayListQuestion1
{
    public static void main(String[] args)
    {
        ArrayList<Integer> intList = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < 6; i++)
        {
            intList.add(random.nextInt(33) + 1);
        }

        for (int i : intList) { System.out.println(i); }

    }
}
