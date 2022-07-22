#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int myreadln(char *argv){
  int f1 = open(argv,O_RDONLY);
  if(f1 == -1) {
    printf("erro ficheiro %s\n", argv);
    return -1;
  }

  char buffer[10] = "";
  ssize_t sizel = 0;
  ssize_t i = sizeof(buffer);
  ssize_t total = 0;

  while ((sizel = read(f1,buffer,sizeof(buffer))) != 0 && i == sizeof(buffer)) {
    for(i = 0; i< sizeof(buffer) && buffer[i] != '\n';i++);
    write(1,buffer,i);
    total += i;
  }

  return total;
}

int main(int argc,char *argv[]){
  char buffer[33] = "";
  int line = 1;

  while (myreadln(argv[1]) > 0) {
    //itoa(line,buffer,10);
    //write(1,buffer,sizeof(buffer));
    printf("%d\n", line);
    line++;
  }

  return 0;
}
