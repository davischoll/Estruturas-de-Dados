#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort (int vet[]);

#define TAMANHOVETOR 10

int main()
{
  int vet[TAMANHOVETOR] = {0};
  srand(time(NULL));    

  for (int i = 0; i < TAMANHOVETOR; i++)
    vet[i] = rand() % 100;    // GERA VALORES ALEATÓRIOS

  printf("VETOR NAO ORDENADO: \n");
  for (int i = 0; i < TAMANHOVETOR; i++)
    printf("%d\n", vet[i]);
  
  bubbleSort(vet);

  return 0;
}

void bubbleSort (int vet[])
{
  int aux;

  for (int i = 0; i < TAMANHOVETOR; i++)
  {
    for (int j = 0; j < TAMANHOVETOR -1; j++)
    {
      if (vet[j] > vet[j + 1])
      {
        aux = vet[j];
        vet[j] = vet[j + 1];
        vet[j+1] = aux;
      }
    }
  }

  printf("VETOR ORDENADO: \n");
  for (int i = 0; i < TAMANHOVETOR; i++)
    printf("%d\n", vet[i]);
}
