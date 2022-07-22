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

  char buffer[10] = "";
  ssize_t sizel = 0;
  ssize_t i = sizeof(buffer);

  while ((sizel = read(f1,buffer,sizeof(buffer))) != 0 && i == sizeof(buffer)) {
    for(i = 0; i< sizeof(buffer) && buffer[i] != '\n';i++);
    write(1,buffer,i);
  }

  return 0;
}
