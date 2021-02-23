// 将数组元素反转，要求不能使用新数组，就用原来的数组
package basic01.demo007数组倒序;

public class ReverseArray
{
    public static void main(String[] args)
    {
        int[] array = new int[]{1, 2, 3, 4, 5, 6, 7};

        for (int j : array) System.out.println(j);

        for (int head = 0, tail = array.length - 1; head < tail; ++head, --tail)
        {
            int tmp = array[head];
            array[head] = array[tail];
            array[tail] = tmp;
        }

        for (int i : array) System.out.println(i);
    }
}
