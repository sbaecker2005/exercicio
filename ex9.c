#include <stdio.h>
#include <stdlib.h>

float calcularMedia(int array[], int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    return soma / tamanho;
}

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calcularMediana(int array[], int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);

    if (tamanho % 2 != 0) {
        return array[tamanho / 2];
    }
    else {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    }
}

int calcularModa(int array[], int tamanho) {
    int moda = array[0];
    int contagemAtual = 1;
    int contagemMaxima = 1;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            contagemAtual++;
        } else {
            if (contagemAtual > contagemMaxima) {
                contagemMaxima = contagemAtual;
                moda = array[i - 1];
            }
            contagemAtual = 1;
        }
    }

    if (contagemAtual > contagemMaxima) {
        contagemMaxima = contagemAtual;
        moda = array[tamanho - 1];
    }

    return moda;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    float media = calcularMedia(array, tamanho);
    float mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(array);
    return 0;
}
