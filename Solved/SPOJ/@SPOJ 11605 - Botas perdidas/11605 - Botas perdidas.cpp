//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/BOTAS/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int esq[61];
int dir[61];

int n;
int x;
char c;

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 30; i <= 60; i++) {
            esq[i] = 0;
            dir[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %c", &x, &c);
            if (c == 'D') dir[x]++;
            else esq[x]++;
        }
        int resp = 0;
        for (int i = 30; i <= 60; i++)
            resp += min(esq[i], dir[i]);
        printf("%d\n", resp);
    }
    return 0;
}


