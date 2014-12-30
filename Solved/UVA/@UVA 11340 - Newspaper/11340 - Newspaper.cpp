//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2315

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int n, k, m;

int main() {
	scanf("%d",&n);
	while(n--) {
        map<char, int> mapa;
		int total = 0;
		scanf("%d",&k);
		while(k--) {
			char c;
			int custo;
			cin >> c >> custo;
			mapa[c] = custo;
		}
		scanf("%d",&m);
        getchar();
		while(m--) {
			string temp;
			getline(cin,temp);
			for(int j = 0; j < temp.size(); j++) {
				total += mapa[temp[j]];
			}
		}
		int dollar = (total / 100);
		int cent = (total % 100);
		if(cent < 10) cout << dollar << ".0" << cent << "$" << endl;
		else cout << dollar << "." << cent << "$" << endl;
	}
}
