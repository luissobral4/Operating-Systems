#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX 100
size_t myreadln(int fd, char *line,size_t size) {
  int n,m = 0,r = 1;

  while(r && (n = read(fd,line + m,sizeof(char)))) {
      if(line[m] == '\n')
        r = 0;
    m++;
  }
  write(1,line,m * sizeof(char));
  return m * sizeof(char);
}

int main(int argc, char *argv[]) {
  int d = open(argv[1],O_RDONLY,0600);
  if(!d) {
    write(1,"ficheiro não existe",20*sizeof(char));
    return -1;
  }
  int n = 1;
  char a[MAX], c = '1';


  while(n) {
    write(1,&c,sizeof(c));
    write(1," ",sizeof(char));
    n = myreadln(d,a,MAX*sizeof(char));
    c++;
  }
  return 0;
}
