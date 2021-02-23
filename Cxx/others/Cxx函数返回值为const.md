C++函数返回值为const

令函数返回值为const，往往可以降低因用户错误而造成的意外，而又不至于放弃安全性和高效性。

```c
class Rational {...};
class Rational operator* (const Rational &lhs, const Rational &rhs);
Rational a, b, c
(a * b) = c    // 在 a*b的成果上调用operator=。这句话会报错误。
```

1. 函数返回值为const时候，代表返回的值不能修改，变成了右值即临时对象。
2. 将c赋值给(a*b), 相当于赋值给了右值（临时对象），编译器不予许。
3. 当类的赋值构造函数时，即 a=b=c, 此时禁止返回为const，因为a=b当做左值才能进行赋值。

