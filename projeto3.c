#include "projeto3.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrarTarefa(Tarefa tarefas[], int *qtd) {
  if (*qtd >= 100) {
    printf(
        "O limite máximo de tarefas foi atingido .\n"); // Verifica se a
                                                        // quantidade limite de
                                                // tarefas foi atingida.
    return;
  }

  // Se o limite máximo não foi atingido, cadastra a tarefa de acordo com o que
  // o usuário digitar.
  printf("Descricao Da Tarefa: ");
  scanf(" %s", tarefas[*qtd].descricao);

  printf("Categoria Da Tarefa: ");
  scanf("%s", tarefas[*qtd].categoria);

  printf("Prioridade Da Tarefa: ");
  scanf("%d", &tarefas[*qtd].prioridade);

  printf("Estado da Tarefa: ");
  scanf("%s", tarefas[*qtd].estado);

  (*qtd)++;
}
// Função que adiciona a tarefa que o usuário desejar.

void listarTarefas(Tarefa tarefas[], int qtd) {
  if (qtd == 0) {
    printf("Sem tarefas cadastradas.\n"); // Verifica se há tarefas na lista.
    return;
  }

  // Caso tenha, o laço for percorre a lista de tarefas printando as tarefas
  // digitadas pelo usuário em ordem.
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

void filtrarPrioridade(Tarefa tarefas[], int qtd) {
  int prioridadeDesejada;
  printf("Digite a prioridade desejada: ");
  scanf("%d", &prioridadeDesejada);

  int prioridadeEncontrada = 0;
  for (int i = 0; i < qtd; i++) {
    if (tarefas[i].prioridade == prioridadeDesejada) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefas[i].descricao);
      printf("Categoria: %s\n", tarefas[i].categoria);
      printf("Prioridade: %d\n", tarefas[i].prioridade);
      printf("Estado: %s\n", tarefas[i].estado);
      printf("\n");
      prioridadeEncontrada++;
    }
  }

  if (prioridadeEncontrada == 0) {
    printf("Nenhuma tarefa encontrada com prioridade %d ou superior.\n",
           prioridadeDesejada);
  }
}

void filtrarEstado(Tarefa tarefas[], int qtd) {
  char estadoDesejado[100];
  printf("Digite o estado desejado: ");
  scanf("%s", estadoDesejado);

  int estadoEncontrado = 0;
  for (int i = 0; i < qtd; i++) {
    if (strcmp(tarefas[i].estado, estadoDesejado) == 0) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefas[i].descricao);
      printf("Categoria: %s\n", tarefas[i].categoria);
      printf("Prioridade: %d\n", tarefas[i].prioridade);
      printf("Estado: %s\n", tarefas[i].estado);
      printf("\n");
      estadoEncontrado++;
    }
  }

  if (estadoEncontrado == 0) {
    printf("Nenhuma tarefa encontrada com o estado %s.\n", estadoDesejado);
  }
}

int compararPorPrioridade(const void *a, const void *b) {
  return ((Tarefa *)a)->prioridade - ((Tarefa *)b)->prioridade;
}

void filtrarCategoriaCrescente(Tarefa tarefas[], int qtd) {
  char categoriaDesejada[100];

  printf("Digite a categoria desejada: ");
  scanf("%s", categoriaDesejada);

  Tarefa tarefasCategoria[100];
  int qtdCategoria = 0;

  for (int i = 0; i < qtd; i++) {
    if (strcmp(tarefas[i].categoria, categoriaDesejada) == 0) {
      tarefasCategoria[qtdCategoria] = tarefas[i];
      qtdCategoria++;
    }
  }

  if (qtdCategoria == 0) {
    printf("Nenhuma tarefa encontrada na categoria %s.\n", categoriaDesejada);
    return;
  }

  qsort(tarefasCategoria, qtdCategoria, sizeof(Tarefa), compararPorPrioridade);

  printf("Tarefas na categoria %s, ordenadas por prioridade crescente:\n",
         categoriaDesejada);
  for (int i = 0; i < qtdCategoria; i++) {
    printf("Tarefa %d:\n", i + 1);
    printf("Descricao: %s\n", tarefasCategoria[i].descricao);
    printf("Categoria: %s\n", tarefasCategoria[i].categoria);
    printf("Prioridade: %d\n", tarefasCategoria[i].prioridade);
    printf("Estado: %s\n", tarefasCategoria[i].estado);
    printf("\n");
  }
}

