//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1836

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int l, c;

int main() {
	while(scanf("%d %d",&l, &c) != EOF) {
		int m[max(l,c)+1][max(l,c)+1];
		memset(m,0,sizeof m);
		for(int i = 1; i <= l; i++) {
			int qt;
			scanf("%d",&qt);

			if(!qt) {
				cin.ignore();
				continue;
			}

			int arr[qt];
			for(int j = 0; j < qt; j++) scanf("%d",&arr[j]);
			for(int j = 0; j < qt; j++) scanf("%d",&m[i][arr[j]]);
		}
		printf("%d %d\n",c,l);
		for(int i = 1; i <= c; i++) {
			vector<int> number;
			vector<int> pos;
			for(int j = 1; j <= l; j++) 
				if(m[j][i]) {
					number.push_back(m[j][i]);
					pos.push_back(j);
				}
			if(number.empty()) printf("0\n\n");
			else {
				printf("%lu",number.size());
				for(int j = 0; j < pos.size(); j++) printf(" %d",pos[j]);
				printf("\n%d",number[0]);
				for(int j = 1; j < number.size(); j++) printf(" %d",number[j]);
				printf("\n");
			}
		}
	}
}
