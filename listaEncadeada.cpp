#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int menu ();
void inserirInicio (int num);
void inserirFinal (int num);
void inserirMeio (int num, int posicao);
int removerElemento (int num);
void listar ();

struct ElementoListaSimples {
  int dado;
  ElementoListaSimples *prox;
}
*Head;

int main()
{
  int c, op, num, posicao, retorno;

  while (1)
  {
    op = menu();

    switch (op)
    {
      case 1:
        printf("Digite o número que deseja inserir no início da lista: ");
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF) {}

        inserirInicio(num);
      break;
      case 2:
        printf("Digite o número que deseja inserir no final da lista: ");
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF) {}

        inserirFinal(num);
      break;
      case 3:
        printf("Digite o número que deseja inserir na lista: ");
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF) {}

        printf("Digite a posição na qual deseja inserir o novo número: ");
        scanf("%d", &posicao);
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        inserirMeio(num, posicao);
      break;
      case 4:
        printf("Digite o número que deseja remover da lista: ");
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        retorno = removerElemento(num);
        
        if (retorno == 1)
          printf("Número %d removido com sucesso! \n", num);
        else
          printf("Número não encontrado na lista! \n");
        
        getchar();
      break;
      case 5:
        listar();
      break;
      case 6:
        return 0;
      default:
        printf("Inválido\n");
    }
  }

  return 0;
}

int menu ()
{
  int op, c;

  system("clear");

  printf("1. Inserir no início da lista encadeada simples\n");
  printf("2. Inserir no fim da lista encadeada simples\n");
  printf("3. Inserir no meio da lista encadeada simples\n");
  printf("4. Remover da lista encadeada simples\n");
  printf("5. Mostrar toda a lista encadeada simples\n");
  printf("6. Sair\n");

  printf("\n Escolha uma opção do menu acima: ");
  scanf("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}

  system("clear");

  return op;
}

void inserirInicio (int num)
{
  ElementoListaSimples *novoElemento;
  novoElemento = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples)); // ALOCAR O NOVO ELEMENTO NA MEMÓRIA COM O TAMANHO DA ESTRUTURA
  novoElemento->dado = num;

  if (Head == NULL)
  {
    Head = novoElemento;
    Head->prox = NULL;
  }
  else
  {
    novoElemento->prox = Head;
    Head = novoElemento;
  }
}

void inserirFinal (int num)
{
  ElementoListaSimples *novoElemento;
  novoElemento = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples)); // ALOCAR O NOVO ELEMENTO NA MEMÓRIA COM O TAMANHO DA ESTRUTURA
  novoElemento->dado = num;

  if (Head == NULL)
  {
    Head = novoElemento;
    Head->prox = NULL;
  }
  else
  {
    ElementoListaSimples *elementoVarredura;
    elementoVarredura = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));

    elementoVarredura = Head;

    while (elementoVarredura != NULL)
    {
      if (elementoVarredura->prox == NULL)
      {
        elementoVarredura->prox = novoElemento;
        novoElemento->prox = NULL;
      }
      elementoVarredura = elementoVarredura->prox;
    }
  }
}

void inserirMeio (int num, int posicao)
{
  ElementoListaSimples *novoElemento;
  novoElemento = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples)); // ALOCAR O NOVO ELEMENTO NA MEMÓRIA COM O TAMANHO DA ESTRUTURA
  novoElemento->dado = num;

  ElementoListaSimples *elementoVarredura;
  elementoVarredura = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));

  ElementoListaSimples *elementoAuxiliar;
  elementoAuxiliar = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));

  if (posicao == 0)
  {
    inserirInicio(num);
  }
  else
  {
    elementoVarredura = Head;
    for (int i = 0; i < posicao - 1; i++)
    {
      elementoVarredura = elementoVarredura->prox;
    }

    elementoAuxiliar = elementoVarredura->prox;
    elementoVarredura->prox = novoElemento;
    novoElemento->prox = elementoAuxiliar;
  }
}

int removerElemento (int num)
{
  ElementoListaSimples *elementoAnterior;
  elementoAnterior = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));
  
  ElementoListaSimples *elementoVarredura;
  elementoVarredura = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));

  elementoVarredura = Head;

  while (elementoVarredura != NULL)
  {
    if (elementoVarredura->dado == num)
    {
      if (elementoVarredura == Head)
        Head = elementoVarredura->prox;
      else
        elementoAnterior->prox = elementoVarredura->prox;
      
      free(elementoVarredura);
      return 1;
    }
    else
    {
      elementoAnterior = elementoVarredura;
      elementoVarredura = elementoVarredura->prox;
    }
  }

  return 0;
}

void listar ()
{
  ElementoListaSimples *elementoVarredura;
  elementoVarredura = (struct ElementoListaSimples *)malloc(sizeof(struct ElementoListaSimples));

  elementoVarredura = Head;

  if (elementoVarredura == NULL)
  {
    printf("A lista não contém elementos.");
    printf("\nPressione uma tecla para voltar ao menu e adicionar.");
    
    getchar();
    
    return;
  }
  
  while (elementoVarredura != NULL)
  {
    printf("%d ", elementoVarredura->dado);
    elementoVarredura = elementoVarredura->prox;
  }

  printf("\nPressione uma tecla para voltar ao menu.");

  getchar();

  return; 
}
