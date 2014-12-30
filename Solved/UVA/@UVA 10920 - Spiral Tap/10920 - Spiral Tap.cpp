// Author:	Gilberto A. dos Santos
// Site	:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1861

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;
int sz, p;

void pr(int x, int y) { printf("Line = %d, column = %d.\n",x,y); }

void upa(pint &n, int quant, int tipo) {
	if(tipo == 1) { n.first += quant; }
	else if(tipo == 2) { n.second -= quant; }
	else if(tipo == 3) { n.first -= quant; }
	else if(tipo == 4) { n.second += quant; }
}

int main() {
	while(scanf("%d %d",&sz, &p) && sz != 0) {
		pint cord;
		cord.first = (sz + 1) / 2;
		cord.second = (sz + 1) / 2;
		int i, t, qt, t1, f;
		t = qt = t1 = f = i = 1;
		int temporizador = 2;
		while(i <= p) {
			if(i == p) break;
			if(!temporizador) {
				temporizador = 2;
				t1++;
			}
			if(i + t1 <= p) {
				upa(cord,t1,t);
				t++;
				i += t1;
			} else {
				upa(cord,p - i,t);
				break;
			}
			if(t > 4) t = 1;
			temporizador--;
		}
		pr(cord.first,cord.second);
	}
	return 0;
}
