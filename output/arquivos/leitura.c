#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h" // Incluir o cabeçalho que define a struct Posto e a função lerArquivo

// Definição da função lerArquivo
int lerArquivo(const char *arquivo, Posto **postos, int *totalPostos, int capacidade)
{
    FILE *arq = fopen(arquivo, "r");
    if (arq == NULL) {
        printf("ERRO\nNao foi possivel ler ou abrir o arquivo");
        return -1;
    }

    // Alocação de memória inicial
    *totalPostos = 0;
    *postos = malloc(capacidade * sizeof(Posto));
    if (*postos == NULL) {
        printf("Erro de alocacao dinamica");
        fclose(arq);
        return -1;
    }

    // Buffer para armazenar as linhas lidas
    char linha_coordenada[450];

    // Leitura do arquivo linha por linha
    while (fgets(linha_coordenada, sizeof(linha_coordenada), arq)) {
        // Remover o '\n' da linha
        linha_coordenada[strcspn(linha_coordenada, "\n")] = '\0';
        if (strlen(linha_coordenada) == 0)
            continue;

        // Extrair coordenadas (x, y) da linha
        double x, y;
        int resultado = sscanf(linha_coordenada, "%lf %lf", &x, &y);
        if (resultado != 2) {
            fprintf(stderr, "ERRO\nFormato (x,y) nao correspondido na linha %d!", *totalPostos + 1);
            continue;
        }

        // Realocar memória se necessário
        if (*totalPostos >= capacidade) {
            capacidade *= 2;
            *postos = realloc(*postos, capacidade * sizeof(Posto));
            if (*postos == NULL) {
                printf("Erro de realocacao dinamica");
                fclose(arq);
                return -1;
            }
        }

        // Armazenar os dados na struct
        (*postos)[*totalPostos].endereco = *totalPostos + 1;
        (*postos)[*totalPostos].x = x;
        (*postos)[*totalPostos].y = y;

        (*totalPostos)++;
    }

    fclose(arq);
    return 0;
}
