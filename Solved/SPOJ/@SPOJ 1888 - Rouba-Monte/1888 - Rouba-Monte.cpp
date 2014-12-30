//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.pl/problems/ROUBA/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <list>
using namespace std;

struct Monte {
    short topo;
    int tamanho;
};

int main() {
    short N = 0, J = 0;
    while (scanf("%hd %hd", &N, &J) && N != 0) {
        Monte montes[J];
        //Inicializando os montes
        for (short i = 0; i < J; i++) {
            montes[i].topo = 0;
            montes[i].tamanho = 0;
        }
        short pilha_compras;
        list<short> descarte;
        //Identificar a vez do jogador
        short jogador = 1;
        //Flag para ajudar nas operações
        bool achou = false;
        //Identificar o maior monte
        int maior = 0;
        for (short i = 0; i < N; i++) {
            scanf("%hd", &pilha_compras);

            /*
             * A 1° carta da pilha sempre vai para descarte
             */
            if (i == 0) {
                descarte.push_back(pilha_compras);
                continue;
            }


            /*
             * Verificando se algum monte de outro jogador possui a carta
             * da pilha. Detalhe que ele não pega o monte do própio jogador(ainda)
             */
            for (short j = 0; j < J; j++) {
                if ((pilha_compras == montes[j].topo) && (j != jogador)) {
                    montes[jogador].topo = pilha_compras;
                    montes[jogador].tamanho += montes[j].tamanho + 1;
                    montes[j].topo = 0;
                    montes[j].tamanho = 0;
                    achou = true;
                    break;
                }
            }

            /*
             * Se nenhum monte de jogador possui o topo igual a pilha de compra,
             * então ele verfica na área de descarte
             */
            if (!achou) {
                for (list<short>::iterator it = descarte.begin(); it != descarte.end(); it++) {
                    if (*it == pilha_compras) {
                        montes[jogador].topo = pilha_compras;
                        montes[jogador].tamanho += 2;
                        descarte.remove(montes[jogador].topo);
                        achou = true;
                        break;
                    }
                }
            }

            /*
             * Se nenhum monte possui o topo igual a pilha de compra e também
             * não está na área de descarte, então olha se o topo do monte 
             * do própio jogador é igual a carta da pilha de compra
             */
            if (!achou) {
                if (pilha_compras == montes[jogador].topo) {
                    montes[jogador].tamanho++;
                    achou = true;
                }
            }

            /*
             * Se não entrou em nenhum caso, então passa para o próximo jogador
             */
            if (!achou) {
                descarte.push_back(pilha_compras);
                jogador++;
                if (jogador == J)
                    jogador = 0;
            }

            (montes[jogador].tamanho > maior) ? maior = montes[jogador].tamanho : false;
            achou = false;
        }

        printf("%d ", maior);
        for (short i = 0; i < J; i++) {
            if (montes[i].tamanho == maior)
                ((i + 1) == J) ? printf("%hd", (i + 1)) : printf("%hd ", (i + 1));
        }
        printf("\n");
    }
    return 0;
}