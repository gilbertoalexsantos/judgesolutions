//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2035

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<list>
using namespace std;

int M, N, X, Y;
char matriz[20][20];
list<int> grafo[20 * 20];
int marcado[20 * 20], qt_vertices, qt_temp;
char valor[20 * 20];
char land;

void dfs_inicial(int v) {
    marcado[v] = 1;
    for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++) {
        if (!marcado[*it]) dfs_inicial(*it);
    }
}

void dfs_final(int v) {
    marcado[v] = 1;
    qt_temp++;
    for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++) {
        if (!marcado[*it]) dfs_final(*it);
    }
}

int main() {
    while (scanf("%d %d", &M, &N) != EOF) {
        // Inicializando variáveis
        for (int i = 0; i < M * N; i++) {
            grafo[i].erase(grafo[i].begin(), grafo[i].end());
            marcado[i] = 0;
        }
        qt_vertices = 0;
        qt_temp = 0;
        // -----------------------
        for (int l = 0; l < M; ++l)
            scanf("%s", matriz[l]);
        scanf("%d %d", &X, &Y);
        int vertice = X * N + Y;
        land = matriz[X][Y];
        /*
         * Transformando a matriz em um grafo
         */
        for (int l = 0; l < M; l++) {
            for (int c = 0; c < N; c++) {
                int posicao_atual = l * N + c;
                if (matriz[l][c] == land) {
                    if ((l != 0) && (matriz[l - 1][c] == land)) {
                        int posicao_cima = (l - 1) * N + c;
                        grafo[posicao_atual].push_back(posicao_cima);
                        grafo[posicao_cima].push_back(posicao_atual);
                    }
                    if ((c != 0) && (matriz[l][c - 1] == land)) {
                        int posicao_esq = l * N + c - 1;
                        grafo[posicao_atual].push_back(posicao_esq);
                        grafo[posicao_esq].push_back(posicao_atual);
                    }
                } else
                    marcado[posicao_atual] = 1;
            }
        }
        /*
         * Pegando a condição especial de adjacência (*)
         */
        for (int i = 0; i < M; i++) {
            if ((matriz[i][0] == land) && (matriz[i][N - 1] == land)) {
                int p_esq = i * N;
                int p_dir = i * N + N - 1;
                grafo[p_esq].push_back(p_dir);
                grafo[p_dir].push_back(p_esq);
            }
        }
        dfs_inicial(vertice);
        for (int i = 0; i < M * N; i++) {
            if (!marcado[i]) {
                dfs_final(i);
                if (qt_vertices < qt_temp)
                    qt_vertices = qt_temp;
                qt_temp = 0;
            }
        }
        printf("%d\n", qt_vertices);
    }
    return 0;
}
