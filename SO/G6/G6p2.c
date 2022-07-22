#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
  int fdrd = -1,fdwr = -1,log_fd = -1;
  int status,p = -1;
  if(mkfifo("fifo",0666)<0){
		perror("mkfifo");
		return 1;
	}
  if((log_fd = open("log.txt",O_WRONLY | O_TRUNC | O_CREAT,0666))< 0){
    perror("open log");
    return 1;
  }
  printf("open log\n");

  if((fdrd = open("fifo",O_RDONLY))< 0){
    perror("fifo");
    return 1;
  }

  if(!(p = fork())){
    dup2(fdrd,0);
    dup2(log_fd,1);
    close(fdrd);
    execlp("cat","cat",NULL);
    perror("cat");
    _exit(0);
  }else{
    close(log_fd);
    close(fdrd);
    wait(NULL);
  }
  unlink("fifo");

  return 0;
}
