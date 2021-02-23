/*
java.util.Arrays是一个与数组相关的工具类，里面提供了大量的静态方法，用来实现数组常见的操作
`public static String toString(数组)`：减参数数组变成字符串，按照默认格式：[元素1, 元素2, ...]
`public static void sort(数组)`： 按照默认升序堆数组的元素进行排序
* 如果是数值，sort按照升序排序
* 如果是字符串，sort按照字母升序
* 如果是自定义类型，那么这个自定义类需要有Comparable或者Comparator接口的支持
* */
package basic02.demo023Arrays工具类;

import java.util.Arrays;

public class ArraysDemo
{
    public static void main(String[] args)
    {
        int[] intArr = {9, 2, 3, 6, 2};
        // 将int[]  数组按照默认格式变成字符串
        String str = Arrays.toString(intArr);
        System.out.println(str);

        Arrays.sort(intArr); // 对数组按照默认升序排序
        System.out.println(Arrays.toString(intArr));

        String[] strArr = {"zde", "3dg", "ige", "xert"};
        Arrays.sort(strArr);
        System.out.println(Arrays.toString(strArr));
    }
}
