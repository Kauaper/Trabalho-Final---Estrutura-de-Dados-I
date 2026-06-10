// pensar na estrutura inicial do projeto

typedef struct Usuario {
    char email[100];
    char nome[100];

    struct Usuario *prox;
} Usuario;

typedef struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    int ano;

    int status; // depois para usar 0 = disponivel e 1 = emprestado
    char emailUsuario[100];

    struct Livro *prox;
} Livro;

//funcoes para os livros

void cadastrarLivro();
Livro* buscarLivroPorID(int id);
void buscarLivroPorAutor(char autor[]);
void atualizarLivro();
void excluirLivro();

//funcoes para o usuario

void cadastrarUsuario();
Usuario* buscarUsuarioPorEmail(char email[]);
void buscarUsuarioPorNome(char nome[]);
void atualizarUsuario();
void excluirUsuario();

//funcao emprestimo

void emprestarLivro();

//funcao devolucao

void devolverLivro();

//lembrar de incluir os menus!!

//principal
1 Cadastro
2 Consulta
3 Atualização
4 Exclusão
5 Empréstimo
6 Devolução
0 Sair

//cadastro

1 Livros
2 Usuários
0 Voltar

//consulta

1 Livros
2 Usuários
3 Empréstimos
0 Voltar

//atualizacao

1 Livros
2 Usuários
0 Voltar

//exclusão

1 Livros
2 Usuários
0 Voltar
