//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/CPCARROS/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

struct numeroPlaca {
    int l; //Corresponde a transformação das letras em decimal
    int n; //Corresponde aos números finais da placa
};

/*
 * Retorna:
 * TRUE - Placa NOVA (5 Letras, 2 Números)
 * FALSE - Placa VELHA (3 Letras, 4 Números)
 */
bool getTipo(char placa[]) {
    return (isalpha(placa[3]) && isalpha(placa[4]));
}

bool eLetraFalse(char letra) {
    char letras[] = {'A', 'C', 'M', 'I', 'P'};
    for (short i = 0; i < 5; i++) {
        if (letra == letras[i])
            return true;
    }
    return false;
}

/*
 * Verifica se a placa da ISA é uma placa válida
 */
bool eValida(char placa[]) {

    /*
     * Se a 4° for letra e o 5° não for
     */
    if (isalpha(placa[3]) && !isalpha(placa[4]))
        return false;

    /*
     * Se o 4° não for letra e o 5° for
     */
    if (!isalpha(placa[3]) && isalpha(placa[4]))
        return false;

    /*
     * Se o 4° e o 5° forem letras, então a placa é 
     * NOVA, logo não pode conter os caracteres "ACMIP",
     * se contiver, retorna false
     */
    if (isalpha(placa[3]) && isalpha(placa[4])) {
        for (short i = 0; i < 5; i++)
            if (eLetraFalse(placa[i]))
                return false;
    }

    /*
     * Se algum dos três primeiros não forem letras, retor-
     * na false
     */
    if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2]))
        return false;

    /*
     * Se o 6° ou o 7° não forem dígitos, retorna false
     */
    if (!isdigit(placa[5]) || !isdigit(placa[6]))
        return false;

    /*
     * Verifica se tem alguma letra minúscula, teoricamente não
     * precisa disso, mas como sempre estava levando WA, colo-
     * quei para prevenir
     */
    for (short i = 0; i < 3; i++)
        if (placa[i] < 'A' || placa[i] > 'Z')
            return false;
    if (isalpha(placa[3]))
        if (placa[3] < 'A' || placa[3] > 'Z')
            return false;
    if (isalpha(placa[4]))
        if (placa[4] < 'A' || placa[4] > 'Z')
            return false;
    return true;
}

/*
 * Tipo:
 * TRUE - PLACA NOVA
 * FALSE - PLACA VELHA
 * 
 * Irá retornar a posição da letra no alfabeto. Se a placa for
 * nova, a posição será diferente pois as placas NOVAS não con-
 * tém as letras "ACMIP"
 */
