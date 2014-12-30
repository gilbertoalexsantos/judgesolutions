//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.pl/problems/PAR/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short N = 0, contador = 0;
    while (scanf("%hd", &N) && N != 0) {
        char nome1[11], nome2[11];
        bool resposta[N];
        short x = 0, y = 0;
        scanf("%s", nome1);
        scanf("%s", nome2);
        for (short i = 0; i < N; i++) {
            scanf("%hd %hd", &x, &y);
            if( (x + y) == 0 )
                resposta[i] = 0;                
            else if( ((x + y) % 2) == 0) 
                resposta[i] = 0;
            else
                resposta[i] = 1;
        }
        printf("Teste %hd\n",++contador);
        for(short i = 0; i < N; i++) {
            if(resposta[i])
                printf("%s\n",nome2);
            else
                printf("%s\n",nome1);
        }
        printf("\n");
    }
    return 0;
}