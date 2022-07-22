#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 10
typedef struct {
  char nome[MAX];
  int idade;
} *pessoa;
//int a[size];

int main(int argc, char *argv[]) {
  pessoa est;
  est = (pessoa)malloc(sizeof(pessoa));
  //est.idade = malloc(sizeof(int));
  if(!strcmp(argv[1],"-i")) {
    strcpy(est->nome,argv[2]);
    est->idade = atoi(argv[3]);

    int d = open ("f.txt",O_WRONLY | O_APPEND,0600);
    if(!d) {
      printf("erro");
      return -1;
    }

    write(d,est->nome,sizeof(est->nome));
    write(d,est->idade,sizeof(est->idade));
    printf("%s..\n", est->nome);
    close(d);
    return 0;
  }
  //if(strcmp(argv[1],"-i")) {
  //}
  return 0;
}
