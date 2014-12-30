#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <list>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef queue<ll> fila;
typedef stack<ll> pilha;

#define INF 10000000000000000LL
#define ler(x) scanf("%lld",&x);
#define imp(x) printf("%lld",x);
#define FOR(n) for(ll i=0;i<n;++i)
#define PI 2*acos(0.0)
#define rep while(1);
#define repn(n) while(n--)
#define carac 280
#define m 4

double dp[carac][m][m][m][m];
bool marc[carac][m][m][m][m];

map<char, pair<int,int > > posicao;
map<char, int > numap;

char pal[300];
string s;
int len;

inline double dist(int x1,int y1,int x2,int y2)
{
	return (double)(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))/30);
}

inline double time(int ps,int ex,int ey,int dx,int dy)
{
	if(!marc[ps][ex][ey][dx][dy])
	{
		if(ps == s.size())
		{

			return 0;
		}
		else
		{
			double ret = 100000000;
			double press = 0.20 * numap[s[ps]];
			
			ret = min(ret, time(ps+1,posicao[s[ps]].first,posicao[s[ps]].second,dx,dy) +
			 		  dist(posicao[s[ps]].first,posicao[s[ps]].second,ex,ey) + press );


			ret = min(ret, time(ps+1,ex,ey,posicao[s[ps]].first,posicao[s[ps]].second) +
				      dist(posicao[s[ps]].first,posicao[s[ps]].second,dx,dy) + press );
			
			
			dp[ps][ex][ey][dx][dy] = dp[ps][dx][dy][ex][ey] = ret;
			marc[ps][ex][ey][dx][dy] = marc[ps][dx][dy][ex][ey] = true; 
		}
	}
	return dp[ps][ex][ey][dx][dy];
}

int main()
{

	posicao['a'] = make_pair(0,1); numap['a'] = 1;
	posicao['b'] = make_pair(0,1); numap['b'] = 2;
	posicao['c'] = make_pair(0,1); numap['c'] = 3;
	posicao['d'] = make_pair(0,2); numap['d'] = 1;
	posicao['e'] = make_pair(0,2); numap['e'] = 2;
	posicao['f'] = make_pair(0,2); numap['f'] = 3;
	
	posicao['g'] = make_pair(1,0); numap['g'] = 1;
	posicao['h'] = make_pair(1,0); numap['h'] = 2;
	posicao['i'] = make_pair(1,0); numap['i'] = 3;
	posicao['j'] = make_pair(1,1); numap['j'] = 1;
	posicao['k'] = make_pair(1,1); numap['k'] = 2;
	posicao['l'] = make_pair(1,1); numap['l'] = 3;
	posicao['m'] = make_pair(1,2); numap['m'] = 1;
	posicao['n'] = make_pair(1,2); numap['n'] = 2;
	posicao['o'] = make_pair(1,2); numap['o'] = 3;

	posicao['p'] = make_pair(2,0); numap['p'] = 1;
	posicao['q'] = make_pair(2,0); numap['q'] = 2;
	posicao['r'] = make_pair(2,0); numap['r'] = 3;
	posicao['s'] = make_pair(2,0); numap['s'] = 4;
	posicao['t'] = make_pair(2,1); numap['t'] = 1;
	posicao['u'] = make_pair(2,1); numap['u'] = 2;
	posicao['v'] = make_pair(2,1); numap['v'] = 3;
	posicao['w'] = make_pair(2,2); numap['w'] = 1;
	posicao['x'] = make_pair(2,2); numap['x'] = 2;
	posicao['y'] = make_pair(2,2); numap['y'] = 3;
	posicao['z'] = make_pair(2,2); numap['z'] = 4;

	posicao[' '] = make_pair(3,1); numap[' '] = 1;
	posicao['#'] = make_pair(3,2); numap['#'] = 1;
	

	while(scanf(" %[^\n]",pal)!=EOF)
	{
		len = strlen(pal);
		s = pal[0];
		for(int i=1;i<len;++i)
		{
			if(posicao[pal[i]]==posicao[pal[i-1]]) s.push_back('#');

			s.push_back(pal[i]);
		}
		memset(marc,false,sizeof marc);
		double ans = time(0,1,0,1,2);
		printf("%.2lf\n",ans);
	}
	return 0;
}
