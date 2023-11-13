#include "projeto.h"
#include <stdio.h>

void cadastrarTarefa(Tarefa tarefas[], int *qtd) {
    if (*qtd >= 100) {
        printf("O limite máximo de tarefas foi atingido .\n"); // Verifica se a quantidade limite de tarefas foi atingida.
        return;
    }

// Se o limite máximo não foi atingido, cadastra a tarefa de acordo com o que o usuário digitar.
    printf("Descricao Da Tarefa: ");
    scanf(" %s", tarefas[*qtd].descricao);

    printf("Categoria Da Tarefa: ");
    scanf("%s", tarefas[*qtd].categoria);

    printf("Prioridade Da Tarefa: ");
    scanf("%d", &tarefas[*qtd].prioridade);

    (*qtd)++;
}
// Função que adiciona a tarefa que o usuário desejar.


void listarTarefas(Tarefa tarefas[], int qtd) {
    if (qtd == 0) {
        printf("Sem tarefas cadastradas.\n"); // Verifica se há tarefas na lista.
        return;
    }

    // Caso tenha, o laço for percorre a lista de tarefas printando as tarefas digitadas pelo usuário em ordem.
    printf(" Lista de Tarefas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("\n");
    }
}
// Função que lista todas as tarefas adicionadas pelo usuário.


void deletarTarefa(Tarefa tarefas[], int *qtd) {
  int indice;
  if (*qtd == 0) {
    printf("Nenhuma tarefa para deletar.\n");
    return;
  }

  printf("Digite o índice da tarefa que deseja deletar: ");
  scanf("%d", &indice);

  if (indice >= 1 && indice <= *qtd) {
    for (int i = indice - 1; i < *qtd - 1; i++) {
      tarefas[i] = tarefas[i + 1];
    }
    (*qtd)--;
    printf("Tarefa deletada com sucesso.\n");
  } else {
    printf("Índice inválido.\n");
  }
}

void salvarTarefas(Tarefa tarefas[], int qtd) {
  FILE *openfile = fopen("tarefas.txt", "wb");
  if (openfile == NULL) {
    printf("Erro ao abrir.\n"); // Caso haja algum erro ao abrir o arquivo, uma  // mensagem de erro é printada.
    return;
  }

  fwrite(&qtd, sizeof(int), 1,
         openfile); // Escreve a quantidade de tarefas no arquivo.

  fwrite(tarefas, sizeof(Tarefa), qtd,
         openfile); // Escreve o conteúdo de cada tarefa.

  fclose(openfile);
}

// Função que salva as tarefas do programa no arquivo

void carregarTarefas(Tarefa tarefas[], int *qtd) {
  FILE *openfile = fopen("tarefas.txt", "rb");
  if (openfile == NULL) {
    printf("Arquivo nao encontrado.\n"); // Caso haja algum erro ao abrir o  // arquivo, umamensagem de erro é   // printada
    return;
  }

  fread(qtd, sizeof(int), 1,
        openfile); // Lê a quantidade de tarefas no arquivo.

  fread(tarefas, sizeof(Tarefa), *qtd,
        openfile); // Lê o conteúdo de cada tarefa.

  fclose(openfile);
}


void alterarTarefa(Tarefa tarefas[], int *qtd) {
  int indice;
  printf("Digite o índice da tarefa que deseja alterar: ");
  scanf("%d", &indice);

  if (indice >= 1 && indice <= qtd) {
    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Categoria\n");
    printf("3. Estado\n");
    printf("4. Descricao\n");
    printf("Digite sua escolha: ");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("Digite a nova Prioridade: ");
      scanf("%d", &tarefas[indice - 1].prioridade);
      break;
    case 2:
      printf("Digite a nova Categoria: ");
      scanf(" %[^\n]s", tarefas[indice - 1].categoria);
      break;
    case 3:
      printf("Digite o novo Estado: ");
      scanf("%[^\n]s", tarefas[indice - 1].estado);
      break;
    case 4:
      printf("Digite a nova Descricao: ");
      scanf("%[^\n]s", tarefas[indice - 1].descricao);
      break;
    default:
      printf("Opção inválida.\n");
    }
  } else {
    printf("Índice inválido.\n");
  }
}
