//Author: Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/REDOTICA/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct tdado {
    int parent;
    int rank;
};

class UnionFind {
private:
    vector<tdado> vetor;
public:

    UnionFind(int tamanho) {
        vetor.reserve(tamanho);
        for (int i = 0; i < tamanho; i++)
            makeset(i);
    }

    ~UnionFind() {
    }

    bool makeset(int posicao) {
        vetor[posicao].parent = posicao;
        vetor[posicao].rank = 0;
        return true;
    }

    int find(int posicao) {
        if (vetor[posicao].parent == posicao) return posicao;
        else return vetor[posicao].parent = find(vetor[posicao].parent);
    }

    bool _union(int p1, int p2) {
        int p1Root = find(p1);
        int p2Root = find(p2);
        if (p1Root == p2Root) return true;
        if (vetor[p1Root].rank < vetor[p2Root].rank)
            vetor[p1Root].parent = p2Root;
        else if (vetor[p1Root].rank > vetor[p2Root].rank)
            vetor[p2Root].parent = p1Root;
        else {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].rank = vetor[p1Root].rank + 1;
        }
        return true;
    }

    int compDist(int p1, int p2) {
        return find(p1) == find(p2);
    }
};

struct aresta {
    int v1;
    int v2;
    int peso;
};

int comp(aresta x, aresta y) {
    return x.peso < y.peso;
}

int numero_tabas, numero_ramos;
aresta x;

int main() {
    int numero_teste = 1;
    while (scanf("%d %d", &numero_tabas, &numero_ramos) && numero_tabas != 0) {
        aresta arestas[numero_ramos];
        UnionFind uf(numero_ramos + 1);
        for (int i = 0; i < numero_ramos; i++) {
            scanf("%d %d %d", &x.v1, &x.v2, &x.peso);
            arestas[i] = x;
        }
        sort(arestas, arestas + numero_ramos, comp);
        printf("Teste %d\n", numero_teste++);
        for (int i = 0, k = 0; i < numero_ramos; i++) {
            if (!uf.compDist(arestas[i].v1, arestas[i].v2)) {
                uf._union(arestas[i].v1, arestas[i].v2);
                if (arestas[i].v1 < arestas[i].v2) {
                    printf("%d %d", arestas[i].v1, arestas[i].v2);
                } else {
                    printf("%d %d", arestas[i].v2, arestas[i].v1);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
