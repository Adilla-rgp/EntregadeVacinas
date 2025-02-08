// algoritmo.h

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "leitura.h"

// Protótipos das funções
double calcular_distancia(Posto postoA, Posto postoB);
void imprimir_rota(Posto postos[], int rota[], int totalPostos);
void inserir_coordenadas(Posto **postos, int *totalPostos);
void construir_rota(Posto postos[], int totalPostos, int rota[], int visitado[], int atual, int indice);
void nearest_neighbor(Posto postos[], int totalPostos, int rota[]);
double calcular_distancia_total(Posto postos[], int rota[], int totalPostos);


#endif
