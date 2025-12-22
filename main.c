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

void morse();
void linguaguem();

int main(void) {
    char t;
    printf("Introduza o tipo de mensagem inicial ('m' para codigo morse ou 'l' para linguagem usual)\n");
    if (scanf("%c", &t) == 'm') {
        morse();
    }
    if (scanf("%c", &t) == 'l') {
        linguaguem();
    }
    return 0;
}

void morse() {
    printf("Introduza '.' para um sinal único e '-' para um sinal contínuo");
    // Função para traduzir codigo morse em linguagem real utilizar a tabela para decodificar
}

void linguaguem() {
    printf("Introduza o texto para converter para morse");
    // Função para traduzir linguagem real em codigo morse utilizar a tabela para decodificar
}