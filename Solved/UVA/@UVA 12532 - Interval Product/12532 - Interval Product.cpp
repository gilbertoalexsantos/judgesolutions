//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3977&mosmsg=Submission+received+with+ID+12988431

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Bit {
private:
    int maxVal;
    vector<int> vetor;
public:

    Bit(int tamanho) {
        maxVal = tamanho;
        vetor.reserve(tamanho);
    }

    ~Bit() {

    }

    int getSoma(int posicao) {
        int soma = 0;
        while (posicao) {
            soma += vetor[posicao];
            posicao -= (posicao & -posicao);
        }
        return soma;
    }

    bool atualiza(int posicao, int valor) {
        while (posicao <= maxVal) {
            vetor[posicao] += valor;
            posicao += (posicao & -posicao);
        }
        return true;
    }

    bool multConst(int constante) {
        for (int i = 1; i <= maxVal; i++)
            vetor[i] = vetor[i] * constante;
        return true;
    }

    bool zera() {
        for (int i = 0; i <= maxVal; i++)
            vetor[i] = 0;
        return true;
    }
};

int numero_elementos, numero_rounds, n1, n2, numero;
char tipo;

int vetor[100000 + 1];
Bit quant_menos(100000 + 1);
Bit quant_zero(100000 + 1);

int main() {
    while (scanf("%d %d", &numero_elementos, &numero_rounds) != EOF) {
        quant_menos.zera();
        quant_zero.zera();
        string resposta;
        for (int i = 1; i <= numero_elementos; i++) {
            scanf("%d", &numero);
            if (numero < 0) quant_menos.atualiza(i, 1);
            else if (numero == 0) quant_zero.atualiza(i, 1);
            vetor[i] = numero;
        }
        for (int i = 0; i < numero_rounds; i++) {
            scanf("%s %d %d", &tipo, &n1, &n2);
            if (tipo == 'C') {
                if (n2 < 0) {
                    if (vetor[n1] >= 0) quant_menos.atualiza(n1, 1);
                    if (vetor[n1] == 0) quant_zero.atualiza(n1, -1);
                } else if (n2 == 0) {
                    if (vetor[n1] != 0) quant_zero.atualiza(n1, 1);
                    if (vetor[n1] < 0) quant_menos.atualiza(n1, -1);
                } else {
                    if (vetor[n1] == 0) quant_zero.atualiza(n1, -1);
                    if (vetor[n1] < 0) quant_menos.atualiza(n1, -1);
                }
                vetor[n1] = n2;
            } else {
                int numero_zeros = quant_zero.getSoma(n2) - quant_zero.getSoma(n1 - 1);
                int numero_negativos = quant_menos.getSoma(n2) - quant_menos.getSoma(n1 - 1);
                if (numero_zeros > 0) resposta += '0';
                else if (numero_negativos & 1) resposta += '-';
                else resposta += '+';
            }
        }
        cout << resposta;
        printf("\n");
    }
    return 0;
}
