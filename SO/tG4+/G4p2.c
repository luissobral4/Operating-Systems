#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
  char c;
  /*
  int f = open("l.txt",O_RDONLY);
  if(f == -1) {
    perror("erro 1");
    return 1;
  }
  dup2(f,0);
  close(f);
*/
  int f = open("saida.txt",O_WRONLY | O_TRUNC | O_CREAT,0600);
  if(f == -1) {
    perror("erro 2");
    return 1;
  }
  dup2(f,1);
  close(f);

  f = open("erros.txt",O_WRONLY | O_TRUNC | O_CREAT,0600);
  if(f == -1) {
    perror("erro 3");
    return 1;
  }
  dup2(f,2);
  close(f);

  pid_t p;
  if(!(p = fork())) {
    execlp("cat","cat","l.txt",NULL);
    //while((read(0,&c,1)))
      //write(1,&c,1);
  }

  return 0;
}
