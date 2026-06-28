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

void consultarLivro() {

    int opcao;

    printf("\n=== CONSULTA DE LIVROS ===\n");
    printf("1 - Por ID\n");
    printf("2 - Por Autor\n");
    printf("0 - Voltar\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    if(opcao == 1) {

        int id;

        printf("ID: ");
        scanf("%d", &id);

        Livro *aux = listaLivros;

        while(aux != NULL) {

            if(aux->id == id) {

                printf("\n===== LIVRO =====\n");
                printf("ID: %d\n", aux->id);
                printf("Titulo: %s\n", aux->titulo);
                printf("Autor: %s\n", aux->autor);
                printf("Ano: %d\n", aux->ano);

                if(aux->status == 0)
                    printf("Status: Disponivel\n");
                else
                    printf("Status: Emprestado\n");

                return;
            }

            aux = aux->prox;
        }

        printf("\nLivro nao encontrado.\n");

    }
    else if(opcao == 2) {

        char autor[100];
        int encontrou = 0;

        printf("Autor: ");
        scanf(" %99[^\n]", autor);

        Livro *aux = listaLivros;

        while(aux != NULL) {

            if(strcmp(aux->autor, autor) == 0) {

                encontrou = 1;

                printf("\n---------------------\n");
                printf("ID: %d\n", aux->id);
                printf("Titulo: %s\n", aux->titulo);
                printf("Ano: %d\n", aux->ano);

            }

            aux = aux->prox;
        }

        if(!encontrou)
            printf("\nLivro nao encontrado.\n");

    }

}

void consultarUsuario() {

    int opcao;

    printf("\n=== CONSULTA DE USUARIOS ===\n");
    printf("1 - Por Email\n");
    printf("2 - Por Nome\n");
    printf("0 - Voltar\n");

    printf("Opcao: ");
    scanf("%d",&opcao);

    if(opcao == 1){

        char email[100];

        printf("Email: ");
        scanf("%s",email);

        Usuario *aux = listaUsuarios;

        while(aux != NULL){

            if(strcmp(aux->email,email)==0){

                printf("\nNome: %s\n",aux->nome);
                printf("Email: %s\n",aux->email);

                return;
            }

            aux = aux->prox;
        }

        printf("\nUsuario nao cadastrado.\n");

    }

    else if(opcao == 2){

        char nome[100];

        printf("Nome: ");
        scanf(" %99[^\n]",nome);

        Usuario *aux = listaUsuarios;

        while(aux != NULL){

            if(strcmp(aux->nome,nome)==0){

                printf("\nNome: %s\n",aux->nome);
                printf("Email: %s\n",aux->email);

                return;
            }

            aux = aux->prox;
        }

        printf("\nUsuario nao cadastrado.\n");

    }

}

void consultarEmprestimos() {

    char email[100];
    int encontrou = 0;

    printf("Email do usuario: ");
    scanf("%s", email);

    Livro *aux = listaLivros;

    while(aux != NULL){

        if(strcmp(aux->emailUsuario,email)==0){

            encontrou = 1;

            printf("\n-----------------\n");
            printf("ID: %d\n",aux->id);
            printf("Titulo: %s\n",aux->titulo);
            printf("Autor: %s\n",aux->autor);

        }

        aux = aux->prox;
    }

    if(!encontrou){

        printf("\nNenhum livro emprestado para este usuario.\n");

    }

}

void atualizarLivro(){

    int id;

    printf("\nID do livro: ");
    scanf("%d",&id);

    Livro *aux = listaLivros;

    while(aux != NULL){

        if(aux->id == id){

            printf("\nNovo titulo: ");
            scanf(" %99[^\n]",aux->titulo);

            printf("Novo autor: ");
            scanf(" %99[^\n]",aux->autor);

            printf("Novo ano: ");
            scanf("%d",&aux->ano);

            printf("\nLivro atualizado com sucesso!\n");

            return;
        }

        aux = aux->prox;
    }

    printf("\nLivro nao encontrado!\n");
}

