/*
* `java.util.Math`是数学相关的工具类，提供了大量的静态方法
 * `public static double abs(double num)`： 获取绝对值
 * `public static double ceil(double num)`：向上取整
 * `public static double floor(double num)`： 向下取整
 * `public static long round(double num)`： 四舍五入
* */
package basic02.demo024Math工具类;

public class MathDemo
{
    public static void main(String[] args)
    {
        // Math.abs()
        System.out.println(Math.abs(-2.25));

        // Math.ceil()
        System.out.println(Math.ceil(1.1));

        // Math.floor()
        System.out.println(Math.floor(1.9));

        // Math.round()
        System.out.println(Math.round(12.34));

        // Math.PI
        System.out.println(Math.PI);

        // java中double可以++
        double num = 1.2;
        System.out.println(++num);
    }
}
