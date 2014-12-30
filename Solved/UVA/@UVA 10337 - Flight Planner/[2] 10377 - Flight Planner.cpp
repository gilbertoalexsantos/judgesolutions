//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1278

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int CLIMB = 60, HOLD = 30, SINK = 20;

int state[3] = {CLIMB, HOLD, SINK};
int wind[10][10];

inline int calc_w(int wind) { return wind < 0 ? +wind : -wind; }

vector<vector<int> > graph(30000);
int dist[30000][30000];

void clear() {
	for(int i = 0; i < 3000; i++) graph[i].clear();
}

void mount_graph(int n, int sum = 100, int pos = 0, int alt = 0) {
	if(sum > n) return;

	const int v = wind[alt][sum/100];
	int n_pos = (pos*3) + 1;
	int pclimb = n_pos+1, phold = n_pos+2, psink = n_pos+3;

	//CLIMB
	if(alt != 9) {
		graph.push_back(pclimb);
		dist[pos][pclimb] = CLIMB + v;
		mount_graph(n,sum+100,pclimb,alt+1);
	}

	//HOLD
	graph.push_back(phold);
	dist[pos][phold] = HOLD + v;
	mount_graph(n,sum+100,phold,alt);

	//SINK
	if(alt != 0) {
		graph.push_back(psink);
		dist[pos][psink] = SINK + v;
		mount_graph(n,sum+100,psink,alt-1);
	}
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		clear();
		int n;
		scanf("%d",&n);
		for(int i = 9; i >= 0; i--) for(int j = 0; j <= 9; j++) scanf("%d",&wind[i][j]);	
		mount_graph(n);
	}
}
