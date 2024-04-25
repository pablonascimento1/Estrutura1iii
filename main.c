#include <stdio.h>
#include <stdlib.h>
#include "joias.h"

int listaUsuarios = 0;
int listaProdutos = 0;

int main() {
  struct ListaUsuarios listaUsuarios;
   
  listaUsuarios.inicio = NULL;

  struct ListaProdutos listaProdutos;
  
  listaProdutos.inicio = NULL;

    const char usuariosFileName[] = "usuarios.txt";
    const char produtosFileName[] = "produtos.txt";

    printf("Bem-vindo à Loja de Joias!\n");

    lerUsuarios(listaUsuarios, usuariosFileName);
    lerProdutos(listaProdutos, produtosFileName);

    int opcao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar Usuário\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                char email[MAX_EMAIL_LENGTH];
                char senha[20];
                printf("Informe seu e-mail para login:\n");
                scanf("%19s", email); // evitar buffer overflow
                printf("Informe sua senha para login:\n");
                scanf("%19s", senha); // evitar buffer overflow
                if (login(listaUsuarios, email, senha)) {
                    printf("Login realizado com sucesso!\n");
                    int opcaoLogado;
                    do {
                        printf("\nEscolha uma opção:\n");
                        printf("1 - Cadastrar Produto\n");
                        printf("2 - Listar Produtos\n");
                        printf("3 - Listar Produtos em Promoção\n");
                        printf("4 - Listar Produtos por Categoria\n");
                        printf("5 - Buscar Produto\n");
                        printf("0 - Sair\n");
                        scanf("%d", &opcaoLogado);

                        switch(opcaoLogado) {
                            case 1:
                                cadastrarProduto(listaProdutos, produtosFileName);
                                break;
                            case 2:
                                listarProdutos(listaProdutos);
                                break;
                            case 3:
                                listarProdutosEmPromocao(listaProdutos);
                                break;
                            case 4: {
                                char categoria[MAX_CATEGORY_LENGTH];
                                printf("Informe a categoria dos produtos a serem listados:\n");
                                scanf("%19s", categoria); // evitar buffer overflow
                                listarProdutosPorCategoria(listaProdutos, categoria);
                                break;
                            }
                            case 5: {
                                char nome[MAX_NAME_LENGTH];
                                printf("Informe o nome do produto a ser buscado:\n");
                                scanf("%19s", nome); // evitar buffer overflow
                                buscarProduto(listaProdutos, nome);
                                break;
                            }
                            case 0:
                                printf("Saindo...\n");
                                break;
                            default:
                                printf("Opção inválida. Tente novamente.\n");
                        }
                    } while(opcaoLogado!= 0);
                } else {
                    printf("E-mail ou senha incorretos.\n");
                }
                break;
            }
            case 2:
                cadastrarUsuario(listaUsuarios, usuariosFileName);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao!= 0);

    free(listaUsuarios);
    free(listaProdutos);

    return 0;
}