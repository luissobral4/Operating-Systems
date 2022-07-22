#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
  pid_t p;
  pid_t filho;
  int status;
  int s;
  for(int i = 0;i < 10;i++){
    if(!(p = fork())) {
      printf("Filho %d:pid %d\n", i,getpid());
      printf("Filho %d:pid pai %d\n", i,getppid());
      _exit(i);
    }
    filho = wait(&status);
    if(WIFEXITED(status)){
      s = WEXITSTATUS(status);
      printf("Pai: pid filho %d exit status %d\n",p,s);
    }
  }

  return 0;
}
