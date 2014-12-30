//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2315

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

typedef unordered_map<char, int> cmap;
typedef pair<char, int> pint;
int n, k, m;

int main() {
	scanf("%d",&n);
	while(n--) {
		cmap mapa;
		int total = 0;
		scanf("%d",&k);
		while(k--) {
			pint temp;
			cin >> temp.first >> temp.second;
			mapa.insert(temp);
		}
		scanf("%d",&m);
        getchar();
		while(m--) {
			string temp;
			getline(cin,temp);
			for(int j = 0; j < temp.size(); j++) {
				if(mapa.count(temp[j]) > 0) total += mapa[temp[j]];
			}
		}
		int dollar = (total / 100);
		int cent = (total % 100);
		if(cent < 10) cout << dollar << ".0" << cent << "$" << endl;
		else cout << dollar << "." << cent << "$" << endl;
	}
}

