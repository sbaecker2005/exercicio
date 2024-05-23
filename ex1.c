#include <stdio.h>

int main() {
    int n, i;
    float soma = 0.0;

    printf("Quantos elementos você deseja inserir no array? ");
    scanf("%d", &n);

    float array[n];

    for (i = 0; i < n; i++) {
        printf("Insira o elemento %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    for (i = 0; i < n; i++) {
        soma += array[i];
    }

    printf("A soma dos elementos do array é: %.2f\n", soma);

    return 0;
}

