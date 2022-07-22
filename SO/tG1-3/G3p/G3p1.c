#include <unistd.h>
#include <stdio.h>

int main() {
  execlp("ls","ls","-l",NULL);
  perror("erro");
  return 1;
}
