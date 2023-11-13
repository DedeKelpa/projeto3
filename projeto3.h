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
void filtrarPrioridade(Tarefa tarefas[], int qtd);
void filtrarEstado(Tarefa tarefas[], int qtd);
void filtrarPrioridadeECategoria(Tarefa tarefas[], int qtd);
void filtrarCategoriaCrescente(Tarefa tarefas[], int qtd);
void arquivoPrioridade(Tarefa tarefas[], int qtd);
void arquivoCategoriaCrescente(Tarefa tarefas[], int qtd);
void arquivoPrioridadeECategoria(Tarefa tarefas[], int qtd);
#endif // PROJETO3FINAL_PROJETO_H
