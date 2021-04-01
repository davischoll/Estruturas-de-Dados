#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>

// Declaração das funções que serão utilizadas no programa, antes da função principal main()
int menu ();
void inserirInicio (char nomeFaixa[], char nomeArtista[], float tempoFaixa);
void listar ();

// Declaração da estrutura heterogênea que vai armazenar os dados das músicas
struct Musicas {
  char nomeMusica[100];
  char nomeArtista[100];
  float tempoFaixa;
  struct Musicas *prox;
};

// Declaração do nó inicial da lista (Cabeça)
struct Musicas *Head;

int main()
{
  setlocale(LC_ALL, "Portuguese");

  // Inicialização das variáveis do tipo inteiro e struct, que serão utilizadas na aplicação
  int op, c, retorno;
  struct Musicas musica;

  // Laço de repetição que fica exibindo o Menu na tela inicial do programa
  while (1)
  {
    // A variável 'op' recebe o retorno da função menu, que será um int
    op = menu();

    // De acordo com o número da opção selecionada, o switch vai executar o case respectivo
    switch (op)
    {
      case 1:
        // printf Solicita a inserção dos dados
        // fgets e scanf guarda os valores inseridos nas variáveis
        printf("Digite o nome da música que deseja incluir: ");
        fgets(musica.nomeMusica, 100, stdin);
        
        printf("Digite o nome do artista desta composição: ");
        fgets(musica.nomeArtista, 100, stdin);

        printf("Digite a duração da faixa que está incluindo: ");
        scanf("%f", &musica.tempoFaixa);
        while ((c = getchar()) != '\n' && c != EOF) {} // Limpa buffer do teclado

        // Chama a função que vai inserir um novo registro no início da lista
        inserirInicio(musica.nomeMusica, musica.nomeArtista, musica.tempoFaixa);
      break;
      case 2:
        // Chama a função que vai exibir os dados inseridos na tela
        listar();
      break;
      case 3:
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

  // Limpa a tela do usuário e exibe as opções do menu principal
  system("clear");

  printf("*******   PLAYLIST  DE  MÚSICAS   ******* \n");
  printf("1. Inserir nova Música na sua playlist\n");
  printf("2. Exibir a playlist das Músicas\n");
  printf("3. Sair\n");
  printf("***** ***** ***** ***** ***** ***** *****");

  printf("\nSelecione uma opção do menu acima: ");
  scanf("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}

  system("clear");

  return op;
}

// Função que insere um novo registro - nova música - no início da lista
// Declaração da função sem retorno e dos parâmetros que ela recebe
void inserirInicio (char *nomeFaixa, char *nomeArtista, float tempoFaixa)
{
  struct Musicas *novaMusica;
  // Alocar o novo elemento na memória, com o mesmo tamanho da estrutura
  novaMusica = (struct Musicas *)malloc(sizeof(struct Musicas));
  
  strcpy(novaMusica->nomeMusica, nomeFaixa);
  strcpy(novaMusica->nomeArtista, nomeArtista);
  novaMusica->tempoFaixa = tempoFaixa;

  // Se Head é null então a lista está vazia e a nova música será a primeira
  if (Head == NULL)
  {
    Head = novaMusica;
    Head->prox = NULL;
  }
  // Se Head contém registros, ele deixa de ser o Head e passa para a segunda posição da lista
  // E o novo elemento passa a ser o Head
  else
  {
    novaMusica->prox = Head;
    Head = novaMusica;
  }
}

// Declaração da função que vai exibir os registros na tela, com retorno vazio
void listar ()
{
  // Definindo um elemento que vai servir para percorrer a lista e exibir os dados
  Musicas *elementoVarredura;
  elementoVarredura = (struct Musicas *)malloc(sizeof(struct Musicas));

  elementoVarredura = Head;

  // Se não encontrar um Head, é porque a lista está vazia e informa o usuário
  if (elementoVarredura == NULL)
  {
    printf("Sua playlist ainda não contém músicas!");
    printf("\nPressione uma tecla para voltar ao menu e adicionar.");

    getchar();

    return;
  }

  // Laço que percorre a lista e vai exibindo os dados de cada elementeo na tela
  while (elementoVarredura != NULL)
  {
    printf("Música: %s | ", elementoVarredura->nomeMusica);
    printf("Artista: %s | ", elementoVarredura->nomeArtista);
    printf("Duração: %.2f \n\n", elementoVarredura->tempoFaixa);
    elementoVarredura = elementoVarredura->prox;
  }

  printf("Pressione uma tecla para voltar ao menu.");

  getchar();

  return; 
}
