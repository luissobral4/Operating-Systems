#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[]){
  //criar pipe
  int pipe_fd[2];
  //pode falhar qd n existe memoria suficiente para o criar
  if(pipe(pipe_fd)<0){
    perror("pipe");
    _exit(1);
  }
  printf("pid %d\n", getpid());
  sleep(10);

  // criar processo filho
  int pid = -1;
  if(!(pid = fork())){
    //herda descritores do pipe
    close(pipe_fd[1]);

    dup2(pipe_fd[0],0);
    close(pipe_fd[0]);

    execlp("wc","wc","-l",NULL);
    _exit(1);
  }else{
    close(pipe_fd[0]);

    if(!(pid = fork())){
      dup2(pipe_fd[1],1);
      execlp("ls","ls","/etc",NULL);
      _exit(1);
    }else{
      close(pipe_fd[1]);
      wait(NULL);
      wait(NULL);
    }
  }
}
