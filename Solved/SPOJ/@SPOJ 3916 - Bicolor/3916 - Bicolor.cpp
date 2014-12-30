//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/BICOLOR/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int n, l, u, v;
list<int> array[200];

/*
-1 no final da lista = Não Marcado
0 no final da lista = Cor 1
1 no final da lista = Cor 2
 */
void DFS(int vertice, int cor) {
    array[vertice].pop_back();
    array[vertice].push_back(cor);
    list<int>::iterator it;
    for (it = array[vertice].begin(); it != array[vertice].end(); it++) {
        if (array[*it].back() == -1) {
            if (cor == 0) {
                DFS(*it, 1);
            } else {
                DFS(*it, 0);
            }
        }
    }
}

int main() {
    while (scanf("%d", &n) && n != 0) {
        // Zerando as listas
        for (int i = 0; i < 200; i++) {
            array[i].clear();
        }
        scanf("%d", &l);
        for (int i = 0; i < l; i++) {
            scanf("%d%d", &u, &v);
            array[u].push_back(v);
            array[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            array[i].push_back(-1);
        }
        DFS(0, 0);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int cor = array[i].back();
            list<int>::iterator it, x;
            for (it = array[i].begin(); it != array[i].end(); it++) {
                // [Start] 
                // Condição para não pegar o último valor da lista, que corresponde a cor
                x = it;
                if (++x == array[i].end()) {
                    break;
                }
                // [End]
                if (array[*it].back() == cor) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                break;
            }
        }
        if (flag == false) {
            cout << "NOT BICOLORABLE.";
        } else {
            cout << "BICOLORABLE.";
        }
        cout << "\n";
    }
    return 0;
}