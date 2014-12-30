//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/SVADA/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int T, N, M;

struct t {
    int ti;
    int te;
};

t monkey1[100], monkey2[100];

int resp = 0;

int bb(int esq, int dir) {
    while (esq + 1 < dir) {
        int meio = (esq + dir) / 2;
        int c1 = 0, c2 = 0;
        for (int j = 0; j < N; j++) {
            int tempo = T - meio;
            if (tempo >= monkey1[j].ti) {
                tempo = tempo - monkey1[j].ti;
                c1++;
                c1 += tempo / monkey1[j].te;
            }
        }
        for (int j = 0; j < M; j++) {
            int tempo = meio;
            if (tempo >= monkey2[j].ti) {
                tempo = tempo - monkey2[j].ti;
                c2++;
                c2 += tempo / monkey2[j].te;
            }
        }
		(c1 <= c2) ? dir = meio : esq = meio;
    }
    return T - dir;
}

int main() {
    scanf("%d", &T);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d %d", &monkey1[i].ti, &monkey1[i].te);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) scanf("%d %d", &monkey2[i].ti, &monkey2[i].te);
    printf("%d\n", bb(0,T));
    return 0;
}
