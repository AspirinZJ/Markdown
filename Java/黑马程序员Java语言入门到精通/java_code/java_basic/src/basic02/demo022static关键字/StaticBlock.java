/*
* public class 类名称
{
	static
	{
	静态代码块的内容
	}
}
*
* 特点：当第一次用到本类时，静态代码块执行唯一的一次
* 静态内容总是优先与非静态，所以静态代码块比构造方法先运行
* 静态代码块的典型用途是一次性地对静态成员变量进行赋值
* */
package basic02.demo022static关键字;

public class StaticBlock
{
    static { System.out.println("static block.");}

    public StaticBlock() { System.out.println("constructor.");}
}
