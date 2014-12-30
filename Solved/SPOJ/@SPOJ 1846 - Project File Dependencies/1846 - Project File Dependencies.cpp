//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/PFDEP/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;

int N, M, T, k;

int grau[100 + 1] = {0};
list<int> grafo[100 + 1];
stack<int> auxiliar;
stack<int> pilha;

bool comp(int x, int y) {
    return x > y;
}

/*
 * Ordenando os de grau 0 (De uma maneira "feia", mas como tem pouco elementos,
 * a complexidade não sobe consideravelmente)
 */
void empilha_certo() {
    int t = auxiliar.size();
    int vetor[t];
    int cont = 0;
    while (!auxiliar.empty()) {
        vetor[cont++] = auxiliar.top();
        auxiliar.pop();
    }
    sort(vetor, vetor + t, comp);
    for (int i = 0; i < t; i++)
        pilha.push(vetor[i]);
}

void ordenacao_topologica() {
    for (int i = 1; i <= N; i++)
        if (grau[i] == 0)
            auxiliar.push(i);
    empilha_certo();
    while (!pilha.empty()) {
        int v = pilha.top();
        printf("%d ", v);
        pilha.pop();
        for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++) {
            grau[*it]--;
            if (grau[*it] == 0)
                auxiliar.push(*it);
        }
        empilha_certo();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d", &T, &k);
        for (int i = 0; i < k; i++) {
            int temp;
            scanf("%d", &temp);
            grafo[temp].push_back(T);
            grau[T]++;
        }
    }
    ordenacao_topologica();   
    return 0;
}