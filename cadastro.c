#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define maximo_produtos 100
#define maximo_fornecedores 50
#define maximo_vendas 100
#define maximo_categoria 5

typedef struct {
    char nome[50];
    float preco;
    float precoCusto;
    int quantidade;
    char categoria[30];
} Produto;

typedef struct {
    char nome[50];
    char contato[50];
} Fornecedor;

typedef struct {
    char produtoNome[50];
    float lucro;
    char data[11];  
} Venda;

// funcoes para manipulação do inventário
void adicionarProduto(Produto **produtos, int *totalProdutos);
void salvarProdutosBinario(Produto *produtos, int totalProdutos);
void carregarProdutosBinario(Produto **produtos, int *totalProdutos);
void listarProdutosPorCategoria(Produto *produtos, int totalProdutos);
void venderProduto(Produto *produtos, int totalProdutos, Venda *vendas, int *totalVendas);
void gerarRelatorioEstoque(Produto *produtos, int totalProdutos);
void buscarProduto(Produto *produtos, int totalProdutos);
void removerProduto(Produto *produtos, int *totalProdutos);
void atualizarProduto(Produto *produtos, int totalProdutos);
void cadastrarFornecedor(Fornecedor **fornecedores, int *totalFornecedores);
void registrarHistoricoPreco(Produto produto);
void controleLucroDiario(Venda *vendas, int totalVendas);
void listarPorCategoria(Produto *produtos, int totalProdutos, char *categoria);

    void cadastrarFornecedor(Fornecedor **fornecedores, int *totalFornecedores) {
    if (*totalFornecedores >= maximo_fornecedores) {
        printf("Limite de fornecedores atingido.\n");
        return;
    }

    Fornecedor novoFornecedor;
    printf("Nome do fornecedor: ");
    fgets(novoFornecedor.nome, sizeof(novoFornecedor.nome), stdin);
    novoFornecedor.nome[strcspn(novoFornecedor.nome, "\n")] = 0;

    printf("Contato do fornecedor: ");
    fgets(novoFornecedor.contato, sizeof(novoFornecedor.contato), stdin);
    novoFornecedor.contato[strcspn(novoFornecedor.contato, "\n")] = 0;

    (*fornecedores)[*totalFornecedores] = novoFornecedor;
    (*totalFornecedores)++;
    printf("Fornecedor cadastrado com sucesso!\n");
}