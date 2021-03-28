#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort (int vet[]);
int buscaBinaria(int vet[], int numBuscado, int inicio, int fim);

#define TAMANHOVETOR 10

int main()
{
  int numBuscado;
  int posicao;
  int vet[TAMANHOVETOR] = {0};
  srand(time(NULL));  

  for (int i = 0; i < TAMANHOVETOR; i++)
    vet[i] = rand() % 100;    // GERA VALORES ALEATÓRIOS

  bubbleSort(vet);

  printf("Digite um número para ser buscado: \n");
  scanf("%d", &numBuscado);

  posicao = buscaBinaria(vet, numBuscado, 0, TAMANHOVETOR - 1);

  if (posicao != -1)
    printf("O número %d foi encontrado na posição %d", numBuscado, posicao);
  else
    printf("Número não encontrado na lista!");

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

int buscaBinaria(int vet[], int numBuscado, int inicio, int fim)
{
  while (inicio <= fim)
  {
    int meio = (inicio + fim) / 2;

    if (vet[meio] == numBuscado)
      return meio + 1;
    else
    {
      if (numBuscado < vet[meio])
        fim = meio - 1;
      else
        inicio = meio + 1;
      buscaBinaria(vet, numBuscado, inicio, fim - 1);
    }
  }

  return -1;
}
