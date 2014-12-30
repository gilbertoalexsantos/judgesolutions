//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1448

#include <iostream>
#include <ios>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

bool active[26];
bool visited[26];
int cont[26];
int n, m;

void clear() {
	memset(visited,0,sizeof visited);
	memset(active,0,sizeof active);
	memset(cont,0,sizeof cont);
}

int main() {
	ios::sync_with_stdio(false);
	while(cin >> n) {
		clear();
		queue<int> q;
		vector<int> graph[26];
		string word;
		cin >> m >> word;

		if(n > 3 && m == 0) {
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
			continue;
		} else if(n <= 3 && m == 0) {
			cout << "WAKE UP IN, 0, YEARS" << endl;
			continue;
		}

		for(int i = 0; i < word.size(); i++) active[word[i] - 65] = true;
		while(m--) {
			cin >> word;
			int a = word[0] - 65;
			int b = word[1] - 65;
			graph[a].push_back(b);
			graph[b].push_back(a);
			if(!visited[a] && !active[a]) {
				q.push(a);
				visited[a] = true;
			}
			if(!visited[b] && !active[b]) {
				q.push(b);
				visited[b] = true;
			}
		}
		int ans = 0;
		int cnt = 3;
		while(true) {
			int size = q.size();
			int n_size = 0;
			vector<int> to_active;
			for(int i = 0; i < size; i++) {
				int vertice = q.front();
				q.pop();
				for(int j = 0; j < graph[vertice].size(); j++) 
					if(active[graph[vertice][j]]) cont[vertice]++;
				if(cont[vertice] < 3) {
					q.push(vertice);
					n_size++;
					cont[vertice] = 0;
				} else {
					to_active.push_back(vertice);
					cnt++;
				}
			}
			for(int z = 0; z < to_active.size(); z++) active[to_active[z]] = true;
			ans++;
			if(cnt == n) break;
			if(n_size == size) {
				ans = -1;
				break;
			}
		}
		if(ans == -1) cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
	}
}
