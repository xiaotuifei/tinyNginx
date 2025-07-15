#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *const *argv)
{
    pid_t pid;

    printf("Linux c++ 通讯架构实战\n");

    // 系统函数，设置某个信号来的时候处理程序，（用哪个函数处理—）
    // SIG_IGN表时忽略这个信号，请操作系统不要用缺省的方式处理
    // signal(SIGHUP, SIG_IGN);

    // 系统函数，用来创建新进程，子进程会从fork()调用之后开始执行
    pid = fork(); 

    if (pid < 0)
    {
        printf("fork()进程出错！\n");
    }
    else if (pid == 0)
    {
    // 子进程会满足这个条件
    printf("子进程开始执行！\n");
    setsid();
        for(;;)
        {
            sleep(1);
            printf("子进程休息1秒\n");
        }
        return 0;
    }
    else
    {
        // 父进程会走到这里
        printf("子进程开始执行！\n");
        setsid();
        for(;;)
        {
        sleep(1);
        printf("父进程休息1秒\n");
    }
    return 0;
    }
    
    // 新建立一个不同的session，但是进程组组长调用setid()是无效的
    // setid()函数不适合进程组组长调用
    // setsid();

    // for(;;)
    // { 
    //     sleep(1);
    //     printf("休息1秒\n");
    // }
    // setsid命令：启动一个进程，而且能够使启动的进程在一个新的session中，这样不会随着终端关闭而关闭
    // nohup(no hang up不要挂断) 忽略SIGHUP信号，该命令会把屏幕输出重新定位到当前目录的nohup.out中去

    printf("程序退出，再见!\n");
    return 0;
}
