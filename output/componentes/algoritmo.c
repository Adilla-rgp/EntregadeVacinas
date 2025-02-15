#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "leitura.h"
#include "algoritmo.h"

// Funções de cálculo
double calcular_distancia(Posto postoA, Posto postoB) {
    return sqrt(pow(postoB.x - postoA.x, 2) + pow(postoB.y - postoA.y, 2));
}

void inserir_coordenadas(Posto **postos, int *totalPostos) {
    printf("Digite o numero de postos: ");
    scanf("%d", totalPostos);

    *postos = malloc((*totalPostos) * sizeof(Posto));
    if (*postos == NULL) {
        printf("Erro de alocacao de memoria para os postos.\n");
        exit(1);
    }

    for (int i = 0; i < *totalPostos; i++) {
        printf("Digite as coordenadas do posto %d (x y): ", i + 1);
        scanf("%lf %lf", &(*postos)[i].x, &(*postos)[i].y);
        (*postos)[i].endereco = i + 1;
    }
}

void imprimir_rota(Posto postos[], int rota[], int totalPostos) {
    for (int i = 0; i < totalPostos + 1; i++) {
        printf("%d", postos[rota[i]].endereco);
        if (i < totalPostos) {
            printf(" -> ");
        }
    }
}


void construir_rota(Posto postos[], int totalPostos, int rota[], int visitado[], int atual, int indice) {
    if (indice == totalPostos) {
        rota[indice] = 0;
        return;
    }
    
    int proximo = -1;
    double menorDistancia = DBL_MAX;
    
    for (int j = 0; j < totalPostos; j++) {
        if (!visitado[j]) {
            double distancia = calcular_distancia(postos[atual], postos[j]);
            printf("Distancia entre o posto %d e o posto %d = %f\n", atual, j, distancia);
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                proximo = j;
            }
        }
    }
    
    if (proximo == -1) {
        printf("Erro: Nao foi possivel encontrar o proximo posto.\n");
        exit(1);
    }
    
    rota[indice] = proximo;
    visitado[proximo] = 1;
    construir_rota(postos, totalPostos, rota, visitado, proximo, indice + 1);
}

void nearest_neighbor(Posto postos[], int totalPostos, int rota[]) {
    int *visitado = malloc(totalPostos * sizeof(int));
    if (visitado == NULL) {
        printf("Erro de alocacao de memoria para o vetor 'visitado'.\n");
        exit(1);
    }
    for (int i = 0; i < totalPostos; i++) {
        visitado[i] = 0;
    }
    
    rota[0] = 0;
    visitado[0] = 1;
    construir_rota(postos, totalPostos, rota, visitado, 0, 1);
    
    free(visitado);
}

double calcular_distancia_total(Posto postos[], int rota[], int totalPostos) {
    double soma = 0.0;
    for (int i = 0; i < totalPostos; i++) {
        soma += calcular_distancia(postos[rota[i]], postos[rota[i+1]]);
    }
    return soma;
}
