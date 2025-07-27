#include <iostream>
#include <list>
#include <thread>
#include <atomic>
#include <mutex>

/**
 * C++ thread 模拟车站窗口卖票的程序
 */

// 车站有100张车票，由三个窗口一起卖票
// 原子变量
// std::atomic_int count(100);

int count = 100;

std::mutex mtx;

/**
 * 多线程程序
 * 竞态条件：在多线程编程中，竞态条件（Race Condition） 指的是当多个线程同时访问和操作共享资源（如变量、数据结构、文件等）时
 * 由于线程执行顺序的不确定性，导致程序最终结果出现不可预测的错误。
 */

// 模拟卖票的程序 lock_guard unique_lock
void sellTicket(int index)
{

    while (count > 0)
    {
        // mtx.lock();

        {
            // std::lock_guard<std::mutex> lock(mtx); // 保证所有现成都能释放锁，防止死锁
            std::unique_lock<std::mutex> lck(mtx); // unique_ptr
            // lck.lock();
            if (count > 0)
            {
                std::cout << "窗口：" << index << "卖出第：" << count << "张票！" << std::endl;
                count--;
            }
            lck.unlock();
        }
        
        // mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main()
{
    std::list<std::thread> tlist;
    for (int i = 1; i <= 3; i++)
    {
        tlist.emplace_back(std::thread(sellTicket, i));
    }

    for (auto &t : tlist)
    {
        t.join();
    }

    return 0;
}