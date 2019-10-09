//
// Created by Administrator on 2019/9/26.
//
#include <iostream>

using std::cout;
using std::endl;

// CPP 的继承

class BaseClass
{
public:
    BaseClass() {}
    void f(const char *s = "unknown")
    {
        cout << "Function f() in BaseClass called from " << s << endl;
        h();
    }

protected:
    void g(const char *s = "unknown")
    {
        cout << "Function g() in BaseClass called from " << s << endl;
    }

private:
    void h()
    {
        cout << "Function h() in BaseClass\n";
    }
};


class Derived1Level1 : public virtual BaseClass
{
public:
    void f(const char *s = "unknown")
    {
        cout << "Function f() in Derived1Level1 called from " << s << endl;
        g("Derived1Level1");
        h("Derived1Level1");
    }
    void h(const char *s = "unknown")
    {
        cout << "Function h() in Derived1Level1 called from " << s << endl;
    }
};

class Derived2Level1 : public virtual BaseClass
{
public:
    void f(const char *s = "unknown")
    {
        cout << "Function f() in Derived1Level1 called from " << s << endl;
        g("Derived2Level1");
//        h();
    }
};

class DerivedLevel2 : public Derived1Level1, public Derived2Level1
{
public:
    void f(const char *s = "unknown")
    {
        cout << "Function f() in DerivedLevel2 called from " << s << endl;
        g("DerivedLevel2");
        Derived1Level1::h("DrivedLevel2");
        BaseClass::f("DriedLevel2");
//        h();
    }
};

int main()
{
    BaseClass bc;
    Derived1Level1 d1l1;
    Derived2Level1 d2l1;
    DerivedLevel2 dl2;

    bc.f("main(1)");
    // protected 方法不允许访问
//    bc.g();
//    bc.h();

    d1l1.f("main(2)");
//    d1l1.g();
    d1l1.h("main(3)");

    d2l1.f("main(4)");
//    d2l1.g();
//    d2l1.h();

    dl2.f("main(5)");
//    dl2.g();
    dl2.h();
    return 0;
}
