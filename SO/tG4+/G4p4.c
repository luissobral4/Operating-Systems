#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  char c;
  if(argc < 3){
    perror("erro");
    return 1;
  }
  int f = open(argv[1],O_RDONLY);
  if(f == -1) {
    perror("erro 1");
    return 1;
  }
  dup2(f,0);
  close(f);

  f = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC ,0600);
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

  execvp(argv[3],&argv[3]);

  perror("erro");
    //while((read(0,&c,1)))
      //write(1,&c,1);


  return 0;
}
