//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3644

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ios>
#include <vector>
#include <queue>
#include <string>
using namespace std;

priority_queue<pair<int,int> > pq;
vector<pair<int, int> > v;

int main() {
	ios::sync_with_stdio(false);
	string word;
	while(cin >> word && word != "#") {
		pair<int, int> p;
		cin >> p.second >> p.first;
		v.push_back(p);
	}
	int k;
	cin >> k;
	
	for(int i = 0; i < v.size(); i++) {
		int period = 0;
		for(int j = 0; j < k; j++) {
			period += v[i].first;

			pair<int, int> temp;
			temp.first = -period;
			temp.second = -v[i].second;

			pq.push(temp);
		}
	}

	while(k--) {
		cout << -pq.top().second << endl;
		pq.pop();
	}
}
