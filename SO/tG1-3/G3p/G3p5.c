#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
  pid_t p;
  int r,s;
  for(int i = 1;i < argc;i++)
    if(!(p = fork())){
      execlp(argv[i],argv[i]);
      perror(argv[i]);
      _exit(i);
    }
  for(int i = 1;i < argc;i++)
    wait(NULL);

  return 0;
}
