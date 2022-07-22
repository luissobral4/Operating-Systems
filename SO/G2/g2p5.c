#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
  int i = 0,r,s;
  pid_t p[10];
  for(i = 0;i<10;i++) {
    p[i] = fork();
    if(!p[i]) {
      printf("PID=%d PID pai=%d\n",getpid(),getppid());
    }
    else {
      p[i] = wait(&r);
      if(WIFEXITED(r)) {
        s = WEXITSTATUS(r);
        printf("PID =%d exit status %d %d\n",p[i],s,i);
      }
      _exit(i + 1);
    }
  }
}
