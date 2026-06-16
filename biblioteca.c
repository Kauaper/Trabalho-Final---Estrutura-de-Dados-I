#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Trabalho Final - Estrutura de Dados I
Sistema de Controle de Biblioteca

Foi utilizada uma LLM (ChatGPT) como ferramenta de apoio para:

parte visual do menu de escolhas

Todo o código foi revisado, adaptado e compreendido pelos alunos.
*/

int main() {

int opcao;

do {

    printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
    printf("1 - Cadastro\n");
    printf("2 - Consulta\n");
    printf("3 - Atualizacao\n");
    printf("4 - Exclusao\n");
    printf("5 - Emprestimo\n");
    printf("6 - Devolucao\n");
    printf("0 - Sair\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {

        case 1:
            printf("Menu Cadastro\n");
            break;

        case 2:
            printf("Menu Consulta\n");
            break;

        case 3:
            printf("Menu Atualizacao\n");
            break;

        case 4:
            printf("Menu Exclusao\n");
            break;

        case 5:
            printf("Emprestimo\n");
            break;

        case 6:
            printf("Devolucao\n");
            break;

        case 0:
            printf("Encerrando sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

} while(opcao != 0);

return 0;

}