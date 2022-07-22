#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
  int f;
  char c;
  f = open("erros.txt",O_WRONLY | O_CREAT | O_TRUNC,777);
  if(f == -1) {perror("erro 3");return 1;}
  dup2(f,2);close(f);

  f = open("/etc/passwd",O_RDONLY);
  if(f == -1) {perror("erro 1");return 1;}
  dup2(f,0);close(f);

  f = open("saida.txt",O_WRONLY | O_CREAT | O_TRUNC,777);
  if(f == -1) {perror("erro 2");return 1;}
  dup2(f,1);close(f);

  if(fork() == 0)
    while(read(0,&c,1)!= 0)
      write(1,&c,1);

  return 0;
}
