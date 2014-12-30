//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=270

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef map<char*,int>::iterator IT;
typedef pair<int,int> ii;

const int MAX = 400;
const int MAX_LETTER = 10;

struct cmp { bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

int cases = 1, qt_events, cnt;
map<char*,int,cmp> MAP;
map<int,char*> TOCHAR;
bool dist[MAX][MAX];

void clear() {
	cnt = 0;
	MAP.clear();
	TOCHAR.clear();
	memset(dist,false,sizeof dist);
}

int ins(char *w) {
	IT it = MAP.find(w);
	if(it == MAP.end()) {
		MAP.insert(make_pair(w,cnt++));
		return cnt-1;
	}
	return it->second;
}

void floyd() {
	for(int k = 0; k < cnt; k++)
		for(int i = 0; i < cnt; i++) for(int j = 0; j < cnt; j++)
			dist[i][j] |= (dist[i][k] & dist[k][j]);
}

void solve() {
	int qt_concurrent = 0;
	vector<ii> ans;
	for(int i = 0; i < cnt; i++) for(int j = i+1; j < cnt; j++)
		if(!dist[i][j] && !dist[j][i]) {
			qt_concurrent++;
			ans.push_back(ii(i,j));
		}
	if(qt_concurrent) {
		printf("Case %d, %d concurrent events:\n",cases++,qt_concurrent);
		printf("(%s,%s) ",TOCHAR.find(ans[0].first)->second,TOCHAR.find(ans[0].second)->second);
		if(qt_concurrent > 1)
			printf("(%s,%s) ",TOCHAR.find(ans[1].first)->second,TOCHAR.find(ans[1].second)->second);
		printf("\n");
	} else
		printf("Case %d, no concurrent events.\n",cases++);
}

int main() {
	while(scanf("%d",&qt_events) && qt_events) {
		clear();
		char *word;
		for(int i = 0; i < qt_events; i++) {
			int qt; scanf("%d",&qt);
			vector<int> pb;
			for(int j = 0; j < qt; j++) {
				word = new char[60]; scanf("%s",word);
				int x = ins(word);
				TOCHAR.insert(make_pair(x,word));
				pb.push_back(x);
			}
			for(int j = 0; j < pb.size()-1; j++)
				dist[pb[j]][pb[j+1]] = 1;
		}
		int query; scanf("%d",&query);
		while(query--) {
			char *w1 = new char[60], *w2 = new char[60];
			scanf("%s %s",w1,w2);
			dist[ins(w1)][ins(w2)] = 1;
		}
		floyd();
		solve();
	}
}
