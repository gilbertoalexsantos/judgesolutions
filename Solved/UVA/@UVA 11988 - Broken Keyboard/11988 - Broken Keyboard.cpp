/*
 * Gilberto Alexandre dos Santos
 * 
 * Site:
 * http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3139
 * 
 * Solução
 * 
 * Essa foi chatinha =/...
 * 
 * Seguinte...
 * 
 * Eu crio 3 apontadores iniciais: Cabeca, Cauda, Atual, e uma estrutura No, que contém a
 * letra e um apontador para o prox.
 * 
 * Enquanto não há nenhum '[' ou ']', eu vou fazendo a malandragem da lista encadeada, sempre
 * atualizando corretamente a Cabeca, Cauda e Atual...
 * 
 * Quando vem um '[', eu movo o apontador "Atual" para "Cabeca" e continuo a inserção, des-
 * te modo:
 * 
 * ABC[DEF
 * 
 * Passo a passo:
 * 
 * (A) -> (B) -> (C)
 * 
 * Aí vem o '['
 * 
 * (D) -> (A)...
 * (D) -> (E) -> (A)...
 * 
 * E se vem um ']', eu movo o apontador "Atual" para "Cauda", e continuo a malandragem.
 */
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

struct No {
    char letra;
    struct No *prox;
};

string palavra;

int main() {
    while (cin >> palavra) {
        bool entrou = 0;
        No *cabeca, *cauda, *atual;
        cabeca = (No*) malloc(sizeof (No));
        cauda = (No*) malloc(sizeof (No));
        atual = (No*) malloc(sizeof (No));
        cabeca->prox = NULL;
        cauda->prox = NULL;
        atual->prox = NULL;
        for (int i = 0; i < palavra.size(); i++) {
            if (cabeca->prox == NULL) {
                if ((palavra[i] != '[') && (palavra[i] != ']')) {
                    No *temp;
                    temp = (No*) malloc(sizeof (No));
                    temp->letra = palavra[i];
                    temp->prox = NULL;
                    cabeca->prox = temp;
                    cauda->prox = temp;
                    atual->prox = temp;
                    entrou = 0;
                    continue;
                }
            }
            if (palavra[i] == '[') {
                atual->prox = cabeca->prox;
                entrou = 1;
            } else if (palavra[i] == ']') {
                atual->prox = cauda->prox;
                entrou = 0;
            } else if ((entrou)) {
                No *temp;
                temp = (No*) malloc(sizeof (No));
                temp->letra = palavra[i];
                temp->prox = cabeca->prox;
                cabeca->prox = temp;
                atual->prox = temp;
                entrou = 0;
            } else if (atual->prox == cauda->prox) {
                No *temp;
                temp = (No*) malloc(sizeof (No));
                temp->letra = palavra[i];
                atual->prox->prox = temp;
                temp->prox = NULL;
                atual->prox = temp;
                cauda->prox = temp;
            } else {
                No *temp;
                temp = (No*) malloc(sizeof (No));
                temp->letra = palavra[i];
                temp->prox = atual->prox->prox;
                atual->prox->prox = temp;
                atual->prox = temp;
            }
        }
        atual = cabeca->prox;
        while (atual->prox != NULL) {
            No *temp;
            temp = (No*) malloc(sizeof (No));
            printf("%c", atual->letra);
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
        printf("%c", atual->letra);
        printf("\n");
    }
    return 0;
}