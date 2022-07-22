#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 100000
        int a[LINHAS][COLUNAS];

int main(int argc,char *argv[]) {
  int i = 0,r,s,j;
  pid_t p,n;

  if(argc < 2) {
    printf("falta nº a prcurar\n" );
    _exit(-1);
  }
  n = atoi (argv[1]);

  srand(time(NULL));

  for(i = 0;i < LINHAS;i++)
    for(j = 0;j < COLUNAS;j++)
      a[i][j] = (int) random()%100000;

  for(i = 0;i<LINHAS;i++) {
    p = fork();
    if(!p) {
      for(j = 0;j < COLUNAS;j++)
        if(n == a[i][j]) {
          printf("a[%d][%d]=%d\n",i,j,a[i][j]);
          _exit(0);
        }
      _exit(1);
    }
    else if(p == -1)
      printf("erro no fork\n");
  }

  for(i = 0;i<LINHAS;i++) {
    n = wait(&r);
    if(WIFEXITED(r)) {
      s = WEXITSTATUS(r);
      printf("PID do filho=%d exit status %d\n",n,s);
    }
  }
}
