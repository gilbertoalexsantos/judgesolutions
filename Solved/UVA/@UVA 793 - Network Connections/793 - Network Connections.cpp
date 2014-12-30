//Author: Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=734

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

    bool sameParent(int p1, int p2) {
        return (find(p1) == find(p2));
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
};

int testes, numero_computadores, n1, n2;
char tipo;

int main() {
    scanf("%d", &testes);
    while (testes--) {
        int certo = 0, errado = 0;
        scanf("%d", &numero_computadores);
        UnionFind x(numero_computadores + 1);
        getchar();
        tipo = getchar();
        while ((tipo != '\n') && (tipo != EOF)) {
            scanf("%d %d", &n1, &n2);
            if (tipo == 'c') x._union(n1, n2);
            else (x.sameParent(n1, n2)) ? certo++ : errado++;
            getchar();
            tipo = getchar();
        }
        printf("%d,%d\n", certo, errado);
        if (testes) printf("\n");
    }
    return 0;
}
