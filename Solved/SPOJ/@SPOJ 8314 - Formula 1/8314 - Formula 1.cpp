//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/FORMULA/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct d {
    int pos;
    int n;
};

d posicao[101];
vector<int> corredor[101];
int pontos[101];
int g, p, s, k;

void zera() {
    for (int i = 0; i < 101; i++) {
        posicao[i].pos = -1;
        posicao[i].n = -1;
        pontos[i] = -1;
    }
}

bool compare(d x, d y) {
    if (x.n == y.n) {
        return x.pos < y.pos;
    }
    return x.n > y.n;
}

int main() {
    while (scanf("%d %d", &g, &p) && g != 0) {
        for (int i = 0; i <= p; i++) {
            corredor[i].clear();
        }
        for (int i = 0; i < g; i++) {
            for (int j = 1; j <= p; j++) {
                int temp;
                scanf("%d", &temp);
                corredor[j].push_back(temp);
            }
        }
        scanf("%d", &s);
        for (int i = 0; i < s; i++) {
            zera();
            scanf("%d", &k);
            for (int j = 1; j <= k; j++) {
                scanf("%d", &pontos[j]);
            }

            for (int j = 1; j <= p; j++) {
                posicao[j].pos = j;
                for (unsigned int z = 0; z < corredor[j].size(); z++) {
                    if (corredor[j][z] <= k)
                        posicao[j].n += pontos[corredor[j][z]];
                }
            }


            sort(posicao + 1, posicao + p + 1, compare);


            if (p == 1)
                printf("1");
            else {
                int cont = 1;
                printf("%d", posicao[cont].pos);
                while ((posicao[cont].n == posicao[cont + 1].n) && cont <= p) {
                    printf(" %d", posicao[cont + 1].pos);
                    cont++;
                }
            }
            printf("\n");
        }
    }
    return 0;
}

