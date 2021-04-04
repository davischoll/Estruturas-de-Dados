#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>

struct ElementoDaArvoreBinaria {
  int dado;
  char nomeAluno[100];
  char emailAluno[100];
  struct ElementoDaArvoreBinaria *direita;
  struct ElementoDaArvoreBinaria *esquerda;
};

struct ElementoDaArvoreBinaria *root;

int menu();
void inserir(ElementoDaArvoreBinaria **ElementoVarredura, int num, char nome[], char email[]);
void listarEmOrdem (ElementoDaArvoreBinaria *ElementoVarredura);
int buscar(ElementoDaArvoreBinaria *ElementoVarredura, int num);

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int op, num, pos, c, res;

  root = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));
  root = NULL;

  struct ElementoDaArvoreBinaria aluno;

  int elementoBusca;
	// elementoBusca = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));

  while (1) {
    op = menu();

    switch (op)
    {
    case 1:
      printf("Digite o número do RU do Aluno: ");
      scanf("%d", &num);
      while ((c = getchar()) != '\n' && c != EOF) {}

      printf("Digite o nome do Aluno que deseja incluir: ");
      fgets(aluno.nomeAluno, 100, stdin);
      
      printf("Digite o endereço de email do Aluno: ");
      fgets(aluno.emailAluno, 100, stdin);

      inserir(&root, num, aluno.nomeAluno, aluno.emailAluno);
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
      listarEmOrdem(root);
      printf("\n");
      printf("\n");
      printf("Pressione uma tecla para retornar ao Menu.");
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

void inserir(ElementoDaArvoreBinaria **ElementoVarredura, int num, char *nome, char *email) {
  if (*ElementoVarredura == NULL)
  {
    ElementoDaArvoreBinaria *NovoElemento = NULL;
    NovoElemento = (struct ElementoDaArvoreBinaria *)malloc(sizeof(struct ElementoDaArvoreBinaria));
    
    NovoElemento->esquerda = NULL;
    NovoElemento->direita = NULL;
    NovoElemento->dado = num;
    strcpy(NovoElemento->nomeAluno, nome);
    strcpy(NovoElemento->emailAluno, email);

    *ElementoVarredura = NovoElemento;

    return;
  }

  if (num < (*ElementoVarredura)->dado)
    inserir(&(*ElementoVarredura)->esquerda, num, nome, email);
  else if (num > (*ElementoVarredura)->dado)
    inserir(&(*ElementoVarredura)->direita, num, nome, email);
}

void listarEmOrdem (ElementoDaArvoreBinaria *ElementoVarredura) {
  if (ElementoVarredura)
  {
    listarEmOrdem(ElementoVarredura->esquerda);
    printf("RU: %d\n", ElementoVarredura->dado);
    printf(" | Aluno: %s", ElementoVarredura->nomeAluno);
    printf(" | Email: %s\n", ElementoVarredura->emailAluno);
    listarEmOrdem(ElementoVarredura->direita);
  }
}

int buscar(ElementoDaArvoreBinaria *ElementoVarredura, int num) {
  if (ElementoVarredura == NULL)
	  return 0;

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
