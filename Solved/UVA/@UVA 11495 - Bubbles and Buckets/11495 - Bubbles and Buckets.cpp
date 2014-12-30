//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2490

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int passos = 0;
int array[100000];

void merge(int vetor[], int inicio, int meio, int fim) {
    int temp_vetor[fim - inicio + 1];
    int esq = inicio;
    int dir = meio + 1;
    int contador = 0;
    int var_passos = 0;
    while ((esq <= meio) && (dir <= fim)) {
        if (vetor[esq] <= vetor[dir]) temp_vetor[contador++] = vetor[esq++];
        else {
            passos += dir - esq - var_passos;
            var_passos++;
            temp_vetor[contador++] = vetor[dir++];
        }
    }
    while (esq <= meio) temp_vetor[contador++] = vetor[esq++];
    while (dir <= fim) temp_vetor[contador++] = vetor[dir++];
    esq = inicio;
    contador = 0;
    while (esq <= fim) vetor[esq++] = temp_vetor[contador++];
}

void mergeSort(int vetor[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (fim + inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, (meio + 1), fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        passos = 0;
        mergeSort(array, 0, n - 1);
        if ((passos % 2) == 0) {
            cout << "Carlos\n";
        } else {
            cout << "Marcelo\n";
        }
    }
    return 0;
}