void atualizarUsuario(){

    char email[100];

    printf("\nEmail do usuario: ");
    scanf("%99s",email);

    Usuario *aux = listaUsuarios;

    while(aux != NULL){

        if(strcmp(aux->email,email) == 0){

            printf("Novo nome: ");
            scanf(" %99[^\n]",aux->nome);

            printf("\nUsuario atualizado com sucesso!\n");

            return;
        }

        aux = aux->prox;
    }

    printf("\nUsuario nao encontrado!\n");
}

void excluirLivro(){

    int id;

    printf("\nID do livro: ");
    scanf("%d",&id);

    Livro *atual = listaLivros;
    Livro *anterior = NULL;

    while(atual != NULL && atual->id != id){

        anterior = atual;
        atual = atual->prox;

    }

    if(atual == NULL){

        printf("\nLivro nao encontrado!\n");
        return;

    }

    // Não permite excluir livro emprestado
    if(atual->status == 1){

        printf("\nNao e possivel excluir um livro emprestado!\n");
        return;

    }

    if(anterior == NULL){

        listaLivros = atual->prox;

    }else{

        anterior->prox = atual->prox;

    }

    free(atual);

    printf("\nLivro excluido com sucesso!\n");
}

void excluirUsuario(){

    char email[100];

    printf("\nEmail do usuario: ");
    scanf("%99s", email);

    Usuario *atual = listaUsuarios;
    Usuario *anterior = NULL;

    while(atual != NULL && strcmp(atual->email, email) != 0){

        anterior = atual;
        atual = atual->prox;

    }

    if(atual == NULL){

        printf("\nUsuario nao encontrado!\n");
        return;

    }

    // Verifica se o usuário possui livros emprestados
    Livro *livro = listaLivros;

    while(livro != NULL){

        if(strcmp(livro->emailUsuario, email) == 0){

            printf("\nNao e possivel excluir um usuario com livros emprestados!\n");
            return;

        }

        livro = livro->prox;
    }

    if(anterior == NULL){

        listaUsuarios = atual->prox;

    }else{

        anterior->prox = atual->prox;

    }

    free(atual);

    printf("\nUsuario excluido com sucesso!\n");
}

void emprestarLivro(){

    int id;
    char email[100];

    printf("\nID do livro: ");
    scanf("%d",&id);

    Livro *livro = listaLivros;

    while(livro != NULL && livro->id != id){
        livro = livro->prox;
    }

    if(livro == NULL){
        printf("\nLivro nao encontrado!\n");
        return;
    }

    if(livro->status == 1){
        printf("\nLivro ja esta emprestado!\n");
        return;
    }

    printf("Email do usuario: ");
    scanf("%99s", email);

    Usuario *usuario = listaUsuarios;

    while(usuario != NULL && strcmp(usuario->email, email) != 0){
        usuario = usuario->prox;
    }

    if(usuario == NULL){
        printf("\nUsuario nao encontrado!\n");
        return;
    }

    livro->status = 1;
    strcpy(livro->emailUsuario, email);

    printf("\nLivro emprestado com sucesso!\n");
}

void devolverLivro(){

    int id;

    printf("\nID do livro: ");
    scanf("%d",&id);

    Livro *livro = listaLivros;

    while(livro != NULL && livro->id != id){
        livro = livro->prox;
    }

    if(livro == NULL){
        printf("\nLivro nao encontrado!\n");
        return;
    }

    if(livro->status == 0){
        printf("\nEste livro nao esta emprestado!\n");
        return;
    }

    livro->status = 0;
    strcpy(livro->emailUsuario, "");

    printf("\nLivro devolvido com sucesso!\n");
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

                consultarLivro();

            }
            else if(opcaoConsulta == 2) {

                consultarUsuario();

            }
            else if(opcaoConsulta == 3) {

                consultarEmprestimos();

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

                atualizarLivro();

            }
            else if(opcaoAtualizacao == 2) {

                atualizarUsuario();

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

                excluirLivro();

            }
            else if(opcaoExclusao == 2) {

                excluirUsuario();

            }
            else if(opcaoExclusao == 0) {

                printf("Voltando...\n");

            }
            else {

                printf("Opcao invalida!\n");

            }

        }
        else if(opcao == 5) {

            emprestarLivro();

        }
        else if(opcao == 6) {

            devolverLivro();

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