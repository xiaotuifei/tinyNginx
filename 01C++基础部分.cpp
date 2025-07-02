#include <iostream>


/**
 * 形参带默认值的函数
 * 1、给默认值的时候，从右向左给
 * 2、调用效率的问题
 * 3、定义出可以给形参默认值，声明也可以给形参默认值
 * 4、形参给默认值的时候，不管是定义出给，还是声明处给，形参默认值只能出现一次
 */

/**
 * inline内联函数 和 普通函数的区别？？？
 * inline内联函数：在编译过程中，就没有函数的调用开销了，在函数的调用点直接把
 * 函数的代码进行展开了
 * 
 * inline函数不再生成相应的函数符号
 * 
 * inline只是建议编译器把这个函数处理成内联函数
 * 但是不是所有的inline都会被编译器处理成内联函数  - 递归
 * 
 * debug版本上，inline是不起作用的；inline只有在release版本下才能出现
 * 
 */


inline int sum(int a = 10, int b = 20)
{
    return a + b;
}


int main01() 
{
    int a = 10;
    int b = 20;
    int ret = sum(a, b);
    // std::cout << "ret:" << std::endl;

    ret = sum(a);
    ret = sum();

}


 /**
  * 总结const和指针的类型转换公式：
  * int * <= const int* 是错误的！
  * const int* <= int * 是可以的!
  * int* const <= int * 是可以的！  
  * 
  */
int main02()
{
    int a = 10;
    int *p1 = &a;
    const int *p2 = &a;

    int *const p3 = &a;

    int *q1 = nullptr;
    int *const q2 = nullptr;

    std::cout << typeid(q1).name() << std::endl;
    std::cout << typeid(q2).name() << std::endl;
    // const如果右边没有指针*的划，const是不参与类型的
}

/**
 * 函数重载
 * 1、C++为什么支持函数重载，C语言不支持函数重载
 * C++代码产生函数符号的时候，函数名+参数列表类型组成的！
 * C代码产生函数符号的时候，函数名来决定！
 * 2、函数重载需要注意些什么？
 * 3、C++和C语言代码之间如何互相调用
 * 
 * 函数名相同，参数列表或者类型不同，那么这一组函数就成为重载函数
 * 
 */


 /**
  * const和二级指针的结合
  * 
  * int** <= const int** 是错误的!
  * const int** <= int** 是错误的！
  * int** <= int *const* 是错误的！
  * int*const* <= int** 是可以的！
  */
 int main04()
 {
    int a = 10;
    int *p = &a;
    const int **q = &p; // const int** <= int**
    

    const int b = 20;
    // int *p2 = &b; "const int *" 类型的值不能用于初始化 "int *" 类型的实体
    return 0;
 }


 int main()
 {
    int a = 10;
    const int *p = &a;  // const int* <= int *
    // int *q = p; // int * <= const int *  "const int *" 类型的值不能用于初始化 "int *" 类型的实体

    return 0;
 }