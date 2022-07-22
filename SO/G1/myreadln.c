#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX 100
int main(int argc, char *argv[]) {
  int d = open(argv[1],O_RDONLY,0600);
  if(!d) {
    write(1,"ficheiro não existe",20*sizeof(char));
    return -1;
  }
  char c[MAX];
  int n,m = 0,r = 1,i;

  /*
  while((n = read(d,&c,sizeof(char)))&& c != '\n') {
    m++;
    write(1,&c,sizeof(char));
  }
  */

  while(r && (n = read(d,c + m * 10,10 * sizeof(char)))) {
    for(i = m * 10;i < m * 10 + n && r;i++)
      if(c[i] == '\n')
        r = 0;
    m++;
  }
  write(1,c,i * sizeof(char));
  return 0;
}
