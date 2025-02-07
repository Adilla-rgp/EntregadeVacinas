#include <stdio.h>
#include <stdlib.h>
#include "output/arquivos/leitura.h"  // Incluir o cabeçalho de leitura

int main()
{
    char arquivo_Pcoordenadas[200]; // Array que armazena o nome dos arquivos
    Posto *postos = NULL;           // Ponteiro para alocação de memória
    int totalPostos = 0;            // Armazena o número total de postos lidos
    int capacidade = 200;           // Capacidade inicial da array de postos

    // Entrada do usuário
    printf("\n(Antes de comecar, verifique se os arquivos estão no mesmo diretorio que o programa!)\n\nInsira o nome do arquivo: ");
    scanf("%199s", arquivo_Pcoordenadas);

    // Adicionar o debug aqui
    printf("Tentando abrir o arquivo: %s\n", arquivo_Pcoordenadas);

    // Chamada da função lerArquivo
    int resultado = lerArquivo(arquivo_Pcoordenadas, &postos, &totalPostos, capacidade);
    if (resultado != 0) {
        fprintf(stderr, "\nNao e possivel realizar a leitura do arquivo de coordenadas\n");
        return 1;  // Retorna 1 em caso de erro
    }

    // Exibição do resultado
    printf("\nPostos encontrados: %d\n", totalPostos);  // Mostra a quantidade de postos encontrados no arquivo
    for (int i = 0; i < totalPostos; i++) {  // Imprime as coordenadas e o número do posto
        printf("\nPosto %d:\t\t (%.2lf , %.2lf)\n", postos[i].endereco, postos[i].x, postos[i].y);
    }

    // Liberação de memória
    free(postos);
    return 0;
}
