#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define Vazio 0
#define Navio 3

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

     // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.



    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
// Função para iniciar o tabuleiro com valores vazios
void iniciarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = Vazio;
        }
    }
}

// Função para verificar se a posição é válida para um navio (considerando seu tamanho)
int posicaoValida(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    if (direcao == 0) { // Horizontal
        if (coluna + tamanho > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != Vazio) return 0; // Já ocupado
        }
    } else { // Vertical
        if (linha + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != Vazio) return 0;
        }
    }
    return 1;
}

// Função para posicionar navios corretamente no tabuleiro
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    srand(time(NULL));

    int tamanhos[] = {4, 3, 3, 2}; // Tamanhos dos navios
    int totalNavios = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < totalNavios; i++) {
        int linha, coluna, direcao, valido = 0;
        while (!valido) {
            linha = rand() % TAMANHO;
            coluna = rand() % TAMANHO;
            direcao = rand() % 2; // 0 = Horizontal, 1 = Vertical
            if (posicaoValida(tabuleiro, linha, coluna, tamanhos[i], direcao)) {
                valido = 1;
            }
        }
        
        // Posiciona o navio
        for (int j = 0; j < tamanhos[i]; j++) {
            if (direcao == 0)
                tabuleiro[linha][coluna + j] = Navio;
            else
                tabuleiro[linha + j][coluna] = Navio;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para habilidade Cone
void habilidadeCone(int matriz[TAMANHO][TAMANHO], int x, int y) {
    if (x < 2) return; // Impede que o cone saia dos limites superiores
    matriz[x][y] = 1;
    if (y > 0) matriz[x - 1][y - 1] = 1;
    matriz[x - 1][y] = 1;
    if (y < TAMANHO - 1) matriz[x - 1][y + 1] = 1;
    if (y > 1) matriz[x - 2][y - 1] = 1;
    matriz[x - 2][y] = 1;
    if (y < TAMANHO - 2) matriz[x - 2][y + 1] = 1;
}

// Função para habilidade Cruz
void habilidadeCruz(int matriz[TAMANHO][TAMANHO], int x, int y) {
    for (int i = 0; i < TAMANHO; i++) {
        matriz[i][y] = 1; // Linha vertical
        matriz[x][i] = 1; // Linha horizontal
    }
}

// Função para habilidade Octaedro
void habilidadeOctaedro(int matriz[TAMANHO][TAMANHO], int x, int y) {
    matriz[x][y] = 1;
    if (x > 0) matriz[x - 1][y] = 1;
    if (x < TAMANHO - 1) matriz[x + 1][y] = 1;
    if (y > 0) matriz[x][y - 1] = 1;
    if (y < TAMANHO - 1) matriz[x][y + 1] = 1;
    if (x > 0 && y > 0) matriz[x - 1][y - 1] = 1;
    if (x > 0 && y < TAMANHO - 1) matriz[x - 1][y + 1] = 1;
    if (x < TAMANHO - 1 && y > 0) matriz[x + 1][y - 1] = 1;
    if (x < TAMANHO - 1 && y < TAMANHO - 1) matriz[x + 1][y + 1] = 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro e posiciona os navios
    iniciarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    imprimirTabuleiro(tabuleiro);

    // Testando habilidades especiais
    int matriz[TAMANHO][TAMANHO] = {0};
    int x = 5, y = 5; // Posição central para aplicar a habilidade

    printf("\nHabilidade Cone:\n");
    habilidadeCone(matriz, x, y);
    imprimirMatriz(matriz);

    // Resetando a matriz
    iniciarTabuleiro(matriz);
    printf("Habilidade Cruz:\n");
    habilidadeCruz(matriz, x, y);
    imprimirMatriz(matriz);

    // Resetando a matriz
    iniciarTabuleiro(matriz);
    printf("Habilidade Octaedro:\n");
    habilidadeOctaedro(matriz, x, y);
    imprimirMatriz(matriz);

    return 0;
}
