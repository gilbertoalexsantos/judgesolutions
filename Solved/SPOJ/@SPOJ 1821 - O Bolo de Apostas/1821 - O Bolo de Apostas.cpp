//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/BAPOSTAS/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
    int N = 0;
    while(scanf("%d",&N) && N != 0) {
        int resposta = 0, temp = 0, flag = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d",&temp);
            flag += temp;
            if(flag < 0) 
                flag = 0; 
            if(resposta < flag)
                resposta = flag;
        }
        if(resposta <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",resposta);
    }
    return 0;  
}