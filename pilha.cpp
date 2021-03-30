#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void push(int value);
void pop();
void display();

struct Stack
{
  int dado;
  Stack *prox;
} *Top = NULL ;

int main()
{
  int c, op, value;

  while (1)
  {
    system ("clear");
    printf("\n***** MENU *****\n");
    printf("1. Empilhar/Push\n");
    printf("2. Desempilhar/Pop\n");
    printf("3. Listar\n");
    printf("4. Sair\n");

    printf("\nDigite uma opção no menu acima: ");
    scanf("%d", &op);
    while ((c = getchar()) != '\n' && c != EOF) {}

    switch (op)
    {
      case 1:
        printf("Digite o valor que deseja inserir na pilha: ");
        scanf("%d", &value);
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        push(value);
      break;
      case 2:
        pop();
      break;
      case 3:
        display();
      break;
      case 4:
        exit(0);
      break;
      default:
        printf("Inválido. Digite outra opção!\n");
    }
  }
}

void push(int value)
{
  Stack *novoElemento;
  novoElemento = (struct Stack*)malloc(sizeof(struct Stack));
  novoElemento->dado = value;

  if (Top == NULL)
    novoElemento->prox = NULL;
  else
    novoElemento->prox = Top;
  
  Top = novoElemento;

  printf("Inserido com sucesso!");
}

void pop()
{
  Stack *temp = Top;

  if (Top == NULL)
    printf("\nA Pilha não contém dados!");
  else
  {
    printf("\n Valor removido da pilha com sucesso!");
    Top = temp->prox;
    free(temp);

    getchar();
  } 
}

void display()
{
  Stack *elementoVarredura = Top;

  if (Top == NULL)
    printf("\nA Pilha não contém dados!!");
  else
  {
    while (elementoVarredura->prox != NULL)
    {
    printf("%d\n", elementoVarredura->dado);
    elementoVarredura = elementoVarredura->prox;
    }

    printf("%d\n", elementoVarredura->dado);
  }

  getchar();
}
