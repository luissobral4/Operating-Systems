#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
  pid_t p;
  int r,s;
  if(!(p = fork())) {
    execlp("ls","ls","-l",NULL);
    perror("error");
    _exit(-1);
  }
  else{
    p = wait(&r);
    if(WIFEXITED(r)) {
      s = WEXITSTATUS(r);
      printf("ls executado pelo %d exit %d\n", p,s);
    }
  }
  return 0;
}
