#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  int f1 = open(argv[1],O_RDONLY);
  if(f1 == -1) {
    printf("erro ficheiro %s\n", argv[1]);
    return -1;
  }
  int f2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0600);
  if(f2 == -1) {
    printf("erro ficheiro %s\n", argv[2]);
    return -1;
  }
  char buffer[10] = "";
  int sizel = 0;


  while ((sizel = read(f1,buffer,sizeof(buffer))) != 0) {
      write(f2,buffer,sizel);
  }

  close(f1);
  close(f2);

  return 0;
}