int getNumber(char letra, bool tipo) {
    char velha[] = {'$', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char nova[] = {'$', 'B', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'N', 'O', 'Q',
        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    if (tipo) {
        for (short i = 1; i < 22; i++)
            if (letra == nova[i])
                return i;
    } else {
        for (short i = 1; i < 27; i++)
            if (letra == velha[i])
                return i;
    }
    return -1;
}

/*
 * Tipo:
 * TRUE - PLACA NOVA
 * FALSE - PLACA VELHA
 * 
 * Transforma a parte ALFABÉTICA da placa em decimal com base:
 * 26 - Placa VELHA
 * 21 - Placa NOVA
 * 
 * Depois retorna um tipo struct numeroPlaca, que contém duas 
 * variáveis, uma contendo a parte ALFABÉTICA transformada em 
 * decimal, e a outra é a parte numérica
 */
numeroPlaca getNumeroPlaca(char placa[], bool tipo) {
    numeroPlaca resp;
    if (tipo) {
        /*
         * Como a placa é NOVA:
         * Os inteiros 0,1,2,3,4 equivalem a parte ALFABÉTICA
         * Os inteiros 5,6 equivalem a parte NUMÉRICA
         */
        int parte_alfabetica = 0;
        short contador = 0;
        for (short i = 4; i >= 0; i--, contador++)
            parte_alfabetica += getNumber(placa[i], tipo) * (pow(21, contador));
        char temp[3];
        temp[0] = placa[5];
        temp[1] = placa[6];
        resp.l = parte_alfabetica;
        resp.n = atoi(temp);
    } else {
        /*
         * Como a placa é VELHA:
         * Os inteiros 0,1,2 equivalem a parte ALFABÉTICA
         * Os inteiros 3,4,5,6 equivalem a parte NUMÉRICA
         */
        int parte_alfabetica = 0;
        short contador = 0;
        for (short i = 2; i >= 0; i--, contador++)
            parte_alfabetica += getNumber(placa[i], tipo) * (pow(26, contador));
        char temp[5];
        temp[0] = placa[3];
        temp[1] = placa[4];
        temp[2] = placa[5];
        temp[3] = placa[6];
        resp.l = parte_alfabetica;
        resp.n = atoi(temp);
    }
    return resp;
}

/*
 * Usada para comparar as duas placas
 */
char comparacao(numeroPlaca m, numeroPlaca i) {
    if (i.l < m.l)
        return 'Y';
    else if (i.l == m.l)
        if (i.n <= m.n)
            return 'Y';
        else
            return 'N';
    else
        return 'N';
}

/*
 * Quando as duas placas são válidas, é usada a seguinte lógica:
 * 
 * OBS:
 * Usaremos a denotação L para a parte alfabética transformada em
 * decimal e N para a parte numérica.
 * 
 * Se ambas as placas forem do mesmo tipo:
 * 
 * 1° - Cria variável X contendo L e N da 1° placa e variável
 * Y contendo L e N da segunda placa.
 * 
 * 2° - Transforma o número de confidência. Se
 * a placa for velha, faz a seguinte conta:
 * Parte Alfabética = Confidencia / 10000
 * Parte Numérica = Confidencia % 10000
 * Se for nova:
 * Parte Alfabética = Confidencia / 100
 * Parte Numérica = Confidencia % 100
 * Depois soma a parte alfabética ao X.L e a parte numérica ao
 * X.N. Fazendo essa soma, nós obteríamos o número máximo que 
 * a placa de Isa pode atingir.
 * 
 * 3° - Faz a seguinte comparação:
 * Se X.L < I.L, então é porque a placa de ISA não atingiu o
 * máximo, logo ela é válida
 * 
 * Se X.L > I.L, então é porque a placa de ISA passou do máxi-
 * mo, logo não é valida
 * 
 * Se X.L = I.L, devemos comparar a parte numérica, ou seja:
 *   Se X.N <= I.N, é porque a placa de ISA ou é menor ou é igual
 *   ao máximo que pode atingir, logo é válida
 * 
 * 
 * Se a placa de M for do tipo velha e a placa de I for nova:
 * 
 * Pega o número de confidência e transforma a placa de M até
 * ZZZ9999 + 1, depois o que sobrar da confidência, será 
 * transformado em uma placa NOVA, depois faz a comparação das 
 * placas
 */
char retorno(char M[], char I[], int confidencia) {
    /*
     * Placa da Isa não é Válida
     */
    if (!eValida(I))
        return 'N';

    numeroPlaca m = getNumeroPlaca(M, getTipo(M));
    numeroPlaca i = getNumeroPlaca(I, getTipo(I));
    bool tipo_m = getTipo(M), tipo_i = getTipo(I);

    /*
     * Se a placa M for tipo NOVA e a I for tipo VELHA,
     * retorna false
     */
    if (tipo_m && !tipo_i)
        return 'N';

    /*
     * Se tiveram placas iguais
     * (Ou seja, mesmo número decimal e mesmo tipo)
     */
    if (((m.l) == (i.l)) && ((m.n) == (i.n)) && (tipo_m == tipo_i))
        return 'N';

    /*
     * Se a placa de M for mais nova que a de I
     */
    if (tipo_m == tipo_i) {
        if (m.l > i.l)
            return 'N';
        else if (m.l == i.l)
            if (m.n >= i.n)
                return 'N';
    }
    
    /*
     * As duas placas são NOVAS
     */
    if (tipo_m && tipo_i) {
        if (m.n + confidencia >= 100) {
            int passou = (confidencia + m.n) / 100;
            int sobrou = (confidencia + m.n) % 100;
            m.l += passou;
            m.n = sobrou;
        } else {
            m.n += confidencia;
        }
        return comparacao(m, i);
    }

    /*
     * As duas placas são VELHAS
     */
    if (!tipo_m && !tipo_i) {
        if (m.n + confidencia >= 10000) {
            int passou = (confidencia + m.n) / 10000;
            int sobrou = (confidencia + m.n) % 10000;
            m.l += passou;
            m.n = sobrou;
        } else {
            m.n += confidencia;
        }
        return comparacao(m, i);
    }
    
    /*
     * A placa de M é tipo VELHA e a de I é tipo NOVA
     */
    if (!tipo_m && tipo_i) {
        int passa = (confidencia + m.n) / 10000;
        char placa_max[] = "ZZZ9999";
        numeroPlaca number_max = getNumeroPlaca(placa_max, false);
        if ((m.l + passa) <= number_max.l)
            return 'N';
        else {
            int falta = (number_max.l - m.l) * 10000;
            int nova_confidencia = confidencia - (10000 - m.n);
            nova_confidencia -= falta;
            numeroPlaca nova_m;
            char placa_inicial[] = "BBBBB00";
            numeroPlaca zzz = getNumeroPlaca(placa_inicial, true);
            nova_m.l = zzz.l + nova_confidencia / 100;
            nova_m.n = zzz.n + nova_confidencia % 100;
            return comparacao(nova_m, i);
        }
    }
}

int main() {
    char SM[10], SI[10];
    int c;
    while (scanf("%s %s %d", SM, SI, &c) && (SM[0] != '*')) {
        printf("%c\n", retorno(SM, SI, c));
    }
    return 0;
}