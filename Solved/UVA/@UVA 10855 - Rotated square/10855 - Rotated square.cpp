//Author: Gilberto A. dos Santos
//Site: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1796

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> small(100000), big(10000000);

int quant() {
	int resp = 0;
	for(int linha = 0; linha <= (n - m); linha++) {
		for(int coluna = 0; coluna <= (n - m); coluna++) {
			int ps = 0;
			bool cat = true;
			if(small[ps++] == big[linha].substr(coluna,m)) {
				for(int n_linha = linha+1; n_linha < (linha+m); n_linha++, ps++) {
					if(small[ps] != big[n_linha].substr(coluna,m)) {
						cat = false;
						break;
					}
				}
				if(cat) resp++;
			}
		}
	}
	return resp;
}

void rotaciona() {
	vector<string> nova(m);
	for(int i = 0; i < m; i++) {
		string temp;
		for(int j = m - 1; j >= 0; j--) temp += small[j][i];
		nova[i] = temp;
	}
	for(int i = 0; i < m; i++) small[i] = nova[i];
}

int main() {
	while(scanf("%d %d",&n, &m) && n != 0) {
		int n1, n2, n3, n4;
		n1 = n2 = n3 = n4 = 0;
		for(int i = 0; i < n; i++) cin >> big[i];
		for(int i = 0; i < m; i++) cin >> small[i];
		n1 = quant();
		rotaciona();
		n2 = quant();
		rotaciona();
		n3 = quant();
		rotaciona();
		n4 = quant();
		printf("%d %d %d %d\n",n1, n2, n3, n4);
	}
}
