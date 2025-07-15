#include <stdio.h>
#include <unistd.h>
int main(int argc, char *const *argv){
    printf("Linux C++通讯架构实战\n");
    for(;;){
        sleep(1); // 休息一秒
        printf("休息一秒\n");
    }
    printf("程序退出，再见！");
    return 0;
    

    // ps -eo pid,ppid,sid,tty,pgrp,comm,cmd|grep -E 'bash|PID|nginx'
    // 后台运行 & 
    // 后台执行，执行这个程序的同时，终端能够干其他事情；

    // ps -eo pid,ppid,sid,uid,tty,pgrp,comm,stat | grep -E 'bash|PID|nginx'
    // ps aux | grep -E 'bash|PID|nginx' aux 所谓BSD风格
    // sudo strace -e trace=signal -p 1184

}
