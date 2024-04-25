#ifndef JOIAS_H
#define JOIAS_H

#define MAX_EMAIL_LENGTH 80
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct Usuario Usuario;
typedef struct Produto Produto;
typedef struct no_usuario NoUsuario;
typedef struct listaUsuarios ListaUsuarios;
typedef struct no_produto NoProduto;
typedef struct listaProdutos ListaProdutos;

void lerUsuarios(ListaUsuarios *lista, const char *fileName);
void lerProdutos(ListaProdutos *lista, const char *fileName);
int login(ListaUsuarios *lista, const char *email, const char *senha);
void cadastrarUsuario(ListaUsuarios *lista, const char *fileName);
void cadastrarProduto(ListaProdutos *lista, const char *fileName);
void listarProdutos(ListaProdutos *lista);
void listarProdutosEmPromocao(ListaProdutos *lista);
void listarProdutosPorCategoria(ListaProdutos *lista, const char *categoria);
void buscarProduto(ListaProdutos *lista, const char *nome);

#endif /* JOIAS_H */
