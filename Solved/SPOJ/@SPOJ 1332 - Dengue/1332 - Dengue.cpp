//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/DENGUE/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<list>
using namespace std;

/*
 * Irá armazenar a distância máx no 1° e o vértice extremo no 2°
 */
pair<short, short> temp;

void dfc1(list<short> grafo[], short vertice, bool marcado[], short &tamanho) {
    marcado[vertice] = 1;
    for (list<short>::iterator it = grafo[vertice].begin(); it != grafo[vertice].end(); it++) {
        if (!marcado[*it]) {
            tamanho++;
            dfc1(grafo, *it, marcado, tamanho);
        }
    }
    if (temp.first < tamanho) {
        temp.first = tamanho;
        temp.second = vertice;
    }
    (tamanho != 0) ? tamanho-- : false;
}

void dfc2(list<short> grafo[], short vertice, bool marcado[], bool caminho[], short distancia, short &tamanho, int N) {
    marcado[vertice] = 1;
    caminho[vertice] = 1;
    for (list<short>::iterator it = grafo[vertice].begin(); it != grafo[vertice].end(); it++) {
        if (!marcado[*it]) {
            tamanho++;
            dfc2(grafo, *it, marcado, caminho, temp.first, tamanho, N);
        }
    }
    if (tamanho < distancia) {
        caminho[vertice] = 0;
        tamanho--;
    } else {
        for (short i = 0; i < N + 1; i++)
            marcado[i] = 1;
    }
}

void dfc3(list<short> grafo[], short vertice, bool caminho[], short raio, short &tamanho, short &retorno, bool marcado[]) {
    marcado[vertice] = 1;
    for (list<short>::iterator it = grafo[vertice].begin(); it != grafo[vertice].end(); it++) {
        if (caminho[*it] && !marcado[*it]) {
            tamanho++;
            if (tamanho == raio) {
                retorno = *it;
                break;
            } else {
                dfc3(grafo, *it, caminho, raio, tamanho, retorno, marcado);
            }
        }
    }
}

list<short> grafo[200];

int main() {
    short N = 0, resposta = 0;
    while (scanf("%hd", &N) && N != 0) {
        for(int i = 0; i <= N; i++)
          grafo[i].clear();

        for (short i = 0; i < N - 1; i++) {
            short X = 0, Y = 0;
            scanf("%hd %hd", &X, &Y);
            grafo[X].push_back(Y);
            grafo[Y].push_back(X);
        }

        if ((N == 1) || (N == 2)) {
            printf("Teste %hd\n%d\n\n", ++resposta, 1);
            continue;
        }

        /*
         * Estrutura para saber se o vértice está marcado, para auxiliar a DFC
         */
        bool marcado[N + 1];

        /*
         * Peguei algum vértice extremo 
         */
        for (short i = 0; i < N + 1; i++)
            marcado[i] = 0;
        short tamanho = 0;
        temp.first = 0;
        temp.second = 0;
        dfc1(grafo, 1, marcado, tamanho);
        /*
         * A partir do vértice extremo, calculei o diâmetro
         */
        tamanho = 0;
        temp.first = 0;
        for (short i = 0; i < N + 1; i++)
            marcado[i] = 0;
        dfc1(grafo, temp.second, marcado, tamanho);

        /*
         * Descobrir o caminho
         */
        tamanho = 0;
        bool caminho[N + 1];
        for (short i = 0; i < N + 1; i++) {
            marcado[i] = 0;
            caminho[i] = 0;
        }
        short vertice = temp.second;
        short raio = temp.first / 2;
        dfc2(grafo, temp.second, marcado, caminho, temp.first, tamanho, N);

        /*
         * Agora só aplicar outra DFS até o meio
         */
        tamanho = 0;
        short retorno = 0;
        for (short i = 0; i < N + 1; i++)
            marcado[i] = 0;
        dfc3(grafo, vertice, caminho, raio, tamanho, retorno, marcado);
        printf("Teste %hd\n%hd\n\n", ++resposta, retorno);
    }
    return 0;
}
