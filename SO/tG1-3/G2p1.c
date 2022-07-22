#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    printf("pid Filho %d\n", getpid());
    printf("pid Pai %d\n", getppid());

    return 0;
}
