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

typedef struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    int ano;

    int status; // 0 = disponível | 1 = emprestado
    char emailUsuario[100];

    struct Livro *prox;
} Livro;


typedef struct Usuario {
    char email[100];
    char nome[100];

    struct Usuario *prox;
} Usuario;

Livro *listaLivros = NULL;
Usuario *listaUsuarios = NULL;

int proximoID = 1;

void cadastrarLivro() {

    Livro *novo = (Livro *) malloc(sizeof(Livro));

    if(novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    novo->id = proximoID++;

    printf("\nTitulo: ");
    scanf(" %99[^\n]", novo->titulo); // %99 permite que o usuário digite espaços no título


    printf("Autor: ");
    scanf(" %99[^\n]", novo->autor);

    printf("Ano: ");
    scanf("%d", &novo->ano);

    novo->status = 0;

    strcpy(novo->emailUsuario, "");

    novo->prox = NULL;

    if(listaLivros == NULL) {
        listaLivros = novo;
    }
    else {

        Livro *aux = listaLivros;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    printf("\nLivro cadastrado com sucesso!\n");
    printf("ID gerado: %d\n", novo->id);
}

void cadastrarUsuario() {

    Usuario *novo = (Usuario *) malloc(sizeof(Usuario));

    if(novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }


    printf("\nE-mail: ");
    scanf("%s", novo->email);

    printf("Nome: ");
    scanf("%s", novo->nome);

    novo->prox = NULL;

    if(listaUsuarios == NULL) {

        listaUsuarios = novo;

    } else {

        Usuario *aux = listaUsuarios;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    printf("\nUsuário cadastrado com sucesso!\n");
}


int main() {

    int opcao;

    do {

        printf("\n=====================================\n");
        printf("      SISTEMA DE BIBLIOTECA\n");
        printf("=====================================\n");
        printf("1 - Cadastro\n");
        printf("2 - Consulta\n");
        printf("3 - Atualizacao\n");
        printf("4 - Exclusao\n");
        printf("5 - Emprestimo\n");
        printf("6 - Devolucao\n");
        printf("0 - Sair\n");
        printf("=====================================\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {

            int opcaoCadastro;

            printf("\n=== MENU CADASTRO ===\n");
            printf("1 - Livro\n");
            printf("2 - Usuario\n");
            printf("0 - Voltar\n");

            printf("Opcao: ");
            scanf("%d", &opcaoCadastro);

            if(opcaoCadastro == 1) {

                cadastrarLivro();

            }
            else if(opcaoCadastro == 2) {

                cadastrarUsuario();

            }
            else if(opcaoCadastro == 0) {

                printf("Voltando ao menu principal...\n");

            }
            else {

                printf("Opcao invalida!\n");

            }

        }
        else if(opcao == 2) {

            int opcaoConsulta;

            printf("\n=== MENU CONSULTA ===\n");
            printf("1 - Livros\n");
            printf("2 - Usuarios\n");
            printf("3 - Emprestimos\n");
            printf("0 - Voltar\n");

            printf("Opcao: ");
            scanf("%d", &opcaoConsulta);

            if(opcaoConsulta == 1) {

                printf("Consulta de livros\n");

            }
            else if(opcaoConsulta == 2) {

                printf("Consulta de usuarios\n");

            }
            else if(opcaoConsulta == 3) {

                printf("Consulta de emprestimos\n");

            }
            else if(opcaoConsulta == 0) {

                printf("Voltando...\n");

            }
            else {

                printf("Opcao invalida!\n");

            }

        }
        else if(opcao == 3) {

            int opcaoAtualizacao;

            printf("\n=== MENU ATUALIZACAO ===\n");
            printf("1 - Livros\n");
            printf("2 - Usuarios\n");
            printf("0 - Voltar\n");

            printf("Opcao: ");
            scanf("%d", &opcaoAtualizacao);

            if(opcaoAtualizacao == 1) {

                printf("Atualizacao de livros\n");

            }
            else if(opcaoAtualizacao == 2) {

                printf("Atualizacao de usuarios\n");

            }
            else if(opcaoAtualizacao == 0) {

                printf("Voltando...\n");

            }
            else {

                printf("Opcao invalida!\n");

            }

        }
        else if(opcao == 4) {

            int opcaoExclusao;

            printf("\n=== MENU EXCLUSAO ===\n");
            printf("1 - Livros\n");
            printf("2 - Usuarios\n");
            printf("0 - Voltar\n");

            printf("Opcao: ");
            scanf("%d", &opcaoExclusao);

            if(opcaoExclusao == 1) {

                printf("Exclusao de livros\n");

            }
            else if(opcaoExclusao == 2) {

                printf("Exclusao de usuarios\n");

            }
            else if(opcaoExclusao == 0) {

                printf("Voltando...\n");

            }
            else {

                printf("Opcao invalida!\n");

            }

        }
        else if(opcao == 5) {

            printf("\nEmprestimo de livro\n");

        }
        else if(opcao == 6) {

            printf("\nDevolucao de livro\n");

        }
        else if(opcao == 0) {

            printf("\nEncerrando sistema...\n");

        }
        else {

            printf("\nOpcao invalida!\n");

        }

    } while(opcao != 0);

    return 0;
}