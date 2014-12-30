//Author:   Gilberto Alexandre dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1524

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct tdado {
    int parent;
    int rank;
};

class UnionFind {
private:
    int numero_componentes;
    vector<tdado> vetor;
public:

    UnionFind(int tamanho) {
        vetor.reserve(tamanho);
        numero_componentes = tamanho - 1;
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
        if (vetor[posicao].parent != posicao)
           return vetor[posicao].parent = find(vetor[posicao].parent);
		else return posicao;
    }

    bool _union(int p1, int p2) {
        int p1Root = find(p1);
        int p2Root = find(p2);
        if (p1Root == p2Root) return true;
        if (vetor[p1Root].rank < vetor[p2Root].rank) {
            numero_componentes--;
            vetor[p1Root].parent = p2Root;
        } else if (vetor[p1Root].rank > vetor[p2Root].rank) {
            vetor[p2Root].parent = p1Root;
            numero_componentes--;
        } else {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].rank = vetor[p1Root].rank + 1;
            numero_componentes--;
        }
        return true;
    }

    int getNumeroComponentes() {
        return numero_componentes;
    }
};

int numero_estudantes, numero_pares, x, y, caso = 1;

int main() {
    while (scanf("%d %d", &numero_estudantes, &numero_pares) && numero_estudantes != 0) {
        UnionFind uf(numero_estudantes + 1);
        for (int i = 0; i < numero_pares; i++) {
            scanf("%d %d", &x, &y);
            uf._union(x, y);
        }
        printf("Case %d: %d\n", caso++, uf.getNumeroComponentes());
    }
    return 0;
}
