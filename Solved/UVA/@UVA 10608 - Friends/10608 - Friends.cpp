//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1549

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct tdado {
    int parent;
    int rank;
    int tamanho;
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
        vetor[posicao].tamanho = 1;
        return true;
    }

    int find(int posicao) {
        if (vetor[posicao].parent != posicao)
            posicao = find(vetor[posicao].parent);
        return posicao;
    }

    int _union(int p1, int p2) {
        int p1Root = find(p1);
        int p2Root = find(p2);
        if (p1Root == p2Root) return -1;
        if (vetor[p1Root].rank < vetor[p2Root].rank) {
            vetor[p1Root].parent = p2Root;
            vetor[p2Root].tamanho += vetor[p1Root].tamanho;
            return vetor[p2Root].tamanho;
        } else if (vetor[p1Root].rank > vetor[p2Root].rank) {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].tamanho += vetor[p2Root].tamanho;
            return vetor[p1Root].tamanho;
        } else {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].rank = vetor[p1Root].rank + 1;
            vetor[p1Root].tamanho += vetor[p2Root].tamanho;
            return vetor[p1Root].tamanho;
        }
    }
};

int numero_testes, numero_pessoas, numero_pares, f1, f2;

int main() {
    scanf("%d", &numero_testes);
    while (numero_testes--) {
        scanf("%d %d", &numero_pessoas, &numero_pares);
        UnionFind uf(numero_pessoas + 1);
        int resp = 0;
        for (int i = 0; i < numero_pares; i++) {
            scanf("%d %d", &f1, &f2);
            int temp = uf._union(f1, f2);
            if (resp < temp)
                resp = temp;
        }
        printf("%d\n", resp);
    }
    return 0;
}