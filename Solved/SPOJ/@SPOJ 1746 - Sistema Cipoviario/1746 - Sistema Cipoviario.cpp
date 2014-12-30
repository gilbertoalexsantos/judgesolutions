//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/CIPO/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

struct tdado {
    int parent;
    int rank;
};

class UnionFind {
private:
    vector<tdado> vetor;
    int tamanho;
public:

    UnionFind(int tamanho) {
        vetor.reserve(tamanho);
        this->tamanho = tamanho;
        for (int i = 0; i < tamanho; i++)
            makeset(i);
    }

    ~UnionFind() {
    }

    void makeset(int posicao) {
        vetor[posicao].parent = posicao;
        vetor[posicao].rank = 0;
    }

    int find(int posicao) {
        if (vetor[posicao].parent != posicao)
            posicao = find(vetor[posicao].parent);
        return posicao;
    }

    void zera() {
        for (int i = 0; i < tamanho; i++)
            makeset(i);
    }

    bool _union(int p1Root, int p2Root) {
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
        return p1 == p2;
    }
};

struct aresta {
    int v1;
    int v2;
    int peso;
};

int numero_pontos_cipo, numero_cipo;
aresta temp;
UnionFind uf(1000 + 5);
stack<aresta> aresta1;
stack<aresta> aresta2;
stack<aresta> aresta3;

int main() {
    int instancia = 1;
    while (scanf("%d %d", &numero_pontos_cipo, &numero_cipo) != EOF) {
        uf.zera();
        for (int i = 0; i < numero_cipo; i++) {
            scanf("%d %d %d", &temp.v1, &temp.v2, &temp.peso);
            if (temp.peso == 1235) aresta1.push(temp);
            else if (temp.peso == 8977) aresta2.push(temp);
            else aresta3.push(temp);
        }
        int resp = 0;
        while (!aresta1.empty()) {
            temp = aresta1.top();
            aresta1.pop();
            int findV1 = uf.find(temp.v1);
            int findV2 = uf.find(temp.v2);
            if (!uf.compDist(findV1, findV2)) {
                uf._union(findV1, findV2);
                resp += temp.peso;
            }
        }
        while (!aresta2.empty()) {
            temp = aresta2.top();
            aresta2.pop();
            int findV1 = uf.find(temp.v1);
            int findV2 = uf.find(temp.v2);
            if (!uf.compDist(findV1, findV2)) {
                uf._union(findV1, findV2);
                resp += temp.peso;
            }
        }
        while (!aresta3.empty()) {
            temp = aresta3.top();
            aresta3.pop();
            int findV1 = uf.find(temp.v1);
            int findV2 = uf.find(temp.v2);
            if (!uf.compDist(findV1, findV2)) {
                uf._union(findV1, findV2);
                resp += temp.peso;
            }
        }
        printf("Instancia %d\n%d\n\n", instancia++, resp);
    }
    return 0;
}