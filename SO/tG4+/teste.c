#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[]){
  char* com1[3];
  char* com2[3];
  com1[0] = argv[1];
  com1[1] = argv[2];
  com1[2] = NULL;
  com2[2] = NULL;
  com2[0] = argv[3];
  com2[1] = argv[4];
  int pipe_fd[2];
  if(pipe(pipe_fd)<0){
    perror("pipe");
    _exit(1);
  }

  int pid = -1;
  if((pid = fork())){
    close(pipe_fd[1]);
    if(!fork()){
      dup2(pipe_fd[0],0);
      close(pipe_fd[0]);
      execvp(com2[0],com2);
    }
    wait(NULL);
  }else{
      close(pipe_fd[0]);
      dup2(pipe_fd[1],1);
      close(pipe_fd[1]);
      execvp(com1[0],com1);
      _exit(1);
  }
}
