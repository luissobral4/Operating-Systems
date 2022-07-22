#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
  int fd;
  int status,p = -1;
  if((fd = open("fifo",O_RDONLY))< 0){
    perror("fifo");
    return 1;
  }


  if(!(p = fork())){
    dup2(fd,0);
    close(fd);
    execlp("cat","cat",NULL);
    perror("cat");
    _exit(0);
  }else{
    wait(NULL);
  }
/*
  char buf[20];
  int bytes = 0;
  while ((bytes = read(fd,buf,20))) {
    if(write(1,buf,bytes)<0){
      perror("write");
      return 1;
    }
  }
  */
  return 0;
}
