#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

int compararPorIdade(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;
    return pessoaA->idade - pessoaB->idade;
}

void imprimirPessoas(Pessoa *pessoas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }
}

int main() {
    int n;

    printf("Digite o número de pessoas: ");
    scanf("%d", &n);
    getchar(); 

    Pessoa *pessoas = (Pessoa *)malloc(n * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, 100, stdin);
        size_t len = strlen(pessoas[i].nome);
        if (len > 0 && pessoas[i].nome[len - 1] == '\n') {
            pessoas[i].nome[len - 1] = '\0';
        }

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        getchar(); // Limpa o buffer do '\n' deixado pelo scanf
    }

    qsort(pessoas, n, sizeof(Pessoa), compararPorIdade);

    printf("\nPessoas ordenadas por idade:\n");
    imprimirPessoas(pessoas, n);

    free(pessoas);

    return 0;
}
