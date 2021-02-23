package basic02.demo036发红包案例;

import java.util.ArrayList;
import java.util.Random;

public class Member extends User
{
    public Member() { }

    public Member(String name, int money) { super(name, money); }

    public void receiveRedPackets(ArrayList<Integer> moneyLst)
    {
        // 从多个红包之中随便抽取一个红包
        int ind = new Random().nextInt(moneyLst.size());

        // 根据索引，从集合中删除一个元素，把这个红包给自己
        int money = moneyLst.remove(ind);

        super.setMoney(super.getMoney() + money);
    }
}
