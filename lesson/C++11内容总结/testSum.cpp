#include <iostream>
#include <thread>
#include <future>


long long sum1()
{
    long long sum = 0;
    for (int i = 1; i < 300000000; i++)
    {
        sum += i;
    }
    return sum;
}

long long sum2()
{
    long long sum = 0;
    for (int i = 300000000; i < 600000000; i++)
    {
        sum += i;
    }
    return sum;
}

long long sum3()
{
    long long sum = 0;
    for (int i = 600000000; i <= 900000000; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    auto start = std::chrono::system_clock::now();
    long long sum = 0;
    for (int i = 1; i <= 900000000; i++)
    {
        sum += i;
    }

    std::cout << sum << std::endl;
    
    auto end = std::chrono::system_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "同步耗时：" << duration.count() << std::endl;


    start = std::chrono::system_clock::now();
    sum = 0;
   
    // 使用async启动异步任务，获取future对象
    std::future<long long> fut1 = std::async(std::launch::async, sum1);
    std::future<long long> fut2 = std::async(std::launch::async, sum2);
    std::future<long long> fut3 = std::async(std::launch::async, sum3);
    
    // 获取结果（如果线程未完成，会阻塞等待）
    long long res1 = fut1.get();
    long long res2 = fut2.get();
    long long res3 = fut3.get();
    

    long long result = res1 + res2 + res3;
    std::cout << result << std::endl;
    end = std::chrono::system_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "异步耗时：" << duration.count() << std::endl;
    
}