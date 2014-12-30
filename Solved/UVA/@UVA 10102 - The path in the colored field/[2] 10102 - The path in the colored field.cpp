//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1043

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pint;

int manhattan_distance(pint a, pint b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int main() {
	int size;
	while(scanf("%d",&size) != EOF) {

		char m[size][size];

		for(int i = 0; i < size; i++) scanf("%s",m[i]);

		vector<pint> number_tree;
		vector<pint> number_one;

		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(m[i][j] == '1') {
					pint t(i,j);
					number_one.push_back(t);
				}
				if(m[i][j] == '3') {
					pint t(i,j);
					number_tree.push_back(t);
				}
			}
		}

		int ans = -1;
		for(int i = 0; i < number_one.size(); i++) {
			int l = 100000000;
			for(int j = 0; j < number_tree.size(); j++) {
				l = min(l,manhattan_distance(number_one[i],number_tree[j]));
			}
			ans = max(ans,l);
		}

		printf("%d\n",ans);
	}
}
