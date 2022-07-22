#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
  pid_t p[10];
  pid_t filho;
  int status;
  int s;
  for(int i = 0;i < 10;i++){
    if(!(p[i] = fork())) {
      printf("Filho pid %d\n", getpid());
      printf("Filho pid pai %d\n", getppid());
    }
    else{
      p[i] = wait(&status);
      if(WIFEXITED(status)){
        s = WEXITSTATUS(status);
        printf("Pai: pid ficho %d exit status %d\n",p[i],s);
      }
      _exit(i);
    }
  }
  return 0;
}
