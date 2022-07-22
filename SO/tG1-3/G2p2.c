#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
  pid_t p;
  int status;
  if(!(p = fork())) {
    printf("Filho:pid %d\n", getpid());
    printf("Filho:pid pai %d\n", getppid());
    _exit(0);
  }
  else {
    printf("Pai:pid %d\n", getpid());
    printf("Pai:pid pai %d\n", getppid());
    pid_t filho = wait(&status);
    printf("Pai:filho pid %d %d\n", p,filho);
  }
    return 0;
}
