#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  if((pid = fork())){
    //herda descritores do pipe
    close(pipe_fd[1]);
    char buf[10];
    int bytes = read(pipe_fd[0],buf,10);

    printf("li: %s\n",buf);
    _exit(0);
  }else{
    close(pipe_fd[0]);
    char *str = "teste";
    sleep(15);
    write(pipe_fd[1],str,strlen(str)+1);

    wait(NULL);
  }
}
