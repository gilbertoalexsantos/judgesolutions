//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1048

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v;
int n;

int main() {
	while(scanf("%d",&n) != EOF) {
		v.push_back(n);
		for(int i = v.size() - 1; i > 0; i--)
			if(v[i - 1] > v[i]) swap(v[i - 1], v[i]);
		int mid1 = v[v.size() / 2 - 1];
		int mid2 = v[v.size() / 2];
		if(!(v.size() % 2)) printf("%d\n",(mid1 + mid2) / 2);
		else printf("%d\n",mid2);
	}
}
