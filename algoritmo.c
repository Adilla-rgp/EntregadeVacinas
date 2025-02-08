#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "leitura.h" 

// --------------------------- PROTÓTIPOS DAS FUNÇÕES ---------------------------

/*
1) Calcula a distância entre dois postos usando a fórmula euclidiana.
2) Essa função usa recursividade. (Constrói a rota do caminhão a partir do posto atual).
3) Cria o vetor dos postos visitados e chama a função recursiva para calcular a melhor rota.
4) Calcula a distância total percorrida com base na rota.
*/
double calcular_distancia(Posto postoA, Posto postoB);
void construir_rota(Posto postos[], int totalPostos, int rota[], int visitado[], int atual, int indice);
void nearest_neighbor(Posto postos[], int totalPostos, int rota[]);
double calcular_distancia_total(Posto postos[], int rota[], int totalPostos);

// ------------------------------ FUNÇÃO MAIN ------------------------------
int main() {
    char nomeArquivo[200];
    printf("Digite o nome do arquivo de coordenadas: ");
    scanf("%199s", nomeArquivo);
    
    Posto *postos = NULL;
    int totalPostos = 0;
    int capacidadeInicial = 200;
    
    // Chama a função de leitura do arquivo feita por Brendda
    if (lerArquivo(nomeArquivo, &postos, &totalPostos, capacidadeInicial) != 0) {
        printf("Erro ao ler o arquivo de coordenadas.\n");
        return 1;
    }
    
    printf("\nTotal de postos lidos: %d\n", totalPostos);
    // Exibe as informações dos postos do arquivo
    for (int i = 0; i < totalPostos; i++) {
        printf("Posto %d: (%.6lf, %.6lf)\n", postos[i].endereco, postos[i].x, postos[i].y);
    }
    
    // Cria o vetor para armazenar a rota. O (tamanho = totalPostos + 1) é para incluir o retorno ao centro de distribuição
    int *rota = malloc((totalPostos + 1) * sizeof(int));
    if (rota == NULL) {
        printf("Erro de alocacao de memoria para a rota.\n");
        free(postos);
        return 1;
    }
    
    nearest_neighbor(postos, totalPostos, rota);
    
    double distanciaTotal = calcular_distancia_total(postos, rota, totalPostos);
    // Corrigindo: a chamada correta:
    // double distanciaTotal = calcular_distancia_total(postos, rota, totalPostos);
    
    // Imprime o id de cada posto na ordem de visita
    printf("\nRota calculada:\n");
    for (int i = 0; i < totalPostos + 1; i++) {
        printf("%d ", postos[rota[i]].endereco);
        if (i < totalPostos)
            printf("-> ");
    }
    printf("\nDistancia total percorrida: %.6lf\n", distanciaTotal);
    
    // Libera a memória alocada
    free(rota);
    free(postos);
    
    return 0;
}

// ------------------------------ FUNÇÕES ------------------------------------

double calcular_distancia(Posto postoA, Posto postoB) {
    return sqrt(pow(postoB.x - postoA.x, 2) + pow(postoB.y - postoA.y, 2));
}

// 'atual' é o índice do posto atual, o 'indice' é como um for externo, que passa e preenche os índices da rota
void construir_rota(Posto postos[], int totalPostos, int rota[], int visitado[], int atual, int indice) {
    // Caso base: 
    if (indice == totalPostos) {
        rota[indice] = 0;  // Retorna ao posto inicial
        return;
    }
    
    int proximo = -1;
    double menorDistancia = DBL_MAX;
    
    // Percorre todos os postos para encontrar o próximo não visitado com a menor distância do posto atual
    for (int j = 0; j < totalPostos; j++) {
        if (!visitado[j]) {  // Se o posto j ainda não foi visitado
            double distancia = calcular_distancia(postos[atual], postos[j]);
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
    /* Utilizando a função recursiva para preencher a próxima posição na rota */
    construir_rota(postos, totalPostos, rota, visitado, proximo, (indice + 1));
}

void nearest_neighbor(Posto postos[], int totalPostos, int rota[]) {
    // Aloca e inicializa o vetor para marcar quais postos já foram visitados (0 = nao visitado, 1 = visitado)
    int *visitado = malloc(totalPostos * sizeof(int));
    if (visitado == NULL) {
        printf("Erro de alocacao de memoria para o vetor 'visitado'.\n");
        exit(1);
    }
    for (int i = 0; i < totalPostos; i++) {
        visitado[i] = 0;
    }
    
    // O índice 0 é o centro de distribuicao.
    rota[0] = 0;
    visitado[0] = 1;
    
    // Constrói a rota a partir do centro de distribuição, preenchendo a partir da posição 1 que é o ponto 2.
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
