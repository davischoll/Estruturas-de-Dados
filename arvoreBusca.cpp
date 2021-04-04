#include <stdio.h>
#include <stdlib.h>

struct ElementoDaArvoreBinaria {
  int dado;
  struct ElementoDaArvoreBinaria *direita;
  struct ElementoDaArvoreBinaria *esquerda;
};

int menu();
void inserir(ElementoDaArvoreBinaria **ElementoVarredura, int num);
void listarEmOrdem (ElementoDaArvoreBinaria *ElementoVarredura);
int buscar(ElementoDaArvoreBinaria *ElementoVarredura, int num);

int main() {
  int op, num, pos, c, res;

  struct ElementoDaArvoreBinaria *root;
  root = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));
  root = NULL;

  int elementoBusca;
	// elementoBusca = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));

  while (1) {
    op = menu();

    switch (op)
    {
    case 1:
      printf("Digite um número para inserir na Árvore: ");
      scanf("%d", &num);
      while ((c = getchar()) != '\n' && c != EOF) {}

      inserir(&root, num);
    break;
    case 2:
      printf("Digite o número a ser buscado: ");
			scanf("%d", &num);
      while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			
      elementoBusca = buscar(root, num);

      printf("%d", elementoBusca);

			if (elementoBusca != 0)
				printf("Valor localizado.\n");
			else
				printf("Valor não encontrado na Árvore.\n");

			getchar();
    break;
    case 3:
      printf("\n");
      listarEmOrdem(root);
      printf("\n");
      getchar();
    break;
    case 4:
      return 0;
    break;
    default:
      printf("Inválido!\n");
    break;
    }
  }
  return 0;
}

int menu() {
  int op, c;

  // Limpa a tela do usuário e exibe as opções do menu principal
  system("clear");

  printf("*******  MENU ÁRVORE BINÁRIA BST  ******* \n");
  printf("1. Inserir na Árvore Binária\n");
  printf("2. Buscar na Árvore Binária\n");
  printf("3. Consultar a Árvore Binária\n");
  printf("4. Sair\n");
  printf("***** ***** ***** ***** ***** ***** *****");
  printf("\nSelecione uma opção do menu acima: ");

  scanf("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}

  system("clear");

  return op;
}

void inserir(ElementoDaArvoreBinaria **ElementoVarredura, int num) {
  if (*ElementoVarredura == NULL)
  {
    ElementoDaArvoreBinaria *NovoElemento = NULL;
    NovoElemento = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));
    
    NovoElemento->esquerda = NULL;
    NovoElemento->direita = NULL;
    NovoElemento->dado = num;

    *ElementoVarredura = NovoElemento;

    return;
  }

  if (num < (*ElementoVarredura)->dado)
    inserir(&(*ElementoVarredura)->esquerda, num);
  else if (num > (*ElementoVarredura)->dado)
    inserir(&(*ElementoVarredura)->direita, num);
}

void listarEmOrdem (ElementoDaArvoreBinaria *ElementoVarredura) {
  if (ElementoVarredura)
  {
    listarEmOrdem(ElementoVarredura->esquerda);
    printf("%d\t", ElementoVarredura->dado);
    listarEmOrdem(ElementoVarredura->direita);
  }
}

int buscar(ElementoDaArvoreBinaria *ElementoVarredura, int num) {
  if (ElementoVarredura == NULL)
	  return NULL;

	if (num < ElementoVarredura->dado)
	{
		buscar(ElementoVarredura->esquerda, num);
	}
	else if (num > ElementoVarredura->dado)
	{
		buscar(ElementoVarredura->direita, num);
	}
	else if (num == ElementoVarredura->dado)
	{
    return ElementoVarredura->dado;
	}

  return ElementoVarredura->dado;
}
