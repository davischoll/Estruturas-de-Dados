#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>

// Declaração da estrutura heterogênea que vai armazenar os dados dos alunos inseridos
struct AlunoUninter {
  int numRU;
  char nomeAluno[100];
  char emailAluno[100];
  struct AlunoUninter *direita;
  struct AlunoUninter *esquerda;
};

// Declaração do nó inicial da árvore binária (Raiz)
struct AlunoUninter *root;

// Declaração das funções que serão utilizadas no programa, antes da função principal main()
int menu();
void inserir(AlunoUninter **ElementoVarredura, int ru, char nome[], char email[]);
void listarEmOrdem (AlunoUninter *ElementoVarredura);
struct AlunoUninter *buscar(AlunoUninter **ElementoVarredura, int ru);

int main()
{
  setlocale(LC_ALL, "Portuguese");

  // Inicialização das variáveis do tipo inteiro e struct, que serão utilizadas na aplicação
  int op, ru, c;

  root = (struct AlunoUninter *)malloc(sizeof(struct AlunoUninter));
  root = NULL;

  struct AlunoUninter aluno;

  struct AlunoUninter *elementoBusca;
	elementoBusca = (struct AlunoUninter *)malloc(sizeof(struct AlunoUninter));

  // Laço de repetição que fica exibindo o Menu na tela inicial do programa
  while (1) {
    // 'op' recebe o retorno da função menu, que será um int
    op = menu();

    // De acordo com o número da opção selecionada, o switch vai executar o case respectivo
    switch (op)
    {
    case 1:
      // printf Solicita a inserção dos dados
      // 'fgets' e 'scanf' guarda os valores inseridos nas variáveis
      printf("Digite o número do RU do Aluno: ");
      scanf("%d", &ru);
      while ((c = getchar()) != '\n' && c != EOF) {} // Limpa buffer do teclado

      printf("Digite o nome do Aluno que deseja incluir: ");
      fgets(aluno.nomeAluno, 100, stdin);
      
      printf("Digite o endereço de email do Aluno: ");
      fgets(aluno.emailAluno, 100, stdin);

      // Chama a função que vai inserir um novo registro na árvore de alunos,
      // passando os parâmetros (dados) introduzidos pelo usuário
      inserir(&root, ru, aluno.nomeAluno, aluno.emailAluno);
    break;
    case 2:
      printf("Digite o número a ser buscado: ");
			scanf("%d", &ru);
      while ((c = getchar()) != '\n' && c != EOF) {}

      // Chama a função buscar, passando o RU digitado para busca,
      // e guarda o retorno desta função na variável elementoBusca
      elementoBusca = buscar(&root, ru);

      // Se retornar o elemento com o RU buscado, vai exibir os dados na tela
      // Caso não encontre o RU buscado, vai mostrar a mensagem do else
			if (elementoBusca != 0)
      {
				printf("RU: %d\n", elementoBusca->numRU);
        printf(" | Aluno: %s", elementoBusca->nomeAluno);
        printf(" | Email: %s\n", elementoBusca->emailAluno);
        printf("Pressione uma tecla para retornar ao Menu.");
      }
			else
      {
				printf("Número do RU não encontrado!\n");
        printf("Pressione uma tecla para retornar ao Menu.");
      }

			getchar();
    break;
    case 3:
      // Chamada da função que ordena a árvore em Ordem crescente
      listarEmOrdem(root);
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

// Declaração e implementação da função que insere um novo registro na árvore
void inserir(AlunoUninter **ElementoVarredura, int ru, char *nome, char *email) {
  if (*ElementoVarredura == NULL)
  {
    AlunoUninter *NovoElemento = NULL;
    NovoElemento = (struct AlunoUninter *)malloc(sizeof(struct AlunoUninter));
    
    NovoElemento->esquerda = NULL;
    NovoElemento->direita = NULL;
    NovoElemento->numRU = ru;
    strcpy(NovoElemento->nomeAluno, nome);
    strcpy(NovoElemento->emailAluno, email);

    *ElementoVarredura = NovoElemento;

    return;
  }

  if (ru < (*ElementoVarredura)->numRU)
    inserir(&(*ElementoVarredura)->esquerda, ru, nome, email);
  else if (ru > (*ElementoVarredura)->numRU)
    inserir(&(*ElementoVarredura)->direita, ru, nome, email);
}

// Função que ordena a árvore Em Ordem e vai exibindo os dados na tela
// Com chamada recursiva, colca primeiro os dados da esquerda, depois o
// nó raiz e depois os dados da direita
void listarEmOrdem (AlunoUninter *ElementoVarredura) {
  if (ElementoVarredura)
  {
    listarEmOrdem(ElementoVarredura->esquerda);
    printf("RU: %d\n", ElementoVarredura->numRU);
    printf(" | Aluno: %s", ElementoVarredura->nomeAluno);
    printf(" | Email: %s\n", ElementoVarredura->emailAluno);
    listarEmOrdem(ElementoVarredura->direita);
  }
}

// Função buscar, que vai fazer a busca pelo elemento informado
// quando solicitado o item 2 do menu. Se encontrar o número informado,
// vai retornar o elemento com os dados. Caso contrário, 0
struct AlunoUninter *buscar(AlunoUninter **ElementoVarredura, int ru) {
  AlunoUninter *elementoVarredura;
  elementoVarredura = (struct AlunoUninter *)malloc(sizeof(struct AlunoUninter));

  elementoVarredura = *ElementoVarredura;

  if (elementoVarredura == NULL)
	  return 0;

	if (ru < elementoVarredura->numRU)
		buscar(&elementoVarredura->esquerda, ru);
	else if (ru > elementoVarredura->numRU)
		buscar(&elementoVarredura->direita, ru);
	else if (ru == elementoVarredura->numRU)
    return elementoVarredura;
}
