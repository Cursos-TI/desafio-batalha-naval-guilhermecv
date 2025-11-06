// Tema 5 - Batalha Naval
// Autor: Guilherme Camargo Valese


#include <stdio.h>

// Definição dos tamanhos dos objetos
#define TAMANHO_NAVIO 3
#define TAMANHO_TABULEIRO 10


// Coordenadas iniciais dos navios
int posHorizNavio1 = 7;
int posVertNavio1 = 7;
int posHorizNavio2 = 0;
int posVertNavio2 = 1;

int main()
{
    // Representação do tabuleiro do jogo. Inicializa com todos valores em 0
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Representação dos navios, inicializa com o valor 3 em todas as posições
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

    // Coloca os navios no tabuleiro e verifica se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[posVertNavio1][posHorizNavio1 + i] = navio1[i];
        tabuleiro[posVertNavio2 + i][posHorizNavio2] = navio2[i];

        if(tabuleiro[posVertNavio1][posHorizNavio1 + i] == tabuleiro[posVertNavio2 + i][posHorizNavio2] == 3)
        {
            printf("Os navios se sobrepõem!\n");
            return 1;
        }
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