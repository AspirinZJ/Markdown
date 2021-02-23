/*
群主发普通红包，规则：
1. 群主的一笔金额，从群主余额中扣除，平均分成n等份，让成员领取
2. 成员领取红包后，保存到成员余额中
* */
package basic02.demo036发红包案例;

import java.util.ArrayList;

public class Main
{
    public static void main(String[] args)
    {
        Manager manager = new Manager("Manager", 100);
        Member mem1 = new Member("A", 0);
        Member mem2 = new Member("B", 0);
        Member mem3 = new Member("C", 0);

        showInfo(manager, mem1, mem2, mem3);
        System.out.println("-----------------------");

        // 发红包, 3份共20元
        ArrayList<Integer> moneyLst = manager.sendRedPackets(3, 20);
        mem1.receiveRedPackets(moneyLst);
        mem2.receiveRedPackets(moneyLst);
        mem3.receiveRedPackets(moneyLst);

        showInfo(manager, mem1, mem2, mem3);
    }

    public static void showInfo(Manager manager, Member mem1, Member mem2, Member mem3)
    {
        manager.show();
        mem1.show();
        mem2.show();
        mem3.show();
    }
}
