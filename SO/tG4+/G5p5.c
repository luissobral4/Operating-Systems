#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[]){
  int pipe_fd[2];//1ºpipe
  if(pipe(pipe_fd)<0){perror("pipe");_exit(1);}
  printf("pid %d\n", getpid());

  int pid = -1;
  if(!(pid = fork())){//1ºfilho
    close(pipe_fd[1]);
    dup2(pipe_fd[0],0);
    close(pipe_fd[0]);

    int pipe2_fd[2];//2ºpipe
    if(pipe(pipe2_fd)<0){perror("pipe2");_exit(1);}
    if(!(pid = fork())) {//3ºfilho
      close(pipe2_fd[1]);
      dup2(pipe2_fd[0],0);
      close(pipe2_fd[0]);

      int pipe3_fd[2];//3ºpipe
      if(pipe(pipe3_fd)<0){perror("pipe3");_exit(1);}
      if(!(pid = fork())){//5ºfilho
        close(pipe3_fd[1]);
        dup2(pipe3_fd[0],0);
        close(pipe3_fd[0]);

        execlp("wc","wc","-l",NULL);
        _exit(1);
      }else{
        close(pipe3_fd[0]);

        if(!(pid = fork())){//6ºfilho
          dup2(pipe3_fd[1],1);
          execlp("uniq","uniq",NULL);
          _exit(1);
        }

        close(pipe3_fd[1]);
        wait(NULL);
        wait(NULL);
      }
    }
    else{
      close(pipe2_fd[0]);

      if(!(pid = fork())){//4ºfilho
        dup2(pipe2_fd[1],1);
        execlp("cut","cut","-f7","-d:",NULL);
        _exit(1);
      }

      close(pipe2_fd[1]);
      wait(NULL);
      wait(NULL);
    }
    _exit(1);
  }else{
    close(pipe_fd[0]);

    if(!(pid = fork())){//2ºfilho
      dup2(pipe_fd[1],1);
      execlp("grep","grep","-v","^#","/etc/passwd",NULL);
      _exit(1);
    }

    close(pipe_fd[1]);
    wait(NULL);
    wait(NULL);
  }
}
