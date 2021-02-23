// 方法重载
package basic01.demo003重载方法;

public class MethodOverload
{
    public static void main(String[] args)
    {
        System.out.println(sum(1, 2));
        System.out.println(sum(1, 2, 3));
        System.out.println(sum(1.2, 2.3));
    }

    public static int sum(int a, int b) { return a + b;}
    public static int sum(int a, int b, int c) { return a + b + c;}
    public static int sum(double a, double b) { return (int) (a + b);}
}
