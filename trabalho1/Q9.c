#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int NUM_NAVIOS = 5;
int tam_navios[] = {4, 3, 1, 1, 1};

char tab1[10][10], tab2[10][10];
char vis1[10][10], vis2[10][10];
int hp1 = 10, hp2 = 10;

void inicializar() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tab1[i][j] = ' ';
            tab2[i][j] = ' ';
            vis1[i][j] = ' ';
            vis2[i][j] = ' ';
        }
    }
}

void imprimir_matriz(char matriz[10][10]) {
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 10; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 10; j++) {
            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
}

int posicionar(char tab[10][10], int tam) {
    char linha, orientacao;
    int col;

    if (scanf(" %c %d %c", &linha, &col, &orientacao) != 3) {
        while(getchar() != '\n');
        return 0;
    }

    linha = toupper(linha);
    orientacao = toupper(orientacao);
    int l = linha - 'A';

    if (l < 0 || l > 9 || col < 0 || col > 9) return 0;

    if (orientacao == 'H') {
        if (col + tam > 10) return 0;
        for (int i = 0; i < tam; i++) {
            if (tab[l][col + i] != ' ') return 0;
        }
        for (int i = 0; i < tam; i++) {
            tab[l][col + i] = 'N';
        }
    } else if (orientacao == 'V') {
        if (l + tam > 10) return 0;
        for (int i = 0; i < tam; i++) {
            if (tab[l + i][col] != ' ') return 0;
        }
        for (int i = 0; i < tam; i++) {
            tab[l + i][col] = 'N';
        }
    } else {
        return 0;
    }

    return 1;
}

void configurar_jogador(int jogador, char tab[10][10]) {
    printf("\nJogador %d, posicione seus %d navios.\n", jogador, NUM_NAVIOS);
    printf("Formato: Linha Coluna Orientacao(H/V). Exemplo: A 0 H\n");
    
    for (int i = 0; i < NUM_NAVIOS; i++) {
        int posicionado = 0;
        while (!posicionado) {
            imprimir_matriz(tab);
            printf("Posicione o navio %d (Tamanho %d): ", i + 1, tam_navios[i]);
            if (posicionar(tab, tam_navios[i])) {
                posicionado = 1;
            } else {
                printf("Posicao invalida. Tente novamente.\n");
            }
        }
    }
    printf("\n--- Tabuleiro do Jogador %d configurado! ---\n\n", jogador);
}

int main() {
    int jogador_atual = 1;
    char linha;
    int col;

    inicializar();
    configurar_jogador(1, tab1);
    configurar_jogador(2, tab2);

    while (hp1 > 0 && hp2 > 0) {
        char (*tab_adv)[10] = (jogador_atual == 1) ? tab2 : tab1;
        char (*vis_adv)[10] = (jogador_atual == 1) ? vis2 : vis1;
        char (*tab_prop)[10] = (jogador_atual == 1) ? tab1 : tab2;
        int *hp_adv = (jogador_atual == 1) ? &hp2 : &hp1;

        printf("\n--- Turno do Jogador %d ---\n", jogador_atual);
        printf("Seu tabuleiro:\n");
        imprimir_matriz(tab_prop);
        printf("\nTabuleiro do adversario (seus tiros):\n");
        imprimir_matriz(vis_adv);

        printf("\nJogador %d, informe as coordenadas do tiro (Ex: A 5): ", jogador_atual);
        if (scanf(" %c %d", &linha, &col) != 2) {
            while(getchar() != '\n');
            printf("Entrada invalida.\n");
            continue;
        }

        linha = toupper(linha);
        int l = linha - 'A';

        if (l < 0 || l > 9 || col < 0 || col > 9) {
            printf("Coordenadas fora do mapa.\n");
            continue;
        }

        if (vis_adv[l][col] != ' ') {
            printf("Voce ja atirou nessa posicao.\n");
            continue;
        }

        if (tab_adv[l][col] == 'N') {
            printf("TIRO CERTEIRO!\n");
            vis_adv[l][col] = '0';
            tab_adv[l][col] = '0';
            (*hp_adv)--;
        } else {
            printf("AGUA!\n");
            vis_adv[l][col] = 'X';
            if (tab_adv[l][col] == ' ') tab_adv[l][col] = 'X';
        }

        if (*hp_adv == 0) {
            printf("\nO Jogador %d destruiu todos os navios e VENCEU O JOGO!\n", jogador_atual);
            break;
        }

        jogador_atual = (jogador_atual == 1) ? 2 : 1;
    }

    return 0;
}
