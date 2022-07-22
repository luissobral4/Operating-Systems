#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char *argv[]) {
  for(int i = 0;i < argc;i++)
    printf("argv[%d] %s\n", i,argv[i]);
  return 1;
}
