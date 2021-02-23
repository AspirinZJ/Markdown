// 面向对象： 当实现一个功能的时候，每一个具体的步骤都要亲历亲为， 详细处理每一个细节
// 面向过程： 当实现一个功能的时候，不关系具体的步骤，而是找一个已经具有该功能的对象来操作
package basic02.demo009面向对象和面向过程打印数组;

import java.util.Arrays;

public class PrintArray
{
    public static void main(String[] args)
    {
        int[] array = new int[]{1, 2, 3, 4, 5};

        // 面向过程打印
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) System.out.print(array[i] + ", ");
        System.out.println(array[array.length-1] + "]");

        // 面向对象打印
        // 使用JDK给提供好的Arrays类
        // 其中有一个toString方法，直接把数组作为String输出
        System.out.println(Arrays.toString(array));
    }
}
