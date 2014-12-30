//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/PT07Z/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<list>
using namespace std;

int N, X, Y, tamanho_temp, tamanho_max, vertice_extremo;

void dfs(list<int> grafo[], bool marcado[], int v) {
    marcado[v] = 1;
    for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++) {
        if (!marcado[*it]) {
            tamanho_temp++;
            dfs(grafo, marcado, *it);
        }
    }
    if (tamanho_max < tamanho_temp) {
        vertice_extremo = v;
        tamanho_max = tamanho_temp;
    }
    if (tamanho_temp != 0) tamanho_temp--;
}

list<int> grafo[10005];

int main() {
    scanf("%d", &N);
    bool marcado[N + 1];
    for (int i = 0; i < N + 1; i++)
        marcado[i] = 0;
    for(int i = 0; i <= N; i++)
      grafo[i].clear();
    tamanho_max = 0;
    tamanho_temp = 0;
    vertice_extremo = 0;
    for (int z = 0; z < N - 1; z++) {
        scanf("%d %d", &X, &Y);
        grafo[X].push_back(Y);
        grafo[Y].push_back(X);
    }
    dfs(grafo, marcado, 1);
    tamanho_max = 0;
    tamanho_temp = 0;
    for (int i = 0; i < N + 1; i++)
        marcado[i] = 0;
    dfs(grafo, marcado, vertice_extremo);
    printf("%d", tamanho_max);
    return 0;
}
