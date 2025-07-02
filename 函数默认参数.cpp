#include <iostream>

// 函数默认参数

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

int main() 
{
    std::cout << func(10, 20, 30) << std::endl;
    system("pause");

    return 0;
}

