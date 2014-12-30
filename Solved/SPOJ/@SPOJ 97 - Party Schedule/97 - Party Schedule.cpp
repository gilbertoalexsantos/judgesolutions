//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/PARTY/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct bag {
    int preco;
    int felicidade;
};

int matriz[100 + 10][500 + 10][2];
int t_mochila, q_itens;

bag mochila(int t_mochila, int q_itens, bag dados[]) {
    bag resp;
    for (int i = 1; i <= q_itens; i++) {
        for (int j = 0; j <= t_mochila; j++) {
            matriz[i][j][0] = matriz[i - 1][j][0];
            matriz[i][j][1] = matriz[i - 1][j][1];
            if (j - dados[i].preco >= 0) {
                if (matriz[i][j][0] < matriz[i - 1][j - dados[i].preco][0] + dados[i].felicidade) {
                    matriz[i][j][0] = matriz[i - 1][j - dados[i].preco][0] + dados[i].felicidade;
                    matriz[i][j][1] = matriz[i - 1][j - dados[i].preco][1] + dados[i].preco;
                } else if (matriz[i][j][0] == matriz[i - 1][j - dados[i].preco][0] + dados[i].felicidade) {
                    if (matriz[i][j][1] > matriz[i - 1][j - dados[i].preco][1] + dados[i].preco) {
                        matriz[i][j][0] = matriz[i - 1][j - dados[i].preco][0] + dados[i].felicidade;
                        matriz[i][j][1] = matriz[i - 1][j - dados[i].preco][1] + dados[i].preco;
                    }
                }
            }
        }
    }
    resp.felicidade = matriz[q_itens][t_mochila][0];
    resp.preco = matriz[q_itens][t_mochila][1];
    return resp;
}

int main() {
    while (scanf("%d %d", &t_mochila, &q_itens) && !(t_mochila == 0 && q_itens == 0)) {
        for (int z = 0; z < 2; z++)
            for (int i = 0; i <= q_itens; i++)
                for (int j = 0; j <= t_mochila; j++)
                    matriz[i][j][z] = 0;
        bag dados[q_itens + 1];
        for (short i = 1; i <= q_itens; i++)
            scanf("%d %d", &dados[i].preco, &dados[i].felicidade);
        bag temp = mochila(t_mochila, q_itens, dados);
        printf("%d %d\n", temp.preco, temp.felicidade);
    }
    return 0;
}
