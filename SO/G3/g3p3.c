#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
    for(int i = 0;i < argc;i++)
      printf("argv[%d] %s\n", i,argv[i]);

    return 0;
}
