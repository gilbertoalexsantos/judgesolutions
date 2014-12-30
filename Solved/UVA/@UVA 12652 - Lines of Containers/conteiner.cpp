//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4381 	
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 301

struct d {
	int n;
	int po;
};

int l, c;
d linha[MAX], coluna[MAX];
int matriz[MAX][MAX];
int resp;

void ordena(d v[], int max) {
	for(int i = 0; i <= max; i++) {
		int maior = -1;
		int in = -1;
		int pos = -1;
		for(int j = 0; j <= max - i; j++) {
			if(maior < v[j].n) {
				maior = v[j].n;
				in = v[j].po;
				pos = j;
			}
		}
		if(pos != max - i) {
			resp++;
			d temp = v[max - i];
			v[max - i].n = maior;
			v[max - i].po = in;
			v[pos].n = temp.n;
			v[pos].po = temp.po;
		}
	}
}

bool f() {
	int min = matriz[linha[0].po][coluna[0].po];
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < c; j++) {
			if( (min > matriz[linha[i].po][coluna[j].po]) || (min > (i + 1) * c) ) {
				return 0;
			} else min = matriz[linha[i].po][coluna[j].po];
		}
	}
	return 1;
}

int main() {
	while (scanf("%d %d",&l,&c) != EOF) { 
		resp = 0;
		for(int i = 0; i < l; i++) {
			for(int j = 0; j < c; j++) {
				int temp;
				scanf("%d",&temp);
				matriz[i][j] = temp;
				if(i == 0) {
					coluna[j].n = temp;
					coluna[j].po = j;
				}
				if(j == 0) {
					linha[i].n = temp;
					linha[i].po = i;
				}
			}
		}
		ordena(linha,l - 1);
		ordena(coluna,c - 1);
		if(f()) printf("%d\n",resp);
		else printf("*\n");
	}	
}
