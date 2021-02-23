/*
重写override：在继承关系中，方法的名称一样，参数列表也一样，如果创建的是子类的对象，则优先使用子类的方法
==`@Override`:写在方法前面，用来检测是不是有效的正确重写==， `@`是annotation， 注解

注意：

* 必须保证父子类方法名称相同，参数列表也相同
* `@Override`就算不写，只要满足要求，也是正确的重写， 它只是一种安全检测, ==推荐写==
* ==子类方法的返回值必须小于等于父类方法的返回值范围==， 例如，String有一个父类Object， java.lang.Object类是所有类的公共最高父类，如果父类返回Object，子类可以返回String
* ==子类方法的权限修饰符必须大于等于父类方法的权限修饰符==， ==从大到小是`public > pretected > (default) > private`==
  * 注意(default)不是关键字，而是什么都不写，留空

* 重写override：方法的名称一样，参数列表也一样。也叫方法的覆盖/覆写。
* 重载overload：方法的名称一样，参数列表不一样
* */
package basic02.demo029继承中方法的重写;

public class OverrideDemo
{

}
