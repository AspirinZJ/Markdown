// 面向对象三大特性：encapsulation, polymorphism, and inheritance
// 封装就是将一些细节信息隐藏，对于外界不可见
// 关键字private也是一种封装
package basic02.demo012面向对象三大特性之封装;

public class Encapsulation
{
    public static void main(String[] args)
    {
        int[] array = {1, 2, 3, 4, 5};

        int max = getMax(array);
        System.out.println(max);
    }

    public static int getMax(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; ++i) if (max < array[i]) max = array[i];
        return max;
    }
}
