/*
 * Jogo de Batalha Naval Simples
 * Este programa inicializa um tabuleiro, posiciona navios aleatoriamente e aplica habilidades em padrões específicos.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 // Definições de tamanho do tabuleiro e valores para navios e habilidades
 #define TAMANHO 10
 #define NAVIO 3
 #define HABILIDADE 5
 
 // Função para exibir o tabuleiro no terminal
 void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
     printf("   A B C D E F G H I J\n");
     for (int i = 0; i < TAMANHO; i++) {
         printf("%2d ", i + 1);
         for (int j = 0; j < TAMANHO; j++)
             printf("%d ", tabuleiro[i][j]);
         printf("\n");
     }
 }
 
 // Função para inicializar o tabuleiro com valores zerados
 void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
     for (int i = 0; i < TAMANHO; i++)
         for (int j = 0; j < TAMANHO; j++)
             tabuleiro[i][j] = 0;
 }
 
 // Função para posicionar um navio de tamanho especificado aleatoriamente
 void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int tamanho) {
     int linha, coluna, orientacao, valido;
     do {
         valido = 1;
         linha = rand() % TAMANHO;
         coluna = rand() % TAMANHO;
         orientacao = rand() % 2; // 0 para horizontal, 1 para vertical
 
         // Verifica se o navio pode ser colocado sem ultrapassar os limites ou colidir com outro navio
         for (int i = 0; i < tamanho; i++) {
             int x = linha + (orientacao ? i : 0);
             int y = coluna + (orientacao ? 0 : i);
             if (x >= TAMANHO || y >= TAMANHO || tabuleiro[x][y] != 0) {
                 valido = 0;
                 break;
             }
         }
 
         // Se válido, posiciona o navio no tabuleiro
         if (valido)
             for (int i = 0; i < tamanho; i++)
                 tabuleiro[linha + (orientacao ? i : 0)][coluna + (orientacao ? 0 : i)] = NAVIO;
     } while (!valido);
 }
 
 // Função para aplicar uma habilidade no tabuleiro em um padrão específico
 void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int matriz[5][5]) {
     for (int i = 0; i < 5; i++)
         for (int j = 0; j < 5; j++) {
             int x = linha + i - 2; // Centraliza a matriz no ponto desejado
             int y = coluna + j - 2;
             if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && matriz[i][j])
                 tabuleiro[x][y] = HABILIDADE;
         }
 }
 
 int main() {
     int tabuleiro[TAMANHO][TAMANHO];
     srand(time(NULL)); // Inicializa a semente de números aleatórios
 
     inicializarTabuleiro(tabuleiro);
 
     // Posiciona dois navios de tamanho 3
     posicionarNavio(tabuleiro, 3);
     posicionarNavio(tabuleiro, 3);
 
     // Definição de padrões de habilidades
     int cone[5][5] = {
         {0, 0, 1, 0, 0},
         {0, 1, 1, 1, 0},
         {1, 1, 1, 1, 1},
         {0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0}
     };
 
     int cruz[5][5] = {
         {0, 0, 1, 0, 0},
         {0, 0, 1, 0, 0},
         {1, 1, 1, 1, 1},
         {0, 0, 1, 0, 0},
         {0, 0, 1, 0, 0}
     };
 
     int octaedro[5][5] = {
         {0, 0, 1, 0, 0},
         {0, 1, 1, 1, 0},
         {1, 1, 1, 1, 1},
         {0, 1, 1, 1, 0},
         {0, 0, 1, 0, 0}
     };
 
     // Aplica as habilidades em posições aleatórias
     aplicarHabilidade(tabuleiro, rand() % TAMANHO, rand() % TAMANHO, cone);
     aplicarHabilidade(tabuleiro, rand() % TAMANHO, rand() % TAMANHO, cruz);
     aplicarHabilidade(tabuleiro, rand() % TAMANHO, rand() % TAMANHO, octaedro);
 
     // Exibe o tabuleiro final
     exibirTabuleiro(tabuleiro);
     return 0;
 }
 