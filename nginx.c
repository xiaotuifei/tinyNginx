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
    

}
