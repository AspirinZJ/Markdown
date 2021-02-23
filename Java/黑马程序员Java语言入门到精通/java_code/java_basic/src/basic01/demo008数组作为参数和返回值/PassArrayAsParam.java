// 将数组作为方法参数
package basic01.demo008数组作为参数和返回值;

public class PassArrayAsParam
{
    public static void main(String[] args)
    {
        int[] array = new int[]{1, 2, 3, 4};
        printIntArr(array); // 传递进去的是array的地址值
    }

    public static void printIntArr(int[] array)
    {
        System.out.println("printIntArr收到的方法参数是: ");
        System.out.println(array);

        System.out.println("method1: ");
        for (int i = 0; i < array.length; i++)
        {
            System.out.println(array[i]);
        }

        System.out.println("method2: ");
        for (int i : array) System.out.println(i);
    }
}
