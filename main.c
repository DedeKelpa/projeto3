#include <stdio.h>
#include "projeto3.h"
// David Gabriel de Souza Batista RA:22.123.056-8



int main() {
    Tarefa tarefas[100];
    int qtd = 0;

    carregarTarefas(tarefas, &qtd);



    int opcao;
    do {
        printf("\n Menu\n");
        printf("1) Cadastrar tarefa\n");
        printf("2) Listar tarefas\n");
        printf("3) Deletar tarefa\n");
        printf("4) Salvar tarefas\n");
        printf("5) Alterar tarefas\n");
        printf("6) Filtrar por prioridade.\n");
        printf("7) Filtrar por estado.\n");
        printf("8) Filtrar por categoria.\n");
        printf("9) Filtrar por prioridade e categoria.\n");
        printf("10) Exportar em arquivo por prioridade.\n");
        printf("11) Exportar em arquivo por categoria\n");
        printf("12) Exportar em arquivo por prioridade e categoria\n");
        printf("13) Sair\n");
        printf("Digite a acao que quer realizar : ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &qtd);
                break;
            case 2:
                listarTarefas(tarefas, qtd);
                break;
            case 3:
                deletarTarefa(tarefas, &qtd);
                break;
            case 4:
                salvarTarefas(tarefas, qtd);
                break;
            case 5:
                alterarTarefa(tarefas, &qtd);
                break;
            case 6:
                filtrarPrioridade(tarefas, qtd);
                break;
            case 7:
                filtrarEstado(tarefas,qtd);
                break;
            case 8:
                filtrarCategoriaCrescente(tarefas,qtd);
                break;
            case 9:
              filtrarPrioridadeECategoria(tarefas,qtd);
                break;
            case 10:
              arquivoPrioridade(tarefas,qtd);
                break;
            case 11:
              arquivoCategoriaCrescente(tarefas, qtd);
                break;
            case 12:
              arquivoPrioridadeECategoria(tarefas,qtd);
                break;
            case 13:
              printf("Fechando programa.\n");
              break;
            default:
                printf("Tente outra acao.\n");
        }
    } while (opcao != 13);

    return 0;
}
