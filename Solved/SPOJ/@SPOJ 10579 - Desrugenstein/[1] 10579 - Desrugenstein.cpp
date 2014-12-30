//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/DESRUG/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

int MAX = 10000000;

int grid, cima, baixo, esq, dir, p;
int matriz[100 + 10][100 + 10];

int main() {
    while (scanf("%d", &grid) && grid != 0) {
        int gridm = grid * grid;
        for (int i = 0; i < gridm; i++)
            for (int j = 0; j < gridm; j++) {
                if (i == j) matriz[i][j] = 0;
                else matriz[i][j] = MAX;
            }
        for (int i = grid - 1; i >= 0; i--)
            for (int j = 0; j < grid; j++) {
                scanf("%d %d %d %d", &cima, &baixo, &esq, &dir);
                int atual = (i * grid) + j;
                if (cima) matriz[atual][(i + 1) * grid + j] = 1;
                if (baixo) matriz[atual][(i - 1) * grid + j] = 1;
                if (esq) matriz[atual][atual - 1] = 1;
                if (dir) matriz[atual][atual + 1] = 1;
            }
        for (int k = 0; k < gridm; k++)
            for (int i = 0; i < gridm; i++)
                for (int j = 0; j < gridm; j++)
                    if (matriz[i][j] > matriz[i][k] + matriz[k][j])
                        matriz[i][j] = matriz[i][k] + matriz[k][j];
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            int l0, c0, l1, c1;
            scanf("%d %d %d %d", &c0, &l0, &c1, &l1);
            int x = (l0 * grid) + c0;
            int y = (l1 * grid) + c1;
            (matriz[x][y] == MAX) ? printf("Impossible\n") : printf("%d\n", matriz[x][y]);
        }
        printf("\n");
    }
    return 0;
}