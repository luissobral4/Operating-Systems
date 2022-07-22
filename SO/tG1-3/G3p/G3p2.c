#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
  pid_t p;
  if(!(p = fork())) {
    execlp("ls","ls","-l",NULL);
    perror("erro");
  }
  return 1;
}
