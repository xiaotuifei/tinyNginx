#include <iostream>

using namespace std;

// class Test
// {
// public:
//     Test(int a = 10) : ma(a)
//     {
//         cout << "Test(int)" << endl;
//     }

//     ~Test()
//     {
//         cout << "~Test()" << endl;
//     }

//     Test(const Test &t) : ma(t.ma)
//     {
//         cout << "Test(const Test&)" << endl;
//     }

//     Test &operator=(const Test &t)
//     {
//         cout << "operator=" << endl;
//         ma = t.ma;
//         return *this;
//     }

// private:
//     int ma;
// };

int main()
{
    Test t1;
    Test t2(t1);
    Test t3 = t1;

    // Test(20) 显式生成临时对象 生存周期：所在的语句

    // C++编译器对于对象构造的优化：用临时对象生成新对象的时候，
    // 临时对象就不产生了，直接构造新对象就可以了
    Test t4 = Test(20); // Test t4(20); 没有区别的！

    cout << "--------------------" << endl;

    // t4.operator = (const Test &t)
    t4 = t3 = Test(30);
    cout << "--------------------" << endl;

    t4 = (Test)30; // int->Test(int)
    cout << "--------------------" << endl;

    // 隐式生成临时对象
    t4 = 30;
    cout << "--------------------" << endl;

    // p指向的是一个已经析构的临时对象
    // Test *p = &Test(40);
    // cout << "--------------------" << endl;

    const Test &ref = Test(50);
    cout << "--------------------" << endl;

    return 0;
}

class Test
{
public:
    Test(int a = 10, int b = 20) : ma(a), mb(b)
    {
        cout << "Test(int, int)" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }

    Test(const Test &src) : ma(src.ma), mb(src.mb)
    {
        cout << "Test(const Test&)" << endl;
    }

    void operator=(const Test &src)
    {

        ma = src.ma;
        mb = src.mb;
        cout << "operator=" << endl;
    }

private:
    int ma;
    int mb;
};

Test t1(20, 30);
int main()
{
    Test t2(20, 30);
    Test t3 = t2;
    t2 = Test(40, 40);
    t2 = (Test)(50, 50);
    t2 = 60;
    Test *p1 = new Test(70, 70);
    Test *p2 = new Test[2];
    Test *p3 = &Test(80, 80);
    const Test &p4 = Test(90, 90);
    delete p1;
    delete []p2;

    return 0;
}
