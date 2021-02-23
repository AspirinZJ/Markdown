// 匿名对象作为方法的参数和返回值
package basic02.demo017匿名对象;

import java.util.Scanner;

public class Anonymous
{
    public static void main(String[] args)
    {
        // 匿名对象的使用
        System.out.println("Input an integer: ");
        int num = new Scanner(System.in).nextInt();
        System.out.println(num);

        // 匿名对象作为方法参数
        useScanner(new Scanner(System.in));

        // 匿名对象作为方法返回值
        Scanner sc = returnScanner();
        System.out.println("Input an integer: ");
        num = sc.nextInt();
        System.out.println(num);
    }

    public static void useScanner(Scanner sc) // 匿名对象作为方法参数
    {
        System.out.println("Input an integer: ");
        int i = sc.nextInt();
        System.out.println(i);
    }

    public static Scanner returnScanner()
    { return new Scanner(System.in);}
}
