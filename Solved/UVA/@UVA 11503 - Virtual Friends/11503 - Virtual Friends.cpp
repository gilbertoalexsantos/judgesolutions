//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

struct tdado {
    string parent;
    int rank;
    int valor;
};

class UnionFind {
private:
    map<string, tdado> vetor;
public:

    UnionFind() {
    }

    ~UnionFind() {
    }

    bool addName(string name) {
        if (vetor[name].parent == "") vetor[name].parent = name;
    }

    string find(string posicao) {
        if (vetor[posicao].parent != posicao)
            posicao = find(vetor[posicao].parent);
        return posicao;
    }

    bool _union(string p1Root, string p2Root) {
        if (p1Root == p2Root) return true;
        if (vetor[p1Root].rank < vetor[p2Root].rank) {
            vetor[p1Root].parent = p2Root;
            vetor[p2Root].valor += vetor[p1Root].valor + 1;
        } else if (vetor[p1Root].rank > vetor[p2Root].rank) {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].valor += vetor[p2Root].valor + 1;
        } else {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].rank++;
            vetor[p1Root].valor += vetor[p2Root].valor + 1;
        }
        return true;
    }

    int getValor(string posicao) {
        return vetor[posicao].valor;
    }

};

int numero_testes, numero_amigos;
string n1, n2;

int main() {
    scanf("%d", &numero_testes);
    while (numero_testes--) {
        UnionFind uf;
        scanf("%d", &numero_amigos);
        for (int i = 0; i < numero_amigos; i++) {
            cin >> n1;
            cin >> n2;
            uf.addName(n1);
            uf.addName(n2);
            string p1 = uf.find(n1);
            string p2 = uf.find(n2);
            int resp = 0;
            if (p1 != p2)
                resp = (uf.getValor(p1) + 1) + (uf.getValor(p2) + 1);
            else
                resp = (uf.getValor(p1) + 1);
            uf._union(p1, p2);
            printf("%d\n", resp);
        }
    }
    return 0;
}