#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ctrl_c_count = 0;
int secconds = 0;

void sigint_handler(int signum){
  printf("signal received %d\n", signum);
  printf("tempo passado %d\n", secconds);
  ctrl_c_count++;
}

void sigquit_handler(int signum){
  printf("carregou %d vezes no ctr C\n", ctrl_c_count);
  _exit(1);
}

void sigalarm_handler(int signum){
  secconds++;
  alarm(1);
  printf("seccond passed\n");
}

int main(){
  if(signal(SIGINT,sigint_handler) == SIG_ERR){
    perror("error");
    _exit(1);
  }

  if(signal(SIGQUIT,sigquit_handler) == SIG_ERR){
    perror("error");
    _exit(1);
  }

  if(signal(SIGALRM,sigalarm_handler) == SIG_ERR){
    perror("error");
    _exit(1);
  }

  alarm(1);
  while (1) {
    pause();
  }
  return 1;
}
