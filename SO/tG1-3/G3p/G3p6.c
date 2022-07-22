#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int my_system(char *comand) {
  char *argv[20];
  char *string;
  int status,p,i;

  string = strtok(comand," ");
  printf("%s\n", string);
  for(i = 0;string != NULL;i++){
    argv[i] = string;
    printf("%s\n", string);
    string = strtok(NULL," ");
  }
  argv[i] = NULL;

  if(!(p = fork())){
    execvp(argv[0],argv);
    perror("erro");
    _exit(1);
  }
  else{
    wait(&status);
    if (WIFEXITED(status))
      return WEXITSTATUS(status);
  }
  return 0;
}

int main(int argc,char *argv[]) {
  int res = my_system("ls -l");

  return 0;
}
