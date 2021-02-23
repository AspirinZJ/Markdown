package basic01.demo002方法;

public class Method
{
    public static void main(String[] args)
    {
        myPrintMethod();
        System.out.println(max(2, 5));
    }

    public static void myPrintMethod()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                System.out.print('*');
            }
            System.out.println();
        }
    }

    public static int max(int int1, int int2)
    {
        return int1 + int2;
    }
}
