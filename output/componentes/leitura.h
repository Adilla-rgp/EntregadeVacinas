#ifndef LEITURA_H
#define LEITURA_H

// A struct Posto é responsável por armazenar os dados das coordenadas (x, y) dos postos,
// além de relacionar um endereço para cada posto.
typedef struct {
    int endereco;
    double x;
    double y;
} Posto;

// Função que lê o arquivo de coordenadas e preenche a estrutura de postos
int lerArquivo(const char *arquivo, Posto **postos, int *totalPostos, int capacidade);
void nearest_neighbor(Posto postos[], int totalPostos, int *rota);
double calcular_distancia_total(Posto postos[], int *rota, int totalPostos); 

#endif // LEITURA_H