void filtrarPrioridadeECategoria(Tarefa tarefas[], int qtd) {
  char categoriaDesejada[100];
  int prioridadeDesejada;
  printf("Digite a prioridade desejada: ");
  scanf("%d", &prioridadeDesejada);

  printf("Digite a categoria desejada: ");
  scanf("%s", categoriaDesejada);

  int prioridadeECategoriaDesejada = 0;
  for (int i = 0; i < qtd; i++) {
    if (tarefas[i].prioridade == prioridadeDesejada &&
        strcmp(tarefas[i].categoria, categoriaDesejada) == 0) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefas[i].descricao);
      printf("Categoria: %s\n", tarefas[i].categoria);
      printf("Prioridade: %d\n", tarefas[i].prioridade);
      printf("Estado: %s\n", tarefas[i].estado);
      printf("\n");
      prioridadeECategoriaDesejada++;
    }
  }

  if (prioridadeECategoriaDesejada == 0) {
    printf("Nenhuma tarefa encontrada com prioridade %d e categoria %s.\n",
           prioridadeDesejada, categoriaDesejada);
  }
}

void arquivoPrioridade(Tarefa tarefas[], int qtd) {
  int prioridadeDesejada;
  printf("Digite a prioridade desejada para o arquivo: ");
  scanf("%d", &prioridadeDesejada);
  FILE *arquivo = fopen("arquivoPrioridade.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para exportar tarefas.\n");
    return;
  }

  for (int i = 0; i < qtd; i++) {
    if (tarefas[i].prioridade == prioridadeDesejada) {
      fprintf(arquivo, "%d, %s, %s, %s\n", tarefas[i].prioridade,
              tarefas[i].categoria, tarefas[i].descricao, tarefas[i].estado);
    }
  }

  fclose(arquivo);
}

void arquivoCategoriaCrescente(Tarefa tarefas[], int qtd) {
  char categoriaDesejada[100];

  printf("Digite a categoria desejada: ");
  scanf("%s", categoriaDesejada);

  FILE *arquivo = fopen("arquivoCategoria.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para exportar tarefas.\n");
    return;
  }
  Tarefa tarefasCategoria[100];

  int qtdCategoria = 0;

  for (int i = 0; i < qtd; i++) {
    if (strcmp(tarefas[i].categoria, categoriaDesejada) == 0) {
      tarefasCategoria[qtdCategoria] = tarefas[i];
      qtdCategoria++;
    }
  }

  if (qtdCategoria == 0) {
    printf("Nenhuma tarefa encontrada na categoria %s.\n", categoriaDesejada);
    fclose(arquivo);
    return;
  }
  qsort(tarefasCategoria, qtdCategoria, sizeof(Tarefa), compararPorPrioridade);

  for (int i = 0; i < qtdCategoria; i++) {
    fprintf(arquivo, "%d, %s, %s, %s\n", tarefasCategoria[i].prioridade,
            tarefasCategoria[i].categoria, tarefasCategoria[i].descricao,
            tarefasCategoria[i].estado);
  }

  fclose(arquivo);
  printf("Tarefas exportadas com sucesso para o arquivo "
         "'arquivoCategoria.txt'.\n");
}

void arquivoPrioridadeECategoria(Tarefa tarefas[], int qtd) {
  int prioridadeDesejada;
  char categoriaDesejada[100];

  printf("Digite a prioridade desejada: ");
  scanf("%d", &prioridadeDesejada);

  printf("Digite a categoria desejada: ");
  scanf("%s", categoriaDesejada);

  FILE *arquivo = fopen("arquivoPrioridadeECategoria.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para exportar tarefas.\n");
    return;
  }

  for (int i = 0; i < qtd; i++) {
    if (tarefas[i].prioridade == prioridadeDesejada &&
        strcmp(tarefas[i].categoria, categoriaDesejada) == 0) {
      fprintf(arquivo, "%d, %s, %s, %s\n", tarefas[i].prioridade,
              tarefas[i].categoria, tarefas[i].descricao, tarefas[i].estado);
    }
  }

  fclose(arquivo);
  printf("Tarefas exportadas com sucesso para o arquivo "
         "'arquivoPrioridadeECategoria.txt'.\n");
}
