#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[]) {
  int f,c = 1;
  char c2;
  //if(argc > 2)
  if(strcmp(argv[c],"-i") == 0) {
    f = open(argv[c+1],O_RDONLY);
    if(f == -1) {perror("erro 3");return 1;}
    dup2(f,0);
    close(f);
    c+=2;
  }

  if(strcmp(argv[c],"-o") == 0) {
    f = open(argv[c+1],O_WRONLY | O_CREAT | O_TRUNC,0600);
    if(f == -1) {perror("erro 3");return 1;}
    dup2(f,1);
    close(f);
    c+=2;
  }

execvp(argv[c],&argv[c+1]);

  return 0;
}
