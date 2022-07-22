#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
  pid_t p;
  int status;
  p = fork();
  if(!p) {
    printf("PID =%d\n",getpid() );
    printf("PID pai=%d\n",getppid() );
    _exit(0);
  }
  else {
    printf("<pai> PID =%d\n",getpid() );
    printf("<pai> PID pai=%d\n",getppid() );
    //printf("<pai> PID filho=%d\n",p );
    pid_t filho = wait(&status);
    printf("<pai> PID filho=%d %d\n",filho,status);
  }
  return 0;
}
