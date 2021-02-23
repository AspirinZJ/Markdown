package basic02.demo036发红包案例;

public abstract class User
{
    private String name;
    private int money; // 余额

    public User() { }

    public User(String name, int money)
    {
        this.name = name;
        this.money = money;
    }

    public String getName() { return name; }

    public void setName(String name) { this.name = name; }

    public int getMoney() { return money; }

    public void setMoney(int money) { this.money = money; }

    public void show()
    {
        System.out.println("Name: " + this.name + ". Money: " + this.money);
    }
}
