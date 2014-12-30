//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/OLIMPJ09/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> x, pair<int, int> y) {
    if (x.second == y.second)
        return x.first < y.first;
    else
        return x.second > y.second;
}

pair<int, int> paises[200];

int main() {
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);
    int O = 0, P = 0, B = 0;
    for (short i = 0; i < N; i++) {
        paises[i].first = i;
        paises[i].second = 0;
    }
    for (short i = 0; i < M; i++) {
        scanf("%d %d %d", &O, &P, &B);
        paises[O - 1].second++;
        paises[P - 1].second++;
        paises[B - 1].second++;
    }
    sort(paises, paises + N, comp);
    for (short i = 0; i < N; i++) {
        printf("%d ", paises[i].first + 1);
    }
    puts("");
    return 0;
}
