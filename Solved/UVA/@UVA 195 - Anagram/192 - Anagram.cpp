//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=131

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include <cstring>
using namespace std;

bool troca(char x, char y) {
    int number = tolower(x) - tolower(y);
    return number ? number < 0 : (x < y);
}

int main() {
    int x = 0;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char c[1000];
        scanf("%s", c);
        int tamanho = strlen(c);
        sort(c, c + tamanho, troca);
        do {
            for (int j = 0; j < tamanho; j++)
                printf("%c", c[j]);
            printf("\n");
        } while (next_permutation(c, c + tamanho, troca));
    }
    return 0;
}
