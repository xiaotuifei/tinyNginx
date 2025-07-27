#include <iostream>

using namespace std;

// 智能指针 保证能做到资源的自动释放！！！
// 利用栈上的对象出作用域自动析构的特征，来做到资源的自动释放
// CSmartPtr<int> *ptr2 = new CSmartPtr<int>(new int(20)); delete p;

template <typename T>
class CSmartPtr
{
public:
    CSmartPtr(T *ptr = nullptr)
        : mptr(ptr)
    {
    }

    ~CSmartPtr()
    {
        delete mptr;
    }

    T &operator*()
    {
        return *mptr;
    }

    T *operator->()
    {
        return mptr;
    }

    // 禁止拷贝，避免double free
    CSmartPtr(const CSmartPtr &) = delete;
    CSmartPtr &operator=(const CSmartPtr &) = delete;

private:
    T *mptr;
};

int main()
{

    // data段 heap堆 stack栈
    // int *p = new int(10);

    CSmartPtr<int> ptr1(new int(10));

    class Test
    {
    public:
        void test()
        {
            std::cout << "Test function" << std::endl;
        }
    };

    *ptr1 = 20;

    CSmartPtr<Test> ptr2(new Test());

    ptr2->test();

    (*ptr2).test();

    return 0;
}