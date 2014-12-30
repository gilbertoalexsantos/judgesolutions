//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2259

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = (ll) 1 << 59;
const int MAX = 51;
const int MAX_STATE = 1 << 13;

int qt_vert, qt_edge, qt_store;

vector<int> arr_store;
ll dist[MAX][MAX];
ll save_store[MAX];
ll memo[13][MAX_STATE];

ll dp(int pos = 0, int mask = 0) {
	if(mask & 1) return 0;

	ll &ret = memo[pos][mask];
	if(ret != -INF) return ret;

	for(int i = 0; i < arr_store.size(); i++) {
		if(mask & (1 << i)) continue;
		int vert = arr_store[i];
		ret = max(ret,dp(i,mask | 1 << i) - dist[arr_store[pos]][vert] + save_store[vert]);
	}

	return ret;
}

void floyd() {
	for(int k = 0; k <= qt_vert; k++) for(int i = 0; i <= qt_vert; i++)
		for(int j = 0; j <= qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

void clear() {
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++)
		dist[i][j] = dist[j][i] = (i == j) ? 0 : INF;
	memset(save_store,-1,sizeof save_store);
	arr_store.clear();
	arr_store.push_back(0);
	save_store[0] = 0;
	for(int i = 0; i < 13; i++) for(int j = 0; j < MAX_STATE; j++)
		memo[i][j] = -INF;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		clear();
		scanf("%d %d",&qt_vert,&qt_edge);
		for(int i = 0; i < qt_edge; i++) {
			int a, b;
			ll c, d;
			scanf("%d %d %lld.%lld",&a,&b,&c,&d);
			dist[a][b] = dist[b][a] = min(dist[a][b],(ll)100*c+d);
		}
		scanf("%d",&qt_store);
		for(int i = 0; i < qt_store; i++) {
			int t; 
			ll c, d;
			scanf("%d %lld.%lld",&t,&c,&d);
			if(save_store[t] != -1) {
				save_store[t] += (ll)100*c+d;
				continue;
			}
			arr_store.push_back(t);
			save_store[t] = (ll)100*c+d;
		}
		floyd();
		ll ans = dp();
		ans > 0 ? printf("Daniel can save $%lld.%02lld\n",ans/100,ans%100) : printf("Don't leave the house\n");
	}
}
