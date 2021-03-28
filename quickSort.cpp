#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort (int vet[], int inicio, int fim);
int particao (int vet[], int inicio, int fim);
void troca(int vet[], int inicio, int fim);

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
  
  QuickSort(vet, 0, TAMANHOVETOR - 1);

  printf("VETOR ORDENADO: \n");
  for (int i = 0; i < TAMANHOVETOR; i++)
    printf("%d\n", vet[i]);

  return 0;
}

void QuickSort (int vet[], int inicio, int fim)
{
  int meio;

  if (inicio < fim)
  {
    meio = particao(vet, inicio, fim);
    QuickSort (vet, inicio, meio);
    QuickSort (vet, meio + 1, fim);
  }
}

int particao (int vet[], int inicio, int fim)
{
  int pivo, posicao_pivo, i, j;

  posicao_pivo = (inicio + fim) / 2;
  pivo = vet[posicao_pivo];

  i = inicio - 1;
  j = fim + 1;

  while (i < j)
  {
    do
    {
      j--;
    } while (vet[j] > pivo);
    do
    {
      i++;
    } while (vet[i] < pivo);

    if (i < j)
      troca(vet, i, j);
  }
  
  return j;
}

void troca(int vet[], int i, int f)
{
  int aux;
  aux = vet[i];
  vet[i] = vet[f];
  vet[f] = aux;
}
