#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz\n");
            exit(1);
        }
    }

    return matriz;
}

void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int **multiplicarMatrizes(int **matriz1, int linhas1, int colunas1, int **matriz2, int linhas2, int colunas2) {
    if (colunas1 != linhas2) {
        printf("Erro: As matrizes não podem ser multiplicadas devido às dimensões inconsistentes.\n");
        return NULL;
    }

    int **resultado = alocarMatriz(linhas1, colunas2);

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

int **transporMatriz(int **matriz, int linhas, int colunas) {
    int **transposta = alocarMatriz(colunas, linhas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    return transposta;
}

void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas1, colunas1, linhas2, colunas2;

    printf("Digite o número de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &linhas1, &colunas1);

    printf("Digite o número de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &linhas2, &colunas2);

    int **matriz1 = alocarMatriz(linhas1, colunas1);
    int **matriz2 = alocarMatriz(linhas2, colunas2);

    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < linhas2; i++) {
        for (int j = 0; j < colunas2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    int **resultadoMultiplicacao = multiplicarMatrizes(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2);
    if (resultadoMultiplicacao != NULL) {
        printf("Resultado da multiplicação das matrizes:\n");
        imprimirMatriz(resultadoMultiplicacao, linhas1, colunas2);
    }

    printf("\nTransposta da primeira matriz:\n");
    int **transposta = transporMatriz(matriz1, linhas1, colunas1);
    imprimirMatriz(transposta, colunas1, linhas1);

    liberarMatriz(matriz1, linhas1);
    liberarMatriz(matriz2, linhas2);
    liberarMatriz(resultadoMultiplicacao, linhas1);
    liberarMatriz(transposta, colunas1);

    return 0;
}
