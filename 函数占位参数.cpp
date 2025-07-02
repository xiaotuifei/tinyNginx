#include <iostream>

// 占位参数
// 返回值类型 函数名 (数据类型) {}

void func(int a, int = 10)
{
    std::cout << "this is func" << std::endl;
}

int main()
{
    
    func(10);
    system("pause");

    return 0;
}


