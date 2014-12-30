//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=227

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int QT_VERT = 5;
const int QT_EDGE = 8;

typedef pair<int,bool> ii;

int graph[6][6] = {
	{0,0,0,0,0,0},
	{0,0,1,1,0,1},
	{0,1,0,1,0,1},
	{0,1,1,0,1,1},
	{0,0,0,1,0,1},
	{0,1,1,1,1,0}
};
int edge[6][6] = {0};

void prt(vector<int> a) {
	for(int i = 0; i < a.size(); i++)
	 printf("%d",a[i]);
	printf("\n");
}

void bt(vector<int> ans, int v, int mask = 0) {
	if(mask == QT_EDGE) {
		if(v == 2) {
			ans.push_back(2);
			prt(ans);
		}
		return;
	}
	for(int i = 1; i <= QT_VERT; i++) {
		if(!graph[v][i] || edge[v][i]) continue;
		edge[v][i] = edge[i][v] = true;
		ans.push_back(v);
		bt(ans,i,mask+1);
		ans.pop_back();
		edge[v][i] = edge[i][v] = false;
	}
}

int main() {
	vector<int> ans;
	bt(ans,1); 
}
