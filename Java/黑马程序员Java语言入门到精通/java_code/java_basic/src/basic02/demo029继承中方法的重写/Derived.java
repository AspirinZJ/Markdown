package basic02.demo029继承中方法的重写;

public class Derived extends Base
{
    @Override // 可选的安全检测手段
    public String method() {return null;} // 重写, String的范围比Object小，可以

    // public Object method2() { return null;} // 错误，Object的范围比String大

    // protectd void method3() { } // 错误，子类的重写方法去权限要大于等于父类方法权限

    //    @Override
    //    public void method1() {} // 不是重写，加@Override会报错
}
