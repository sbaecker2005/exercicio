#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int*)malloc(tamanho * sizeof(int)); 

    if (arrayInvertido == NULL) { 
        printf("Erro: Falha ao alocar memória.\n");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        *(arrayInvertido + i) = *(array + tamanho - 1 - i);
    }

    return arrayInvertido;
}

void imprimirArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *arrayOriginal = (int*)malloc(tamanho * sizeof(int));
    if (arrayOriginal == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arrayOriginal[i]);
    }

    printf("Array original: ");
    imprimirArray(arrayOriginal, tamanho);

    int *arrayInvertido = inverterArray(arrayOriginal, tamanho);
    if (arrayInvertido != NULL) {
        printf("Array invertido: ");
        imprimirArray(arrayInvertido, tamanho);

        free(arrayInvertido);
    }

    free(arrayOriginal);
    return 0;
}
