#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
  pid_t p;

  printf("PID =%d\n",getpid() );
  printf("PID pai=%d\n",getppid() );
  return 0;
}
