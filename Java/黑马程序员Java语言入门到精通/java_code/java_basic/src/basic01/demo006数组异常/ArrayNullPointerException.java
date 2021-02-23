// 数组空指针异常: NullPointerException
// 解决： new
package basic01.demo006数组异常;

public class ArrayNullPointerException
{
    public static void main(String[] args)
    {
        // 所有的引用类型变量都可以赋值为null
        int[] array = null;
        System.out.println(array[0]);
    }
}
