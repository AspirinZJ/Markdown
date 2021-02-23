// 使用动态初始化时，元素有默认值，为：
//* 如果是整型，默认为0
//* 如果是浮点型，默认为0.0
//* 如果是char型，默认为'\u0000'
//* 如果是boolean型，默认为false
//* 如果是引用类型，默认为null
package basic01.demo005数组使用;

public class ArrayUsage
{
    public static void main(String[] args)
    {
        int[] intArr = new int[]{10, 20, 30}; // 静态初始化省略格式
        System.out.println(intArr); // [I@77459877
        // 直接打印数组名称，打印的是数组对应的内存地址hash值. [表示是数组， I表示int

        System.out.println(intArr[0]); // 访问数组元素


        int[] intArr2 = new int[3]; // 动态初始化一个数组
        for (int i = 0; i < 3; i++) { intArr2[i] = i; }
        for (int i = 0; i < 3; i++) { System.out.println(intArr2[i]); }
    }
}
