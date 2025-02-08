#include <stdio.h>
#include <stdlib.h>
#include "componentes/leitura.h"
#include "componentes/algoritmo.h"

int main() {
    int opcao;
    printf("Escolha uma opcao:\n");
    printf("1 - Ler arquivo\n");
    printf("2 - Inserir coordenadas manualmente\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);
    
    Posto *postos = NULL;
    int totalPostos = 0;
    int capacidadeInicial = 200;
    char nomeArquivo[200];
    
    if (opcao == 1) {
        printf("Digite o nome do arquivo de coordenadas: ");
        scanf("%199s", nomeArquivo);
        
        if (lerArquivo(nomeArquivo, &postos, &totalPostos, capacidadeInicial) != 0) {
            printf("Erro ao ler o arquivo de coordenadas.\n");
            return 1;
        }
    } else if (opcao == 2) {
        inserir_coordenadas(&postos, &totalPostos);
    } else {
        printf("Opcao invalida.\n");
        return 1;
    }
    
    printf("\nTotal de postos: %d\n", totalPostos);
    for (int i = 0; i < totalPostos; i++) {
        printf("Posto %d: (%.6lf, %.6lf)\n", postos[i].endereco, postos[i].x, postos[i].y);
    }
    
    int *rota = malloc((totalPostos + 1) * sizeof(int));
    if (rota == NULL) {
        printf("Erro de alocacao de memoria para a rota.\n");
        free(postos);
        return 1;
    }
    
    nearest_neighbor(postos, totalPostos, rota);
    
    double distanciaTotal = calcular_distancia_total(postos, rota, totalPostos);
    
    printf("\nRota calculada:\n");
    imprimir_rota(postos, rota, totalPostos);
    printf("\nDistancia total percorrida: %.6lf\n", distanciaTotal);
    
    free(rota);
    free(postos);
    
    return 0;
}
