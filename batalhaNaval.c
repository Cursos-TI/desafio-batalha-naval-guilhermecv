// Tema 5 - Batalha Naval
// Desafio 1: Nível novato
// Autor: Guilherme Camargo Valese

#include <stdio.h>

#define TAMANHO_NAVIO 3
#define TAMANHO_TABULEIRO 10



// Coordenadas iniciais dos navios
int posHorizNavio1 = 7;
int posVertNavio1 = 7;
int posHorizNavio2 = 0;
int posVertNavio2 = 1;
int posHorizNavio3 = 4;
int posVertNavio3 = 3;
int posHorizNavio4 = 2;
int posVertNavio4 = 5;


int main()
{
    // Representação do tabuleiro do jogo
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Representação dos navios
    int navio1[TAMANHO_NAVIO] = {3};
    int navio2[TAMANHO_NAVIO] = {3};

    printf("\n** Batalha Naval **\n");

    // Verifica se as coordenadas estão dentro dos limites do tabuleiro
    if (posHorizNavio1 < 0 || posHorizNavio1 + TAMANHO_NAVIO> TAMANHO_TABULEIRO || posVertNavio1 < 0 || posVertNavio1 > TAMANHO_TABULEIRO ||
        posHorizNavio2 < 0 || posHorizNavio2 > TAMANHO_TABULEIRO - 1 || posVertNavio2 < 0 || posVertNavio2 + TAMANHO_NAVIO> TAMANHO_TABULEIRO)
    {
        printf("Coordenadas inválidas! Tente novamente.\n");
        return 1;
    }

    // Coloca os navios no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[posVertNavio1][posHorizNavio1 + i] = 3;
        tabuleiro[posVertNavio2 + i][posHorizNavio2] = 3;

        // Navios em diagonal
        tabuleiro[posVertNavio3 - i][posHorizNavio3 + i] = 3;
        tabuleiro[posVertNavio4 + i][posHorizNavio4 + i] = 3;
    }
 
    // Loop aninhado para exibição do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}