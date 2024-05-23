#include <stdio.h>
#include <ctype.h>

int contar_vogais(char *string) {
    int total_vogais = 0;
    char *ptr = string;

    // Percorre cada caractere na string até encontrar o caractere nulo de término '\0'
    while (*ptr != '\0') {
        // Converte o caractere para minúsculo antes de verificar se é uma vogal
        char lower_char = tolower(*ptr);
        
        // Verifica se o caractere é uma vogal
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
            total_vogais++;
        }

        // Move para o próximo caractere
        ptr++;
    }

    return total_vogais;
}

int main() {
    char entrada[100]; // Assume que a entrada da string não terá mais de 100 caracteres

    // Solicita ao usuário a entrada da string
    printf("Digite uma string: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Chama a função contar_vogais e exibe o resultado
    printf("Número de vogais na string: %d\n", contar_vogais(entrada));

    return 0;
}
