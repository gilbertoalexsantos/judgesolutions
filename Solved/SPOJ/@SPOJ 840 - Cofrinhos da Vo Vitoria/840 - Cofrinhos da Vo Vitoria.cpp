//Author:   Gilberto Alexandre dos Santos
//Website:  http://migre.me/bX1dy

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short N = 0, contador = 0;
    while(scanf("%hd",&N) && N != 0) {
        short J = 0, Z = 0, dif = 0, resposta[N];
        for(short i = 0; i < N; i++) {
            scanf("%hd %hd",&J,&Z);
            if(dif == 0) 
                dif = J - Z;
            else if(dif < 0) 
                dif = J - (Z + -dif);
            else
                dif = (J + dif) - Z;
            resposta[i] = dif;
        }
        printf("Teste %hd\n",++contador);
        for(short i = 0; i < N; i++)
            printf("%hd\n",resposta[i]);
        printf("\n");
    }     
    return 0;
}