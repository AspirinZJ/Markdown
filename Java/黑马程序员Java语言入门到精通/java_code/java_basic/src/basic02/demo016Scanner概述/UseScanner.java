// Scanner概述
//引用类型的一般使用步骤：
//1. 导包: import 包路径.类名称，如果处于同一个包，可以省略导入语句, 只有java.lang包下的内容不需要导包
//2. 创建: 类名称 对象名 = new 类名称();
//3. 使用
package basic02.demo016Scanner概述;

// 1. 导包
import java.util.Scanner;

public class UseScanner
{
    public static void main(String[] args)
    {
        // 2. 创建
        Scanner sc = new Scanner(System.in); // System.in代表从键盘进行输入

        // 3. 使用
        System.out.println("Input an integer: ");
        int num = sc.nextInt(); // 获取输入int
        System.out.println(num);
        System.out.println("Input a string: ");
        String str = sc.next(); // 获取输入String
        System.out.println(str);
    }
}
