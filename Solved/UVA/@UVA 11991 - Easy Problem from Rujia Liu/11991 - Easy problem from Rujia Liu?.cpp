//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3142

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pint;
int n, m;

int bb(vector<pint> &v, int value) {
	int esq = 0;
	int dir = v.size() - 1;
	while(esq <= dir) {
		int mid = (esq + dir) / 2;
		if(value == v[mid].first) return mid;
		else if(value < v[mid].first) dir = mid-1;
		else esq = mid+1;
	}
	return -1;
}

int ans(vector<pint> &v, int pos, int k, int value) {
	pos += k-1;
	if(pos >= v.size()) return -1;
	if(v[pos].first == value) return v[pos].second;
	else return -1;
}

int main() {
	while(scanf("%d %d",&n, &m) != EOF) {
		vector<pint> v;
		for(int i = 1; i <= n; i++) {
			pint temp;
			scanf("%d",&temp.first);
			temp.second = i;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		while(m--) {
			int k, number;
			scanf("%d %d",&k, &number);
			int pos = bb(v,number);
			if(pos == -1) cout << "0\n";
			else {
				while(v[pos].first == number) pos--;
				pos++;
				int f = ans(v,pos,k,number);
				if(f == -1) cout << "0\n";
				else cout << f << endl;
			}
		}
	}
}
