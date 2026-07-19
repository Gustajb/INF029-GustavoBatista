#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char tab[3][3];

void inicializar() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = ' ';
        }
    }
}

void imprimir() {
    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 3; j++) {
            printf("%c", tab[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

int checarVitoria() {
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) return 1;
        if (tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) return 1;
    }
    if (tab[0][0] != ' ' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) return 1;
    if (tab[0][2] != ' ' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) return 1;
    return 0;
}

int main() {
    int jogadas = 0;
    int jogador = 1;
    char linha;
    int coluna;

    inicializar();

    while (1) {
        imprimir();
        printf("Jogador %d, informe sua jogada: ", jogador);
        if (scanf(" %c%d", &linha, &coluna) != 2) {
            while(getchar() != '\n');
            continue;
        }

        linha = toupper(linha);
        int l = linha - 'A';
        int c = coluna - 1;

        if (l < 0 || l > 2 || c < 0 || c > 2 || tab[l][c] != ' ') {
            printf("Jogada invalida. Tente novamente.\n");
            continue;
        }

        tab[l][c] = (jogador == 1) ? 'X' : '0';
        jogadas++;

        if (checarVitoria()) {
            imprimir();
            printf("O Jogador %d venceu!\n", jogador);
            break;
        }

        if (jogadas == 9) {
            imprimir();
            printf("O jogo terminou em empate!\n");
            break;
        }

        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}
