# Projeto: Entrega de Vacinas

## Descrição

Este projeto simula a logística de entrega de vacinas, otimizando a rota de um caminhão para visitar uma série de postos de saúde, começando e retornando ao ponto central de distribuição. O objetivo é calcular a menor rota possível usando o algoritmo **Nearest Neighbor** e exibir o resultado, incluindo a rota e a distância total.

---

## Como Executar

### Requisitos

- Um compilador C (como GCC ou Clang):
  - **Linux:** `sudo apt install build-essential`
  - **Windows:** Instale o MinGW.
  - **macOS:** Instale o Xcode Command Line Tools com `xcode-select --install`.

### Passos

1. Clone este repositório:

   ```bash
   git clone https://github.com/Adilla-rgp/EntregadeVacinas.git

   ```

    ```bash
   cd EntregadeVacinas
   cd output
   ```
  
2. Compile o código:

   ```bash
   gcc -o output.exe main.c componentes/algoritmo.c componentes/algoritmo.h componentes/leitura.c componentes/leitura.h
   ```

3. Execute o programa:

   ```bash
   ./output.exe
   ```
   
## Estrutura do Projeto

- **componentes**: Código principal do projeto.
- **output**: Pasta que contém os arquivos com as coordenadas das cidades de entrega.

Exemplo de arquivo de coordenadas:

```
 44.303 2.549 
 43.463 2.447 
 44.408 3.385
 45.248 3.783 
 43.356 2.887
 45.903 3.251 
...
EOF
```

## Como funciona o programa 

- Leitura de coordenadas (arquivo ou entrada do usuário).
- Implementação do algoritmo **Nearest Neighbor**.
- Garantir que todos os postos sejam visitados apenas uma vez.
- Validar os dados de entrada e saída.
- Testar com diferentes cenários de arquivos de entrada.
- Exibição da rota e distância no terminal.
- Representação visual básica ou colorida da rota.

---

## Exemplo de Saída no Terminal

### Entrada

Arquivo `maranhao10.txt`:

```
 44.303 2.549 
 43.463 2.447 
 44.408 3.385
 45.248 3.783 
 43.356 2.887
 45.903 3.251 
 44.568 2.578 
 46.094 3.873
 43.812 2.932 
 43.479 2.466 

...
EOF
```

### Saída

```
Rota do Caminhão:
Cidade 1 (44.303, 2.549) -> Cidade 2 (43.463, 2.447) -> Cidade 3 (44.408, 3.385) -> ... -> Cidade 1 (44.303, 2.549)

Distância Total:8.710910

Mapa Simplificado:
Cidade 1 (44.303, 2.549)
   |
   v
Cidade 2 (43.463, 2.447)
   |
   v
Cidade 3 (44.408, 3.385)
...
```

---

## Tecnologias Utilizadas

- Linguagem C.
- Biblioteca padrão (`math.h`, `stdio.h`).

---

## Próximos Passos

- Adicionar suporte para mais formatos de entrada de dados.
- Adicionar uma interface com animações do caminhão percorrendo os postos.
- Implementar outros algoritmos de otimização de rotas, como **Algoritmo Genético** ou **Simulated Annealing**.

---

## Contribuição

Sinta-se à vontade para contribuir com melhorias neste projeto. Sugestões, correções e ideias são bem-vindas!

---

## Licença

Este projeto é de uso livre para fins educacionais.

---

Feito por Ádilla, Brendda e Camilly

