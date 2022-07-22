#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX 10
int main(int argc, char *argv[]) {

  char c[MAX];
  int n;
  write(1,"Função cat\n",13*sizeof(char));

  while((n = read(0,c,MAX*sizeof(char)))) {
    if(n == 3 && c[0] == ':' && c[1] == 'q') return 0;
    write(1,c,n*sizeof(char));
  }
  return 0;
}
