#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char caractere;
    char codigo[10];
} MorseMap;

MorseMap tabela_morse[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},

    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},

    {' ', "/"}
};
char *buscarCodigoMorse(char letra);
void fromMorseToLanguage();
void fromLanguageToMorse();

int main(void) {
    char t;
    printf("Introduza o tipo de mensagem inicial ('m' para codigo morse ou 'l' para linguagem usual)\n");
    scanf("%c", &t);
        if ( t == 'm') {
            fromMorseToLanguage();
        }
        else if (t == 'l') {
            fromLanguageToMorse();
        }
        else {
            printf("Caracter inválido, tente novamente!\n");
        }
    return 0;
}

void fromMorseToLanguage() {
    printf("Introduza '.' para um sinal único e '-' para um sinal contínuo\n");
    printf("Introduza o código morse a ser convertido para liguagem real\n");
    char codigo [255];
    getchar();
    fgets(codigo, 255, stdin);
    // Função para traduzir codigo morse em linguagem real utilizar a tabela para decodificar
}

void fromLanguageToMorse() {
    printf("Introduza o texto a ser convertido para código morse\n");
    char palavra [255];
    getchar();
    fgets(palavra, 255, stdin);
    for (int i = 0; palavra[i] != '\0'; i++) {
        char letra = palavra[i];
        if (letra == '\n')
            continue;
        char *codigo = buscarCodigoMorse(letra);
        if (codigo != NULL) {
            printf("%s ", codigo);
        } else {
            printf("? ");
        }
    }
    printf("\n");
    // Função para traduzir linguagem real em codigo morse utilizar a tabela para codificar
}

char *buscarCodigoMorse(char letra) {
    letra = toupper(letra);
    int tamanho_tabela = sizeof(tabela_morse);
    for (int i = 0; tabela_morse[i].caractere != tamanho_tabela; i++) {
        if (tabela_morse[i].caractere == letra) {
            return tabela_morse[i].codigo;
        }
    }
    return NULL;
}