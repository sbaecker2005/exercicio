#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

void cadastrarProduto(struct Produto *produto) {
    printf("Nome do produto: ");
    scanf("%s", produto->nome);
    printf("Preço do produto: ");
    scanf("%f", &produto->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produto->quantidade);
}

void exibirProduto(struct Produto produto) {
    printf("\nNome: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}

float calcularValorTotal(struct Produto *produtos, int tamanho) {
    float valorTotal = 0;
    for (int i = 0; i < tamanho; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return valorTotal;
}

int main() {
    int opcao, numProdutos = 0;
    struct Produto *produtos = NULL;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produtos cadastrados\n");
        printf("3. Calcular valor total em estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                produtos = (struct Produto *) realloc(produtos, (numProdutos + 1) * sizeof(struct Produto));
                if (produtos == NULL) {
                    printf("Erro ao alocar memória!\n");
                    return 1;
                }
               
                cadastrarProduto(&produtos[numProdutos]);
                numProdutos++;
                break;
            case 2:
                
                printf("\n=== Produtos Cadastrados ===\n");
                for (int i = 0; i < numProdutos; i++) {
                    exibirProduto(produtos[i]);
                }
                break;
            case 3:
                
                printf("\nValor total em estoque: R$ %.2f\n", calcularValorTotal(produtos, numProdutos));
                break;
            case 4:
                printf("Encerrando o programa...\n");
                
                free(produtos);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
