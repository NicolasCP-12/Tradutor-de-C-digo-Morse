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
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'!', "-.-.--"},
    {'-', "-....-"},
    {'_', "..--.-"},
    {' ', "/"}
};

char *buscarCodigoMorse(char letra);
char buscarLetra(const char *palavra);
void fromMorseToLanguage();
void fromLanguageToMorse();
void criar_ficheiro(const char *texto);
void creditos_finais();

int main(void) {
    char t;
    char m = 's';
    while (m == 's') {
        printf("Introduza o tipo de mensagem inicial ('m' para codigo morse ou 'l' para linguagem usual)\n");
        scanf(" %c", &t);

        if (t == 'm') {
            fromMorseToLanguage();
        }
        else if (t == 'l') {
            fromLanguageToMorse();
        }
        else {
            printf("Caracter inválido, tente novamente!\n");
        }
        printf("Deseja inserir uma mensagem novamente? ('s' para sim e 'n' para não)\n");
        scanf(" %c", &m);
    }
    creditos_finais();
    return 0;
}

// Função para traduzir código Morse em linguagem real utilizando a tabela
void fromMorseToLanguage() {
    printf("Introduza '.' para um sinal único, '-' para um sinal contínuo\n");
    printf("Introduza o código morse a ser convertido para linguagem real\n");

    char codigo[255], r;
    int count = 0;
    getchar();
    fgets(codigo, 255, stdin);
    int len = strlen(codigo);
    if (len > 0 && codigo[len - 1] == '\n') {
        codigo[len - 1] = '\0';
    }
    char *frase[50];
    char *palavra = strtok(codigo, " ");
    char texto_traduzido[255] = "";

    while (palavra != NULL && count < 50) {
        frase[count++] = palavra;
        palavra = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        char *simbolo = frase[i];
        char letra = buscarLetra(simbolo);
        printf("%c", letra);
        char temp[2] = {letra, '\0'};
        strcat(texto_traduzido, temp);
    }
    printf("\nDeseja salvar a tradução em um ficheiro .txt? ('s' ou 'n')\n");
    scanf(" %c", &r);
    if (r == 's') {
        criar_ficheiro(texto_traduzido);
    }
    printf("\n");
}

// Função para traduzir linguagem real em código Morse utilizando a tabela
void fromLanguageToMorse() {
    printf("Introduza o texto a ser convertido para código morse\n");
    char palavra[255], r;
    char texto_traduzido[1000] = "";
    getchar();
    fgets(palavra, 255, stdin);

    for (int i = 0; palavra[i] != '\0'; i++) {
        char letra = palavra[i];
        if (letra == '\n')
            continue;
        char *codigo = buscarCodigoMorse(letra);
        if (codigo != NULL) {
            printf("%s ", codigo);
            strcat(texto_traduzido, codigo);
            strcat(texto_traduzido, " ");
        } else {
            printf("? ");
            strcat(texto_traduzido, "? ");
        }
    }
    printf("\nDeseja salvar a tradução em um ficheiro .txt? ('s' ou 'n')\n");
    scanf(" %c", &r);
    if (r == 's') {
        criar_ficheiro(texto_traduzido);
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

// Função para criar um ficheiro com o texto traduzido
void criar_ficheiro(const char *texto) {
    FILE *f_texto = fopen("tradução.txt", "w");
    if (f_texto != NULL) {
        fprintf(f_texto, "%s", texto);
        fclose(f_texto);
        printf("Ficheiro 'tradução.txt' criado com sucesso!\n");
    } else {
        printf("Erro ao criar o ficheiro.\n");
    }
}

//Funcao para traduzir ficheiro em morse, nesse caso creditos finais
void creditos_finais() {
    char mensagem[] = "Trabalho realizado por Enzo Mello e Nicolas Pinto. Espero que tenham gostado!";
    printf("                  CREDITOS FINAIS:                           \n");
    printf("Mensagem Original:\n");
    printf("%s\n\n", mensagem);

    FILE *f_texto = fopen("autores.txt", "w");
    if (f_texto != NULL) {
        fprintf(f_texto, "%s", mensagem);
        fclose(f_texto);
    }
    FILE *f_morse = fopen("autores_morse.txt", "w");
    if (f_morse == NULL) {
        printf("Erro ao criar ficheiro morse.\n");
        return ;
    }
    printf("Traducao em Morse:\n");
    for (int i = 0; mensagem[i] != '\0'; i++) {
        char letra = mensagem[i];
        char *codigo = buscarCodigoMorse(letra);

        if (codigo != NULL) {
            printf("%s ", codigo);
            fprintf(f_morse, "%s ", codigo);
        }
        else if (letra == ' ') {
            printf("/ ");
            fprintf(f_morse, "/ ");
        }
    }
    printf("\n") ;
    fclose(f_morse);
}