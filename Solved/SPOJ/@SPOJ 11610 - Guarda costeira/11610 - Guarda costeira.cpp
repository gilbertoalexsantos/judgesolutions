//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/GUARDCOS/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>

int main() {
    float distancia, ladrao, guarda, tL, tG, sG;

    while (scanf("%f %f %f", &distancia, &ladrao, &guarda) != EOF) {
        sG = sqrt(distancia * distancia + 144);
        tG = sG / guarda;
        tL = 12 / ladrao;

        if (tG <= tL)
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}


