// Random类: 用来生成随机数字
// Random在java.util包中， `import java.util.Random`
// 获取一个随机int:
// Random.nextInt() -> 范围是int所有的范围（正负都有）
// Random.nextInt(int range) -> 获取一个随机int，range代表类范围，左闭右开区间，如Random.nextInt(10) 代表了[0, 10)
package basic02.demo018Random;

import java.util.Random;

public class UseRandom
{
    public static void main(String[] args)
    {
        Random rand = new Random();
        int randNum = rand.nextInt(); // 获取一个随机的int
        System.out.println("Random number: " + randNum);

        randNum = rand.nextInt(3); // 在[0, 3)区间获取一个随机数
        System.out.println("Random number: " + randNum);

        // 根据int变量n的值，来获取随机数字， 范围是[1, n]
        int n = 10;
        randNum = rand.nextInt(n) + 1;
        System.out.println("Random number: " + randNum);
    }
}
