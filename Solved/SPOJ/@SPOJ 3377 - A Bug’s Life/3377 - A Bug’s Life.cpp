//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/BUGLIFE/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<list>
using namespace std;

int cenarios, nb, ni, X, Y;
bool resp;
int cont = 1;

bool dfc(list<int> grafo[], bool marcado[], bool tipo[], int vertice, bool tp) {
    marcado[vertice] = 1;
    tipo[vertice] = tp;
    for (list<int>::iterator it = grafo[vertice].begin(); it != grafo[vertice].end(); it++) {
        if (!marcado[*it])
            dfc(grafo, marcado, tipo, *it, !tipo[vertice]);
        else if (tipo[vertice] == tipo[*it])
            resp = 1;
    }
}

list<int> grafo[2005];

int main() {
    scanf("%d", &cenarios);
    for (int j = 0; j < cenarios; j++) {
        resp = 0;
        scanf("%d %d", &nb, &ni);
        bool marcado[nb + 1];
        for(int i = 0; i <= nb; i++)
          grafo[i].clear();
        bool tipo[nb + 1];
        for (int i = 0; i <= nb; i++) {
            marcado[i] = 0;
            tipo[i] = 0;
            grafo[i].erase(grafo[i].begin(), grafo[i].end());
        }
        for (int i = 0; i < ni; i++) {
            scanf("%d %d", &X, &Y);
            grafo[X].push_back(Y);
            grafo[Y].push_back(X);
        }
        dfc(grafo, marcado, tipo, 1, 0);
        if (!resp) {
            for (int i = 1; i <= nb; i++) {
                if (!marcado[i])
                    dfc(grafo, marcado, tipo, i, 0);
                if (resp) break;
            }
        }
        printf("Scenario #%d:\n", cont++);
        (resp) ? printf("Suspicious bugs found!\n") : printf("No suspicious bugs found!\n");
    }
    return 0;
}
