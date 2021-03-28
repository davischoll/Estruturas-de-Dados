#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscarSequencial(int vet[], int num);

#define TAMANHOVETOR 10

int main()
{
  int numBuscado;
  int posicao;
  int vet[TAMANHOVETOR] = {0};
  srand(time(NULL));  

  for (int i = 0; i < TAMANHOVETOR; i++)
    vet[i] = rand() % 100;    // GERA VALORES ALEATÓRIOS

  printf("VETOR GERADO: \n");
  for (int i = 0; i < TAMANHOVETOR; i++)
    printf("%d\n", vet[i]);
  
  printf("Digite um número para ser buscado: \n");
  scanf("%d", &numBuscado);

  posicao = buscarSequencial(vet, numBuscado);

  if (posicao != -1)
    printf("O número %d foi encontrado na posição %d", numBuscado, posicao);
  else
    printf("Número não encontrado na lista!");

  return 0;
}

int buscarSequencial(int vet[], int num)
{
  int idEncontrado = 0;
  int i = 0;

  while (i < TAMANHOVETOR && idEncontrado == 0)
  {
    if (vet[i] == num)
      idEncontrado = 1;
    else
      i++;
  }

  return (idEncontrado == 0) ? -1 : i + 1;
}
