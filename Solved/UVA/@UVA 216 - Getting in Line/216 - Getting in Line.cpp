//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=152

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const float INF = 1e9;
const float EPS = 1e-9;

typedef pair<int,int> pint;

inline bool greaterThan(float a, float b) { return (a-b) > EPS; }
inline float calc_dist(pint a, pint b) { return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2)) + 16.0; }

float memo[8][1 << 8];
int path[8][1 << 8];
float dist[8][8];
vector<pint> arr_vert(8);

float dp(int size, int pos, int mask) {
	if(mask == (1 << size)-1) return 0;

	float &ret = memo[pos][mask];
	if(ret == ret) return ret;

	ret = INF;
	float flag;
	for(int i = 0; i < size; i++) {
		if(mask & (1 << i)) continue;
		flag = dp(size,i,mask | 1 << i) + dist[pos][i];
		if(greaterThan(ret,flag)) {
			path[pos][mask] = i;
			ret = flag;
		}
	}

	return ret;
}

int main() {
	int n, cases = 1;
	printf("**********************************************************\n");
	bool first = true;
	while(scanf("%d",&n) && n) {
		first ? first = false : printf("**********************************************************\n");
		memset(memo,-1,sizeof memo);

		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			arr_vert[i] = pint(x,y);
		}
	
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
			dist[i][j] = calc_dist(pint(arr_vert[i].first,arr_vert[i].second),pint(arr_vert[j].first,arr_vert[j].second));
		
		float min_sum = 1e9;
		vector<pint> real_path;
		int beg = 0;
		for(int i = 0; i < n; i++) {
			float ret = dp(n,i,1 << i);
			if(greaterThan(min_sum,ret)) {
				min_sum = ret;	
				beg = i;
				real_path.clear();
				int temp_mask = 1 << beg;
				for(int a = 0, z = beg; a < n-1; a++) {
					real_path.push_back(pint(z,path[z][temp_mask]));
					z = path[z][temp_mask];
					temp_mask |= 1 << z;
				}
			}
			memset(memo,-1,sizeof memo);
		}

		int mask = 1 << beg;
		printf("Network #%d\n",cases++);
		for(int i = 0; i < real_path.size(); i++) {
			int a = real_path[i].first;
			int b = real_path[i].second;
			printf("Cable requirement to connect (%d,%d) to ",arr_vert[a].first,arr_vert[a].second);
			printf("(%d,%d) is %.2lf feet.\n",arr_vert[b].first,arr_vert[b].second,dist[a][b]);
		}
		printf("Number of feet of cable required is %.2lf.\n",min_sum);
	}
}
