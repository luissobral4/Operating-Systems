#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
  pid_t p[10],filho;
  int status,s;

  for(int i = 0;i < 10;i++){
    if(!(p[i] = fork())) {
      printf("Filho %d:pid %d\n", i,getpid());
      printf("Filho %d:pid pai %d\n", i,getppid());
      _exit(i);
    }
  }
  for(int i = 0;i < 10;i++){
    //filho = wait(&status);
    filho = waitpid(p[9-i],&status,0);
    if(WIFEXITED(status)){
      s = WEXITSTATUS(status);
      printf("Pai: pid filho %d exit status %d\n",filho,s);
    }
  }

  return 0;
}
