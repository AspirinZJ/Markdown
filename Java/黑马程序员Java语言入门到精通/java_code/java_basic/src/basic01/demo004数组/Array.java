// 数组的特点：
// 1. 数组是一种引用数据类型
// 2. 数组的长度在运行期间不可改变

// 数组的初始化：
// 1. 动态初始化：指定长度. 格式： 数据类型[] 数组名称 = new 数据类型[数组长度];
// 2. 静态初始化：指定内容. 格式： 数据类型[] 数组名称 = new 数据类型[] {element1, element2, ...};
// 静态初始化的数组长度会被自动推算出
// 静态初始化的省略格式：数据类型[] 数组名称 = {ele1, ele2, ...};
package basic01.demo004数组;

public class Array
{
    public static void main(String[] args)
    {
        // 1. 动态初始化
        int[] intArr = new int[100];
        String[] strArr = new String[5];

        // 2. 静态初始化
        int[] intArr2 = new int[]{1, 2, 3, 4};
        String[] strArr2 = new String[]{"Hello", "World"};

        // 静态初始化和动态初始化能被拆分为两部
        int[] intArr4;
        intArr4 = new int[]{1, 2, 3};
        int[] intArr6;
        intArr6 = new int[10];

        // 静态初始化省略格式
        int[] intArr3 = {1, 2, 3};

        // 静态初始化一旦使用省略格式，就不能拆分成两部
//        int[] intArr7;
//        intArr7 = {1, 2, 3};
    }
}
