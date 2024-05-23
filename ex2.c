#include <stdio.h>
#include <ctype.h>

int contar_vogais(char *string) {
    int total_vogais = 0;
    char *ptr = string;

    while (*ptr != '\0') {
        char lower_char = tolower(*ptr);
        
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
            total_vogais++;
        }

        ptr++;
    }

    return total_vogais;
}

int main() {
    char entrada[100]; 
    printf("Digite uma string: ");
    fgets(entrada, sizeof(entrada), stdin);

    printf("Número de vogais na string: %d\n", contar_vogais(entrada));

    return 0;
}
