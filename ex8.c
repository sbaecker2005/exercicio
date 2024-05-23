#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array
int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int*)malloc(tamanho * sizeof(int)); // Aloca memória para o novo array invertido

    if (arrayInvertido == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro: Falha ao alocar memória.\n");
        return NULL;
    }

    // Preenche o novo array invertido
    for (int i = 0; i < tamanho; i++) {
        *(arrayInvertido + i) = *(array + tamanho - 1 - i);
    }

    return arrayInvertido;
}

// Função para imprimir um array
void imprimirArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int main() {
    int arrayOriginal[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arrayOriginal) / sizeof(arrayOriginal[0]);

    printf("Array original: ");
    imprimirArray(arrayOriginal, tamanho);

    // Chama a função para inverter o array
    int *arrayInvertido = inverterArray(arrayOriginal, tamanho);
    if (arrayInvertido != NULL) {
        printf("Array invertido: ");
        imprimirArray(arrayInvertido, tamanho);

        // Libera a memória alocada para o array invertido
        free(arrayInvertido);
    }

    return 0;
}
