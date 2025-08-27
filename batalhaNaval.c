// batalhaNaval.c — Desafio em três níveis (Novato, Aventureiro e Mestre)
// =======================================================================
// Este programa simula partes de um jogo de Batalha Naval.
// Ele está dividido em três níveis de dificuldade:
//   1) Novato       → posiciona navios simples (vertical e horizontal)
//   2) Aventureiro  → expande o tabuleiro, adiciona diagonais e mostra tudo
//   3) Mestre       → simula habilidades especiais com padrões de matrizes
//
// Como compilar: gcc -std=c11 -Wall -Wextra -O2 batalhaNaval.c -o batalhaNaval
// Como executar: ./batalhaNaval   (ou batalhaNaval.exe no Windows)
// =======================================================================

#include <stdio.h>

/* ==================== NÍVEL NOVATO ====================
   Ideia principal: mostrar como representar navios simples
   em um tabuleiro através de coordenadas (x, y).
   - Um navio é colocado na vertical.
   - Outro é colocado na horizontal.
   - Não existe tabuleiro visual, apenas listamos as coordenadas
     de cada parte do navio no console. */
static void nivelNovato(void) {
    // Coordenadas do navio vertical (3 partes empilhadas)
    int navioVertical[3][2] = {{0,0}, {1,0}, {2,0}};
    // Coordenadas do navio horizontal (3 partes lado a lado)
    int navioHorizontal[3][2] = {{4,1}, {4,2}, {4,3}};

    printf("=== Nível Novato ===\n");

    // Mostra as coordenadas do navio vertical
    printf("Navio Vertical (coordenadas):\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d,%d)\n", navioVertical[i][0], navioVertical[i][1]);
    }

    // Mostra as coordenadas do navio horizontal
    printf("\nNavio Horizontal (coordenadas):\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d,%d)\n", navioHorizontal[i][0], navioHorizontal[i][1]);
    }
}

/* ==================== NÍVEL AVENTUREIRO ====================
   Ideia principal: criar um tabuleiro completo de 10x10.
   - Cada posição começa como 0 (vazio).
   - Inserimos quatro navios:
       • um horizontal
       • um vertical
       • um na diagonal principal (↘)
       • um na diagonal secundária (↙)
   - A marcação é feita com o número 3 nas posições ocupadas.
   - Ao final, o programa imprime o tabuleiro inteiro. */
static void nivelAventureiro(void) {
    int tabuleiro[10][10] = {0}; // inicia todas as casas como 0

    // Navio horizontal na linha 2
    for (int j = 0; j < 4; j++) tabuleiro[2][j] = 3;

    // Navio vertical na coluna 5
    for (int i = 0; i < 4; i++) tabuleiro[i][5] = 3;

    // Navio diagonal principal (↘) começando no canto superior esquerdo
    for (int i = 0; i < 4; i++) tabuleiro[i][i] = 3;

    // Navio diagonal secundária (↙) começando no canto superior direito
    for (int i = 0; i < 4; i++) tabuleiro[i][9-i] = 3;

    // Exibe todo o tabuleiro
    printf("=== Nível Aventureiro ===\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/* ==================== NÍVEL MESTRE ====================
   Ideia principal: representar padrões de habilidades especiais.
   - Usamos matrizes 5x5 para desenhar formatos específicos:
       • Cone
       • Cruz
       • Octaedro
   - O valor 1 indica área atingida pela habilidade.
   - O valor 0 indica área livre.
   - As matrizes são preenchidas manualmente para formar o padrão.
   - O programa exibe cada matriz no console. */
static void nivelMestre(void) {
    // Padrão de cone
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // Padrão de cruz
    int cruz[5][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // Padrão de octaedro (um losango simplificado)
    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    printf("=== Nível Mestre ===\n");

    // Mostra habilidade Cone
    printf("\nHabilidade Cone:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("%d ", cone[i][j]);
        printf("\n");
    }

    // Mostra habilidade Cruz
    printf("\nHabilidade Cruz:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("%d ", cruz[i][j]);
        printf("\n");
    }

    // Mostra habilidade Octaedro
    printf("\nHabilidade Octaedro:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("%d ", octaedro[i][j]);
        printf("\n");
    }
}

// =======================================================================
// Função principal — mostra o menu e chama o nível correspondente.
// =======================================================================
int main(void) {
    int nivel;
    printf("===== Batalha Naval — Escolha o Nível =====\n");
    printf("1) Novato\n");
    printf("2) Aventureiro\n");
    printf("3) Mestre\n");
    printf("Escolha: ");
    if (scanf("%d", &nivel) != 1) return 0;

    switch (nivel) {
        case 1: nivelNovato(); break;
        case 2: nivelAventureiro(); break;
        case 3: default: nivelMestre(); break;
    }
    return 0;
}