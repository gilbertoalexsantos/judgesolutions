//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1099

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

struct tdado {
    int parent;
    int rank;
    int inimigo;
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
        vetor[posicao].inimigo = posicao;
        vetor[posicao].parent = posicao;
        vetor[posicao].rank = 0;
        return true;
    }

    int find(int posicao) {
        if (vetor[posicao].parent == posicao) return posicao;
        else return vetor[posicao].parent = find(vetor[posicao].parent);
    }

    int _union(int p1Root, int p2Root) {
        if (vetor[p1Root].rank < vetor[p2Root].rank) {
            vetor[p1Root].parent = p2Root;
            return p2Root;
        } else if (vetor[p1Root].rank > vetor[p2Root].rank) {
            vetor[p2Root].parent = p1Root;
            return p1Root;
        } else {
            vetor[p2Root].parent = p1Root;
            vetor[p1Root].rank += 1;
            return p1Root;
        }
    }

    int getInimigo(int p) {
        return vetor[p].inimigo;
    }

    bool atualizaInimigo(int x, int y) {
        vetor[x].inimigo = y;
        vetor[y].inimigo = x;
        return true;
    }

    bool eInimigo(int x, int y) {
        if ((getInimigo(x) == y) || (getInimigo(y) == x))
            return true;
        else return false;
    }
};

int numero_pessoas, tipo, f1, f2;

int main() {
    scanf("%d", &numero_pessoas);
    UnionFind uf(numero_pessoas + 2);
    while (scanf("%d %d %d", &tipo, &f1, &f2) && tipo != 0) {
        if (tipo == 1) {
            if (f1 != f2) {
                int fr1 = uf.find(f1);
                int fr2 = uf.find(f2);
                if (uf.eInimigo(fr1, fr2)) printf("-1\n");
                else if ((uf.getInimigo(fr1) == fr1) && (uf.getInimigo(fr2) != fr2)) {
                    int maiorRank = uf._union(fr1, fr2);
                    uf.atualizaInimigo(maiorRank, uf.getInimigo(fr2));
                } else if ((uf.getInimigo(fr1) != fr1) && (uf.getInimigo(fr2) == fr2)) {
                    int maiorRank = uf._union(fr1, fr2);
                    uf.atualizaInimigo(maiorRank, uf.getInimigo(fr1));
                } else if ((uf.getInimigo(fr1) != fr1) && (uf.getInimigo(fr2) != fr2)) {
                    int maiorRank1 = uf._union(uf.getInimigo(fr1), uf.getInimigo(fr2));
                    int maiorRank2 = uf._union(fr1, fr2);
                    uf.atualizaInimigo(maiorRank1, maiorRank2);
                } else {
                    uf._union(fr1, fr2);
                }
            }
        } else if (tipo == 2) {
            int fr1 = uf.find(f1);
            int fr2 = uf.find(f2);
            if (fr1 == fr2) printf("-1\n");
            else {
                if ((uf.getInimigo(fr1) == fr1) && (uf.getInimigo(fr2) != fr2)) {
                    int maiorRank = uf._union(fr1, uf.getInimigo(fr2));
                    uf.atualizaInimigo(maiorRank, fr2);
                } else if ((uf.getInimigo(fr1) != fr1) && (uf.getInimigo(fr2) == fr2)) {
                    int maiorRank = uf._union(uf.getInimigo(fr1), fr2);
                    uf.atualizaInimigo(maiorRank, fr1);
                } else if ((uf.getInimigo(fr1) != fr1) && (uf.getInimigo(fr2) != fr2)) {
                    int maiorRank1 = uf._union(fr1, uf.getInimigo(fr2));
                    int maiorRank2 = uf._union(uf.getInimigo(fr1), fr2);
                    uf.atualizaInimigo(maiorRank1, maiorRank2);
                } else {
                    uf.atualizaInimigo(fr1, fr2);
                }
            }
        } else if (tipo == 3) {
            int fr1 = uf.find(f1);
            int fr2 = uf.find(f2);
            if (fr1 == fr2) printf("1\n");
            else printf("0\n");
        } else {
            int fr1 = uf.find(f1);
            int fr2 = uf.find(f2);
            if (fr1 == fr2) printf("0\n");
            else printf("%d\n", uf.eInimigo(fr1, fr2));
        }
    }
    return 0;
}