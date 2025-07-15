#include <iostream>
#include <memory>
#include <vector>


class AA
{
public:
    std::string m_name;
    AA() 
    {
        std::cout << m_name << " constructor called" << std::endl;
    }
    AA(const std::string& name) : m_name(name)
    {
        std::cout << "constructor called" << m_name << std::endl;
    }
    ~AA() 
    {
        std::cout << "destructor called" << m_name << std::endl;
    }

};


int main()
{
   

    // 茴香豆的三种写法
    std::unique_ptr<AA> pu1(new AA("王昭君"));

    std::unique_ptr<AA> pu2 = std::make_unique<AA>("李四");

    AA* p = new AA("西施");
    // 错误，不能把普通指针赋值给智能指针
    // std::unique_ptr<AA> pu1 = p;

    std::unique_ptr<AA> pu3(p);

    std::cout << pu1->m_name << std::endl;
    std::cout << pu2->m_name << std::endl;
    std::cout << pu3->m_name << std::endl;
}