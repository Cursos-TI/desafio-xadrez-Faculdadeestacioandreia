#include <stdio.h>

#define SIZE 8

// Representação simples: letras maiúsculas = peças brancas, minúsculas = peças pretas
// P = peão, T = torre, C = cavalo, B = bispo, D = dama, R = rei

void inicializar(char tabuleiro[SIZE][SIZE]) {
    char inicio[8][9] = {
        "tcbdrbct",
        "pppppppp",
        "~~~~~~~~",
        "~~~~~~~~",
        "~~~~~~~~",
        "~~~~~~~~",
        "PPPPPPPP",
        "TCBDRBC T"
    };
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tabuleiro[i][j] = inicio[i][j];
}

void mostrar(char tabuleiro[SIZE][SIZE]) {
    printf("   1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[SIZE][SIZE];
    inicializar(tabuleiro);

    printf("===== XADREZ SIMPLES =====\n");
    printf("Sem regras de movimento válidas. Apenas mova peças digitando origem e destino.\n");
    printf("Exemplo: A2 A4 (move de A2 para A4).\n\n");

    int fim = 0;
    while (!fim) {
        mostrar(tabuleiro);
        char oLetra, dLetra;
        int oNum, dNum;
        printf("Movimento: ");
        scanf(" %c%d %c%d", &oLetra, &oNum, &dLetra, &dNum);

        int oi = oLetra - 'A';
        int oj = oNum - 1;
        int di = dLetra - 'A';
        int dj = dNum - 1;

        if (oi < 0 || oi >= SIZE || oj < 0 || oj >= SIZE ||
            di < 0 || di >= SIZE || dj < 0 || dj >= SIZE) {
            printf("Coordenada inválida!\n");
            continue;
        }

        char peca = tabuleiro[oi][oj];
        if (peca == '~') {
            printf("Não há peça na origem!\n");
            continue;
        }

        tabuleiro[di][dj] = peca;
        tabuleiro[oi][oj] = '~';
    }

    return 0;
}
