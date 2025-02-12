 #include <stdio.h>

#define Tamanho_Vertical 4
#define Tamanho_Horizontal 5
#define Navio_Diagonal
#define Navio 3
#define Vazio 0

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

   // Definição do tabuleiro
   void iniciartabuleiro(int tabuleiro[10][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = Vazio;
        }
    }
   }

    int posicaovalida(int tabuleiro[10][10], int linha, int coluna, int Diagonal){
        if (linha >= 10 || coluna >= 10 || tabuleiro[linha][coluna] == Navio){
            return 0;
    }

    if (Diagonal) {
        if (linha + 1 >= 10 || coluna + 1 >= 10 || tabuleiro[linha + 1][coluna + 1 == Navio]){
            return 0;
            }

        }
        return 1;
    }~

    void posicaonavios(int tabuleiro[10][10]){
        int naviosAdicionados = 0;

        while (naviosAdicionados < Navio_Diagonal){
            int linha = rand() % 10;
            int coluna = rand() % 10;
            int Diagonal = (naviosAdicionados >= 2);
            
            if (posicaovalida(tabuleiro, linha, coluna, Diagonal)) {
                tabuleiro[linha][coluna] = Navio
                
                if (Diagonal){
                    tabuleiro[linha +1][coluna +1] = Navio;
                }
                naviosAdicionado++;
            }
        }
    }
    
    void imprimirTabuleiro(int tabuleiro[10][10]){
        printf("Tabuleiro: \n");
        for (int i = 0; i < 10; i++){
            for (int j = 0; j <10; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    // Posição iniciail dos navios
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
