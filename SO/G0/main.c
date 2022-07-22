#include "head.h"
#include <stdio.h>

#define SIZE 100
int v[SIZE];

int main (){
  //int v[SIZE];

  fill(v,SIZE,10);

  int n = find(v,SIZE,10);
  printf("%d\n",n);

  return 1;
}
