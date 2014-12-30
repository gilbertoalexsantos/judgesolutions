//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/CAVALOS/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stack>
using namespace std;

int MAX = 100000000;

int n_cavalos, n_soldados, n_afinidades;
int grafo[200 + 10][200 + 10];
int caminho[200 + 10];
bool marcado[200 + 10];

void zera() {
    for (int i = 0; i <= (n_cavalos + n_soldados + 3); i++) {
        marcado[i] = 0;
        caminho[i] = -1;
    }
}

bool dfs(int x, int y) {
    zera();
    stack<int> pilha;
    caminho[x] = x;
    marcado[x] = 1;
    pilha.push(x);
    while (!pilha.empty()) {
        int vertice = pilha.top();
        pilha.pop();
        for (int i = 0; i <= y; i++) {
            if ((!marcado[i]) && (grafo[vertice][i] > 0)) {
                marcado[i] = 1;
                caminho[i] = vertice;
                if (i == y) return true;
                pilha.push(i);
            }
        }
    }
    return false;
}

int edmonds_karp(int x, int y) {
    int maior = 0;
    while (dfs(x, y)) {
        int fluxo = MAX;
        int a = y, b;
        while (a != x) {
            b = caminho[a];
            fluxo = min(fluxo, grafo[b][a]);
            a = caminho[a];
        }
        a = y;
        while (a != x) {
            b = caminho[a];
            grafo[b][a] -= fluxo;
            grafo[a][b] += fluxo;
            a = caminho[a];
        }
        maior++;
    }
    return maior;
}

int main() {
    int instancia = 1;
    while (scanf("%d %d %d", &n_cavalos, &n_soldados, &n_afinidades) != EOF) {
        int s = 0, t = (n_cavalos + n_soldados + 1);
        for (int i = 0; i <= t; i++)
            for (int j = 0; j <= t; j++)
                grafo[i][j] = 0;
        for (int i = 1; i <= n_cavalos; i++)
            scanf("%d", &grafo[0][i]);
        for (int i = (n_cavalos + 1); i < t; i++)
            grafo[i][t] = 1;
        for (int i = 0; i < n_afinidades; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int vertice = (n_cavalos + y);
            grafo[x][vertice] = 1;
            grafo[vertice][x] = 0;
        }
        printf("Instancia %d\n", instancia++);
        printf("%d\n\n", edmonds_karp(s, t));
    }
    return 0;
}