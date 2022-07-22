#include <unistd.h>
#include <stdio.h>

#define MAX 64

int main(){
  int p[2];
  pipe(p);
  pid_t t;
  int n;
  char buf[MAX],bufPai[MAX],s[MAX];

  //p[0] - descritor de leitura
  //p[1] - descritor de escrita

  if(!(t = fork())) {
    close(p[1]);
    while((n = read(p[0],buf,MAX)) > 0) {
      sprintf(s,"%s",buf);
      write(1,s,sizeof(s));
    }
  }
  else {
    close(p[0]);
    while((n = read(0,bufPai,MAX)) > 0) {
      write(p[1],bufPai,6);
      write(p[1],bufPai+6,10);
    }
  }
}
