#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
  int status,p = -1;
  int fd;
  if((fd = open("fifo",O_WRONLY))< 0){
    perror("fifo");
    return 1;
  }

  if(!(p = fork())){
    dup2(fd,1);
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
  while ((bytes = read(0,buf,20))) {
    if(write(fd,buf,bytes)<0){
      perror("write");
      return 1;
    }
  }
  */
  return 0;
}
