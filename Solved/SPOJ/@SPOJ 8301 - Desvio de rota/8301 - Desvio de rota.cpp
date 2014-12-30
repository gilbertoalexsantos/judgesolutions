//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/DESVIO/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<list>
using namespace std;

int n_cidades, n_estradas, n_rotas, cidade_conserto;
list<int> grafo[251 + 1];
int dist[251 + 1];
bool marcado[251 + 1];
int caminho[251 + 1];
priority_queue<pair<int,int> > d_min;
int peso[251 + 1][251 + 1];

void dijkstra(int vert) {
    pair<int,int> temp;
    temp.first = 0;
    temp.second = vert;
    d_min.push(temp);
    dist[vert] = 0;
    caminho[vert] = vert;
    while (!d_min.empty()) {
        vert = d_min.top().second;
        d_min.pop();
        if (!marcado[vert])
            for (list<int>::iterator it = grafo[vert].begin(); it != grafo[vert].end(); it++) {
                if (!marcado[*it]) {
                    if ((vert >= 0) && (vert < n_rotas - 1) && (*it > vert + 1)) continue;
                    if ((dist[*it] == -1) || (dist[*it] > dist[vert] + peso[vert][*it])) {
                        dist[*it] = dist[vert] + peso[vert][*it];
                        caminho[*it] = vert;
                        temp.first = -dist[*it];
                        temp.second = *it;
                        d_min.push(temp);
                    }
                }
            }
        marcado[vert] = 1;
    }
}

int main() {
    while (scanf("%d %d %d %d", &n_cidades, &n_estradas, &n_rotas, &cidade_conserto) && n_cidades != 0) {
        //Zerando variáveis
        for (int i = 0; i < n_cidades; i++) {
            for (int j = 0; j < n_cidades; j++)
                peso[i][j] = -1;
            dist[i] = -1;
            marcado[i] = 0;
            caminho[i] = -1;
            grafo[i].erase(grafo[i].begin(), grafo[i].end());
        }
        //-------------------   
        for (int i = 0; i < n_estradas; i++) {
            int v1, v2, valor;
            scanf("%d %d %d", &v1, &v2, &valor);
            peso[v1][v2] = valor;
            peso[v2][v1] = valor;
            grafo[v1].push_back(v2);
            grafo[v2].push_back(v1);
        }
        dijkstra(cidade_conserto);
        printf("%d\n", dist[n_rotas - 1]);
    }
    return 0;
}
