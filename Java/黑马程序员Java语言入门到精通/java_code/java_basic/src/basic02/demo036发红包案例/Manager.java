package basic02.demo036发红包案例;

import java.util.ArrayList;

// 群主类
public class Manager extends User
{
    public Manager() {}

    public Manager(String name, int money) { super(name, money); }

    // 发红包成员方法, count 份数, value 红包金额
    public ArrayList<Integer> sendRedPackets(int count, int value)
    {
        // 首先需要一个集合存储若干个红包金额
        ArrayList<Integer> moneyLst = new ArrayList<>();

        int moneyLeft = super.getMoney(); // 群主余额
        if (value > moneyLeft)
        {
            System.out.println("Left money not enough.");
            return moneyLst; // 返回空集合
        }
        super.setMoney(moneyLeft - value);

        // 发红包需要平均拆分成为count份
        int avg = value / count;
        int mod = value % count; // 整数，mod是剩下的除不尽的零头

        // 剩下的零头包在最后一个红包当中
        for (int i = 0; i < count - 1; i++) { moneyLst.add(avg); }

        moneyLst.add(mod + avg); // 最后一个红包单独处理

        return moneyLst;
    }
}
