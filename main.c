#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char caractere;
    char codigo[10];
} MorseMap;

// Tabela de conversão Morse ↔ caracteres
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
char buscarLetra(const char *palavra);
void fromMorseToLanguage();
void fromLanguageToMorse();

int main(void) {
    char t;
    printf("Introduza o tipo de mensagem inicial ('m' para codigo morse ou 'l' para linguagem usual)\n");
    scanf("%c", &t);

    if (t == 'm') {
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

// Função para traduzir código Morse em linguagem real utilizando a tabela
void fromMorseToLanguage() {
    printf("Introduza '.' para um sinal único, '-' para um sinal contínuo e '/' para espaço entre as palavras\n");
    printf("Introduza o código morse a ser convertido para linguagem real\n");

    char codigo[255];
    int count = 0;
    getchar();
    fgets(codigo, 255, stdin);
    int len = strlen(codigo);
    if (len > 0 && codigo[len - 1] == '\n') {
        codigo[len - 1] = '\0';
    }
    char *frase[50];
    char *palavra = strtok(codigo, " ");

    while (palavra != NULL && count < 50) {
        frase[count++] = palavra;
        palavra = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        char *simbolo = frase[i];
        char letra = buscarLetra(simbolo);
        printf("%c", letra);
    }
    printf("\n");
}

// Função para traduzir linguagem real em código Morse utilizando a tabela
void fromLanguageToMorse() {
    printf("Introduza o texto a ser convertido para código morse\n");
    char palavra[255];
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
}

// Função para encontrar o código Morse correspondente a uma letra
char *buscarCodigoMorse(char letra) {
    letra = toupper(letra);
    int tamanho_tabela = sizeof(tabela_morse) / sizeof(tabela_morse[0]);
    for (int i = 0; i < tamanho_tabela; i++) {
        if (tabela_morse[i].caractere == letra) {
            return tabela_morse[i].codigo;
        }
    }
    return NULL;
}

// Função para encontrar a letra correspondente a um código Morse
char buscarLetra(const char *palavra) {
    int tamanho_tabela = sizeof(tabela_morse) / sizeof(tabela_morse[0]);
    for (int i = 0; i < tamanho_tabela; i++) {
        if (strcmp(tabela_morse[i].codigo, palavra) == 0) {
            return tabela_morse[i].caractere;
        }
    }
    return '?';
}