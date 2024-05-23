#include <stdio.h>
#include <time.h>

void codigo_a_ser_medido() {
  
    for (int i = 0; i < 1000000; i++) {
        
        int resultado = i * i;
    }
}

int main() {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock(); 

  
    codigo_a_ser_medido();

    fim = clock(); 
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);

    return 0;
}
