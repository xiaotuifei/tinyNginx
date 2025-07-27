#include <iostream>
#include <memory>

int main()
{
    /**
     * 不带引用计数的智能指针
     *  auto_ptr：C++库里面
     * C++新标准：
     *  scope_ptr
     * 
     *  scope_ptr(const scope_ptr<T>&) = delete;
     *  scope_ptr<T>& operator= (const scoped_ptr<T>&) = delete;
     * 
     *  推荐使用：
     *  unique_ptr
     * 
     *  unique_ptr(const unique_ptr<T>&) = delete;
     *  unique_ptr<T>& operator= (const unique_ptr<T>&) = delete;
     * 
     *  unique_ptr (unique_ptr<T> &&src)
     *  unique_ptr<T>& operator=(unique_ptr<T> &&src)
     * 
     *  unique_ptr<T> getSmartPtr()
     *  {
     * 
     *   }
     * 
     * 怎么解决浅拷贝问题！！！
     * 
     * std::move => C++11 右值引用 std::move得到当前变量的右值类型
     */

    // std::auto_ptr<int> ptr1(new int);

    // std::auto_ptr<int> ptr2(ptr1);

    std::unique_ptr<int> ptr1(new int);
    std::unique_ptr<int> ptr2(std::move(ptr1));

    *ptr2 = 20;

    std::cout << *ptr2 << std::endl;

    return 0;
}