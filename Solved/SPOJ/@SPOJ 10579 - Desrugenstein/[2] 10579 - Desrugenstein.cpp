//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/DESRUG/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct lig {
    int v;
    int p;
};

class mycomparison {
    bool reverse;
public:

    mycomparison(const bool& revparam = false) {
        reverse = revparam;
    }

    bool operator() (const lig& lhs, const lig&rhs) const {
        if (reverse) return (lhs.p < rhs.p);
        else return (lhs.p > rhs.p);
    }
};

int MAX = 10000000;

int grid, cima, baixo, esq, dir, p;
int matriz[100 + 10][100 + 10];
priority_queue<lig, vector<lig>, mycomparison> d_min;
bool marcado[100 + 10];
int dist[100 + 10];

int dijkstra(int x, int y) {
    lig temp;
    temp.p = 0;
    temp.v = x;
    d_min.push(temp);
    dist[x] = 0;
    int vert;
    while (!d_min.empty()) {
        temp = d_min.top();
        vert = temp.v;
        d_min.pop();
        if (!marcado[vert])
            for (int it = 0; it < (grid * grid); it++) {
                if (!marcado[it]) {
                    if ((matriz[vert][it] == MAX) || (vert == it)) continue;
                    if ((dist[it] == -1) || (dist[it] > dist[vert] + matriz[vert][it])) {
                        dist[it] = dist[vert] + matriz[vert][it];
                        lig temp;
                        temp.p = dist[it];
                        temp.v = it;
                        d_min.push(temp);
                    }
                }
            }
        marcado[vert] = 1;
    }
    return dist[y];
}

void zera() {
    for (int i = 0; i < (grid * grid); i++) {
        dist[i] = -1;
        marcado[i] = 0;
    }
}

int main() {
    while (scanf("%d", &grid) && grid != 0) {
        int gridm = grid * grid;
        zera();
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
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            int l0, c0, l1, c1;
            scanf("%d %d %d %d", &c0, &l0, &c1, &l1);
            int x = (l0 * grid) + c0;
            int y = (l1 * grid) + c1;
            int resp = dijkstra(x, y);
            (resp == -1) ? printf("Impossible\n") : printf("%d\n", resp);
            zera();
        }
        printf("\n");
    }
    return 0;
}