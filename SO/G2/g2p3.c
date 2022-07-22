#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
  int i = 0,status,s;
  pid_t p;
  for(i = 0;i<10;i++) {
    p = fork();
    if(!p) {
      printf("PID filho=%d PID pai=%d\n",getpid(),getppid());
      _exit(i + 1);
    }
    pid_t filho = wait(&status); //p=-1 se n tiver filhos
    //s = WIFEXITED(r);
    if(WIFEXITED(status)) { //se filho correu sem erros
      s = WEXITSTATUS(status);
      printf("<pai> PID do filho=%d exit status %d\n",p,s);
    }
  }


}
