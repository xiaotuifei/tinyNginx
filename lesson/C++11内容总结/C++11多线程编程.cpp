#include <iostream>
#include <thread>

/**
 * C++语言级别的多线程编程 => 代码可以跨平台
 * thread/mutex/condition_variable
 * lock_guard/unique_lock
 * atomic原子类型，基于CAS操作的原子类型 线程安全的
 * sleep_for
 * 
 * C++语言层面 thread
 *      windows          linux
 *         |               |
 * createThread     pthread_create
 * 
 * 线程内容：
 * 一 怎么创建启动一个线程
 * std::thread定义一个线程对象，传入线程所需要的线程函数和参数，
 * 现成自动开启执行
 * 
 * 二、子线程如何结束
 * 子线程函数运行完成，线程就结束了
 * 
 * 三、主线程如何处理子线程
 * t.join()：等待t线程结束，当前线程继续往下运行
 * t.detach()：把t线程设置为分离线程，主线程结束，整个进程结束，所有子线程自动结束了
 * 
 */
void threadHandle1(int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // std::cout << std::this_thread::get_id() << std::endl;
    // std::cout << std::this_thread::get_id << std::endl;
    std::cout << "hello thread1!" << std::endl;
}

void threadHandle2(int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // std::cout << std::this_thread::get_id() << std::endl;
    // std::cout << std::this_thread::get_id << std::endl;
    std::cout << "hello thread2!" << std::endl;
}


 int main()
 {
    // 定义了一个线程对象   传入一个线程函数，新线程就开始运行了
    std::thread th1(threadHandle1, 3);
    std::thread th2(threadHandle2,2);
    // 主线程等待子线程结束，主线程继续往下运行
    th1.join();
    th2.join();

    // 把子线程设置为分离线程
    // th1.detach();

    // std::cout << std::this_thread::get_id() << std::endl;
    std::cout << "等待结束！" << std::endl;

    // 主线程运行完成，查看如果当前线程还有未完成的子线程
    // 进程就会异常终止
    return 0;
 }