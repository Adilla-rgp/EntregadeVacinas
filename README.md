# Projeto: Entrega de Vacinas

## Descrição

Este projeto simula a logística de entrega de vacinas, otimizando a rota de um caminhão para visitar uma série de postos de saúde, começando e retornando ao ponto central de distribuição. O objetivo é calcular a menor rota possível usando o algoritmo **Nearest Neighbor** e exibir o resultado, incluindo a rota e a distância total.
Além disso, o programa conta com uma interface baseada em terminal para visualizar o percurso de forma interativa.

---

## Funcionalidades

- Entrada de coordenadas de postos de saúde fornecidas pelo usuário ou por arquivo.
- Cálculo da rota otimizada para a entrega de vacinas.
- Exibição da rota no terminal com visualização básica ou colorida.
- Representação simplificada do "mapa" das cidades e da rota.
- (Opcional) Uso da biblioteca `ncurses` para criar uma interface interativa no terminal.

---

## Como Executar

### Requisitos

- Um compilador C (como GCC ou Clang):
  - **Linux:** `sudo apt install build-essential`
  - **Windows:** Instale o MinGW.
  - **macOS:** Instale o Xcode Command Line Tools com `xcode-select --install`.
- Biblioteca `ncurses`:
  - **Linux:** `sudo apt install libncurses5-dev libncursesw5-dev`
  - **Windows:** Use uma porta como PDCurses.

### Passos

1. Clone este repositório:

   ```bash
   git clone https://github.com/seu_usuario/entrega-de-vacinas.git
   cd entrega-de-vacinas
   ```

2. Compile o código:

   ```bash
   gcc -o entrega_vacinas entrega_vacinas.c -lm
   ```

   - Caso utilize `ncurses`:
     ```bash
     gcc -o entrega_vacinas entrega_vacinas.c -lm -lncurses
     ```

3. Execute o programa:

   ```bash
   ./entrega_vacinas
   ```

---

## Estrutura do Projeto

- **entrega\_vacinas.c**: Código principal do projeto.
- **maranhao10.txt**: Arquivo de exemplo contendo as coordenadas de 10 cidades do Maranhão.

Exemplo de arquivo de coordenadas:

```
1 44.303 2.549 # São Luís
2 43.463 2.447 # Imperatriz
3 44.408 3.385 # Caxias
...
EOF
```

---

## Como funciona o programa 

- Leitura de coordenadas (arquivo ou entrada do usuário).
- Implementação do algoritmo **Nearest Neighbor**.
- Garantir que todos os postos sejam visitados apenas uma vez.
- Validar os dados de entrada e saída.
- Testar com diferentes cenários de arquivos de entrada.
- Exibição da rota e distância no terminal.
- Representação visual básica ou colorida da rota.
- (Opcional) Implementação da interface com `ncurses`.

---

## Exemplo de Saída no Terminal

### Entrada

Arquivo `maranhao10.txt`:

```
1 44.303 2.549 # São Luís
2 43.463 2.447 # Imperatriz
3 44.408 3.385 # Caxias
...
EOF
```

### Saída

```
Rota do Caminhão:
Cidade 1 (44.303, 2.549) -> Cidade 2 (43.463, 2.447) -> Cidade 3 (44.408, 3.385) -> ... -> Cidade 1 (44.303, 2.549)

Distância Total: 710.00 km

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
- Biblioteca `ncurses` para interface interativa.

---

## Próximos Passos

- Adicionar suporte para mais formatos de entrada de dados.
- Melhorar a interface com animações do caminhão percorrendo o mapa.
- Implementar outros algoritmos de otimização de rotas, como **Algoritmo Genético** ou **Simulated Annealing**.

---

## Contribuição

Sinta-se à vontade para contribuir com melhorias neste projeto. Sugestões, correções e ideias são bem-vindas!

---

## Licença

Este projeto é de uso livre para fins educacionais.

---

Feito por Ádilla, Brendda e Camilly

