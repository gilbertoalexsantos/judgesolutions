//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2487

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

const int MAX = 2002;
const int MAX_LETTER = 60;
const int INF = 1e9;

struct cmp { bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

int qt_vert, cnt;
int id_source, id_sink;
int source, sink;
map<char*,int,cmp> MAP;
vector<ii> graph[MAX];
vector<iiii> edge;
int dist[MAX];

void clear() {
	cnt = 0;
	MAP.clear(); edge.clear();
	for(int i = 0; i <= qt_vert+1; i++) {
		dist[i] = INF;
		graph[i].clear();
	}
}

int ins(char *w) { 
	map<char*,int>::iterator IT = MAP.find(w);
	if(IT == MAP.end()) {
		MAP.insert(make_pair(w,cnt)); 
		return cnt++;
	}
	return IT->second;
}

inline void pb(int x, int y, int w) { graph[x].push_back(ii(y,w)); }

void createGraph() {
	source = 0, sink = qt_vert+1;
	for(int i = 0; i < edge.size(); i++) {
		int x = edge[i].first.first, y = edge[i].first.second;
		int size = edge[i].second.first, letter = edge[i].second.second;

		if(x == id_source || y == id_source) pb(source,i+1,size);
		if(x == id_sink || y == id_sink) pb(i+1,sink,0);

		for(int j = i+1; j < edge.size(); j++) {
			int nx = edge[j].first.first, ny = edge[j].first.second;
			int nsize = edge[j].second.first, nletter = edge[j].second.second;
			if(letter != nletter && (x == nx || x == ny || y == nx || y == ny)) {
				pb(i+1,j+1,nsize);
				pb(j+1,i+1,size);
			}
		}
	}
}

int dijkstra() {
	priority_queue<ii> pq;
	pq.push(ii(0,source));
	dist[source] = 0;
	while(!pq.empty()) {
		int v = pq.top().second, w = -pq.top().first; pq.pop();
		if(w > dist[v]) continue;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i].first, nw = graph[v][i].second;
			if(dist[nv] > dist[v]+nw) {
				dist[nv] = dist[v]+nw;

				if(nv == sink) return dist[nv];

				pq.push(ii(-dist[nv],nv));
			}
		}
	}
	return -1;
}

int main() {
	char *w1, *w2, *w3;
	while(scanf("%d",&qt_vert) && qt_vert) {
		clear();
		w1 = new char[MAX_LETTER]; w2 = new char[MAX_LETTER];	
		scanf("%s %s",w1,w2);
		id_source = ins(w1); id_sink = ins(w2);

		for(int i = 0; i < qt_vert; i++) {
			w1 = new char[MAX_LETTER]; w2 = new char[MAX_LETTER]; w3 = new char[MAX_LETTER];
			scanf("%s %s %s",w1,w2,w3);
			ii a(ins(w1),ins(w2));
			ii t(strlen(w3),w3[0]-'a');
			edge.push_back(iiii(a,t));
		}

		createGraph();

		int ans = dijkstra();
		ans < 0 ? printf("impossivel\n") : printf("%d\n",ans);
	}
}
