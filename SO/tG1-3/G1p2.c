#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  char buffer[10] = "";
  int sizel = 0;


  while ((sizel = read(0,buffer,sizeof(buffer))) != 0) {
      write(1,buffer,sizel);
  }

  return 0;
}
