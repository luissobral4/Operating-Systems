#include "head.h"

void fill(int *vetor, int size, int value) {
  for(int i = 0;i < size; i++)
    vetor[i] = value;
}

int find(int *vetor, int size, int value) {
  int i;
  for(i = 0; vetor[i] != value; i++);
  if (i >= size) i = -1;
  return i;
}
