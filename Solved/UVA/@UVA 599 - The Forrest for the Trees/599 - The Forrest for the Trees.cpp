//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=540

#include <iostream>
#include <ios>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

int n;
int parent[26];
int prior[26];
bool visited[26];

int find(int p) {
	if(p == parent[p]) return p;
	else return parent[p] = find(parent[p]);
}

void unite(int a, int b) {
	int ax = find(a);
	int bx = find(b);

	if(ax == bx) return;

	if(prior[ax] > prior[bx]) {
		parent[bx] = ax;
	} else if(prior[ax] < prior[bx]) {
		parent[ax] = bx;
	} else {
		parent[ax] = bx;
		prior[bx]++;
	}
}

void reset() {
	for(int i = 0; i < 26; i++) parent[i] = i;
	memset(prior,0,sizeof prior);
	memset(visited,0,sizeof visited);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--) {
		reset();
		int tree = 0;
		int acorn = 0;
		string word;
		while(cin >> word && word[0] != '*') {
			int a = word[1] - 65;
			int b = word[3] - 65;
			unite(a,b);
		}
		cin >> word;
		for(int i = 0; i < word.size(); i += 2) {
			int a = word[i] - 65;	
			int ax = find(a);
			if(prior[ax] && !visited[ax]) {
				tree++;
				visited[ax] = true;
			} else if(!prior[ax]) acorn++;
		}
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
	}
}
