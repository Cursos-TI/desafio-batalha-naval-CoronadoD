#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Tamanho_Vertical 4
#define Tamanho_Horizontal 5
#define Navio_Diagonal 2 // Definido corretamente
#define Navio 3
#define Vazio 0
#define TAMANHO 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Protótipos das funções
void iniciarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
int posicaoValida(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int diagonal);
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]);
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Definição do tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    iniciarTabuleiro(tabuleiro); // Inicia o tabuleiro
    posicionarNavios(tabuleiro); // Posiciona os navios
    imprimirTabuleiro(tabuleiro); // Imprime o tabuleiro

    // Posição inicial dos navios
    int x_vertical = 2, y_vertical = 3;     // Posição vertical
    int x_horizontal = 5, y_horizontal = 4; // Posição horizontal
    
    // Coordenadas do navio vertical
    printf("Coordenadas do Navio Vertical:\n");
    for (int i = 0; i < Tamanho_Vertical; i++) {
        printf("(%d, %d)\n", x_vertical, y_vertical + i);
    }
    
    // Coordenadas do navio horizontal
    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < Tamanho_Horizontal; i++) {
        printf("(%d, %d)\n", x_horizontal + i, y_horizontal);
    }

    return 0;
}

// Função para iniciar o tabuleiro com valores vazios
void iniciarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = Vazio;
        }
    }
}

// Função para verificar se a posição é válida
int posicaoValida(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int diagonal) {
    if (linha >= TAMANHO || coluna >= TAMANHO || tabuleiro[linha][coluna] == Navio) {
        return 0;
    }
    
    if (diagonal) {
        if (linha + 1 >= TAMANHO || coluna + 1 >= TAMANHO || tabuleiro[linha + 1][coluna + 1] == Navio) {
            return 0;
        }
    }
    
    return 1;
}

// Função para posicionar os navios no tabuleiro
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    int naviosColocados = 0;
    srand(time(NULL));
    
    while (naviosColocados < 4) { // Agora um número fixo
        int linha = rand() % TAMANHO;
        int coluna = rand() % TAMANHO;
        int diagonal = (naviosColocados >= 2); // Os dois últimos navios serão colocados na diagonal
        
        if (posicaoValida(tabuleiro, linha, coluna, diagonal)) {
            tabuleiro[linha][coluna] = Navio;
            
            if (diagonal) {
                if (linha + 1 < TAMANHO && coluna + 1 < TAMANHO) {
                    tabuleiro[linha + 1][coluna + 1] = Navio;
                }
            }
            
            naviosColocados++;
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
    
    return 0;
}
