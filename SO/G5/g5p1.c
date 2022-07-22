#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#define MAX 10

int main(){
  int p[2];
  pipe(p);
  pid_t t;
  int n = 0;
  char buf[MAX];

  //p[0] - descritor de leitura
  //p[1] - descritor de escrita

  if(!(t = fork())) {
    //close(p[1]);
      //write(1,s,sizeof(s));
    printf("filho a ler\n");
    n = read(p[0],buf,MAX);
    printf("filho leu %s\n",buf);
    exit(0);
  }
  else {
    //close(p[0]);
    //while((n = read(0,bufPai,MAX)) > 0) {
    read(0,buf,MAX);
    printf("Pai a escrever\n");
    write(p[1],buf,MAX);
  }
}
