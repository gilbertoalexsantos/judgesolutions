//Author:    Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/TUBOS/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int N, M, A, B;
bool achou;
int contador_visita;
//Vértice pai da árvore da DFS
int v_pai[1000 + 1];
//Menor número de pre-ordem que pode ser alcançado a partir de "V"
int v_low[1000 + 1];
//Caminho de valor mínimo (percorre no máximo 1)
int v_cm[1000 + 1];
list<int> array[1000 + 1];

int ponte(int vertice) {
    if (achou == true) {
        return 0;
    }
    v_cm[vertice] = contador_visita++;
    v_low[vertice] = v_cm[vertice];
    list<int>::iterator it;
    for (it = array[vertice].begin(); it != array[vertice].end(); it++) {
        if (v_cm[*it] == -1) {
            v_pai[*it] = vertice;
            ponte(*it);
            if (v_low[vertice] > v_low[*it]) {
                v_low[vertice] = v_low[*it];
            }
            if (v_low[*it] == v_cm[*it]) {
                achou = true;
                return 0;
            }
        } else {
            if ((*it != v_pai[vertice]) && (v_low[vertice] > v_cm[*it])) {
                v_low[vertice] = v_cm[*it];
            }
        }
    }
    return -1;
}

int encontra_ponte() {
    for (int i = 1; i <= M; i++) {
        if (achou == true) {
            return 0;
        }
        if (v_cm[i] == -1) {
            v_pai[i] = i;
            ponte(i);
        }
    }
    return -1;
}

int main() {
    while (scanf("%d", &N) && N != 0) {
        achou = false;
        contador_visita = 0;

        //Limpando listas e colocando 0 no contador de vértices
        for (int i = 0; i < 1001; i++) {
            array[i].clear();
            v_pai[i] = 0;
            v_low[i] = 0;
            v_cm[i] = -1;
        }

        scanf("%d", &M);
        for (int i = 1; i <= M; i++) {
            scanf("%d%d", &A, &B);
            array[A].push_back(B);
            array[B].push_back(A);
        }

        encontra_ponte();

        if (achou == true) {
            cout << "N";
        } else {
            cout << "S";
        }
        cout << "\n";
    }
    return 0;
}
