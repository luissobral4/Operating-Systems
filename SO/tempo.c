#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
void sigalarm_handler(int signum){
  printf("Tempo esgotado\n");
  _exit(1);

if(signal(SIGCALRM,sigint_handler) == SIG_ERR){
  perror("error");
  _exit(1);
}
}
*/
void parse(char*** x) {
  //x = malloc(sizeof(char**));
  char line[10] = "rertvr r";
  char *s = strsep(&line," ");
  x[0] = malloc(sizeof(char*));
  x[0][0] = malloc(sizeof(char) * 20);
  strcpy(x[0][0],s);
}

int main(){
  char ***x =  malloc(sizeof(char**));
  parse(x);
  printf("%s\n", x[0][0]);
}
