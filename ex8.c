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
    int arrayOriginal[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arrayOriginal) / sizeof(arrayOriginal[0]);

    printf("Array original: ");
    imprimirArray(arrayOriginal, tamanho);

    int *arrayInvertido = inverterArray(arrayOriginal, tamanho);
    if (arrayInvertido != NULL) {
        printf("Array invertido: ");
        imprimirArray(arrayInvertido, tamanho);

        free(arrayInvertido);
    }

    return 0;
}
