#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define MAX 10
int main(int argc, char *argv[]) {

  if(argc != 3) {
    write(1,"Erro argumentos",17*sizeof(char));
    return -1;
  }
  char c[MAX];
  int n;

  int d1 = open (argv[1],O_RDONLY,0777);
  if(!d1) {
    printf("ficheiro não existe");
    return -1;
  }
  int d2 = open (argv[2],O_WRONLY | O_CREAT | O_TRUNC,0777);

  time_t inicio = time(NULL);

  while((n = read(d1,c,5*sizeof(char))))
    write(d2,c,n*sizeof(char));

  time_t fim = time(NULL);
  printf("Tempo = %f\n",difftime(fim,inicio));

  close(d1);
  close(d2);
  return 0;
}
