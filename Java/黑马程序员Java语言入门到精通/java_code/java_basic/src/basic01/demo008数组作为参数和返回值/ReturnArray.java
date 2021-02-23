// 数组作为返回值
// 如果一个方法中产生了多个结果的数据返回，可以返回一个数组
package basic01.demo008数组作为参数和返回值;

public class ReturnArray
{
    public static void main(String[] args)
    {
        int[] ret = calculate(1, 2, 3);
        System.out.println("sum: " + ret[0]);
        System.out.println("avg: " + ret[1]);
    }

    public static int[] calculate(int a, int b, int c)
    {
        int sum = a + b + c;
        int avg = sum / 3;
        return new int[]{sum, avg};
    }
}
