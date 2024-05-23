#include <stdio.h>

void converterParaMaiusculas(char *string) {
    while (*string != '\0') {
        if (*string >= 'a' && *string <= 'z') {
            *string = *string - 32;
        }
        string++;
    }
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    scanf("%s", string);

    converterParaMaiusculas(string);

    printf("String convertida para maiúsculas: %s\n", string);

    return 0;
}
