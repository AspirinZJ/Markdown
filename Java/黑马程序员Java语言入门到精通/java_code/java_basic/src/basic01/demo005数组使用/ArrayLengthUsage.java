// 获取数组长度
// *格式： 数组名称.length
// 数组一旦创建，程序运行期间，长度不可改变
package basic01.demo005数组使用;

public class ArrayLengthUsage
{
    public static void main(String[] args)
    {
        int[] arrayA = new int[]{1, 2, 3};
        System.out.println(arrayA.length);

        arrayA = new int[5]; // 其实是两个数组
    }
}
