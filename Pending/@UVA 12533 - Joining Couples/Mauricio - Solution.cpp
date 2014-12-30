#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int pos_cycle[100001];
int cod_comp[100001];
bool in_cycle[100001];

int cycle_size[100001];
int first_cycle[100001];
int pd[100001][17];

int level[100001];
vector<int> edges[100001];

void dfs(int v, int v_pai) {
	for(int i = 0; i < edges[v].size(); i++) {
		int w = edges[v][i];
		if(pos_cycle[w] == -1) {
			pd[w][0] = v_pai;
			level[w] = level[v_pai]+1;
			pos_cycle[w] = pos_cycle[v];
			cod_comp[w] = cod_comp[v];
			dfs(w, w);
		}
	}
}

int main() {
	int f[100001];
	int visited[100001];

	int n, q;
	while(scanf("%d", &n) != EOF) {
		memset(pos_cycle, -1, sizeof pos_cycle);
		memset(in_cycle, 0, sizeof in_cycle);
		memset(visited, 0, sizeof visited);

		for(int i = 1; i <= n; i++)
			edges[i].clear();

		for(int i = 1; i <= n; i++) {
			scanf("%d", &f[i]);
			edges[f[i]].push_back(i);
		}

		memset(pd, 0, sizeof pd);

		int cnt_comp = 0;
		for(int i = 1; i <= n; i++) {
			if(pos_cycle[i] != -1) continue;

			int cycle_start = i;
			while(!visited[cycle_start]) {
				visited[cycle_start] = true;
				cycle_start = f[cycle_start];
			}

			int cur = cycle_start, cnt = 0;
			do {
				pos_cycle[cur] = cnt++;
				cod_comp[cur] = cnt_comp;
				in_cycle[cur] = true;
				cur = f[cur];
			} while(cur != cycle_start);

			pd[cycle_start][0] = cycle_start;
			cycle_size[cnt_comp] = cnt;
			first_cycle[cnt_comp++] = cycle_start;
			level[cycle_start] = 0;

			do {
				dfs(cur, cycle_start);
				cur = f[cur];
			} while(cur != cycle_start);
		}

		for(int j = 1; (1<<j) <= n; j++)
			for(int i = 1; i <= n; i++)
				pd[i][j] = pd[pd[i][j-1]][j-1];

		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			int v, w;
			scanf("%d %d", &v, &w);
			if(cod_comp[v] != cod_comp[w]) { printf("-1\n"); continue; }

			int diff_cycle = pos_cycle[v] - pos_cycle[w];
			if(diff_cycle < 0) diff_cycle *= -1;
			if(cycle_size[cod_comp[v]] - diff_cycle < diff_cycle) 
				diff_cycle = cycle_size[cod_comp[v]] - diff_cycle;

			if(in_cycle[v]) v = first_cycle[cod_comp[v]]; 
			if(in_cycle[w]) w = first_cycle[cod_comp[w]];

			if(level[v] < level[w]) swap(v, w);
			int vo = v, wo = w;

			int a = level[v] - level[w];
			while(a > 0) {
				v = pd[v][__builtin_ctz(a)];
				a &= a-1;
			}

			if(v == w)
				printf("%d\n", level[vo] - level[v] + diff_cycle);
			else {
				for(int j = 16; j >= 0; j--)
					if(pd[v][j] != pd[w][j]) {
						v = pd[v][j];
						w = pd[w][j];
					}

				printf("%d\n", level[vo] - level[v] + 
						level[wo] - level[w] + 2 + diff_cycle);
			}
		}
	}
}
