#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 100000
        int a[LINHAS][COLUNAS];

int main(int argc,char *argv[]){
  if(argc != 2) return -1;
  pid_t p;
  pid_t filho;
  int status;
  int n = atoi(argv[1]);
  int i,c,s;

  for(i = 0;i < LINHAS;i++)
    for(c = 0;c < COLUNAS;c++)
      a[i][c] = (int) random()%100000;

  for(i = 0;i < LINHAS;i++)
    if(!(p = fork())) {
      for (c = 0; c < COLUNAS; c++)
        if(a[i][c] == n){
          printf("a[%d][%d]=%d\n",i,c,a[i][c]);
          _exit(0);
        }
      _exit(1);
    }

  for (i = 0; i < LINHAS; i++) {
    filho = wait(&status);
    if(WIFEXITED(status)){
      s = WEXITSTATUS(status);
      printf("pid filho %d exit status %d\n",filho,s);
    }
  }
  return 0;
}
