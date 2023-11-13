#ifndef PROJETO3FINAL_PROJETO_H
#define PROJETO3FINAL_PROJETO_H

typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char estado[100];
} Tarefa;

void cadastrarTarefa(Tarefa tarefas[], int *qtd);
void listarTarefas(Tarefa tarefas[], int qtd);
void deletarTarefa(Tarefa tarefas[], int *qtd);
void salvarTarefas(Tarefa tarefas[], int qtd);
void carregarTarefas(Tarefa tarefas[], int *qtd);
void alterarTarefa(Tarefa tarefas[], int *qtd);
