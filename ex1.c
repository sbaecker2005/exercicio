#include <stdio.h>

int main() {
    int n, i;
    float soma = 0.0;

    // Solicita ao usuário o número de elementos
    printf("Quantos elementos você deseja inserir no array? ");
    scanf("%d", &n);

    // Declara o array
    float array[n];

    // Solicita ao usuário a inserção dos elementos
    for (i = 0; i < n; i++) {
        printf("Insira o elemento %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    // Calcula a soma dos elementos
    for (i = 0; i < n; i++) {
        soma += array[i];
    }

    // Exibe a soma dos elementos
    printf("A soma dos elementos do array é: %.2f\n", soma);

    return 0;
}

