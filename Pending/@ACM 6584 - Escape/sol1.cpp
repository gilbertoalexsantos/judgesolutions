// Model solution for problem E
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;

typedef pair<LL,LL> PI;
typedef multiset<PI> SP;
typedef multiset<PI>::iterator spt;

const LL infty = 1LL << 60;

const int maxn = 200*1000;

int W[maxn+1];
vector<int> G[maxn+1];
int target;

SP* merge(SP* a, SP* b)
{
  for(spt t = b->begin(); t!=b->end(); t++)
    a->insert(*t);
  delete(b);
  return a;
}

void push(SP* a, PI f)
{
  if (a->size()==0)
  {
    if (f.second>f.first)
      a->insert(f);
    return;
  }
  PI g = *(a->begin());
  if (f.first>=f.second || f.first>=g.first)
  {
    LL x = max(f.first,f.first-f.second+g.first);
    LL y = f.second+g.second-f.first-g.first+x;
    a->erase(a->begin());
    push(a,PI(x,y));
  } else
    a->insert(f);
}

SP* go(int u, int p)
{
  SP* r = new SP;
  if (u==target)
  {
    PI f(max(-W[u],0),infty);
    r->insert(f);
    return r;
  }
  SP *s;
  for(int i=0; i<G[u].size(); i++)
  {
    int x = G[u][i];
    if (x==p)
      continue;
    s = go(x,u);
    if (r->size()>=s->size())
      r = merge(r,s);
    else
      r = merge(s,r);
  }
  PI f(0,0);
  if (W[u]>=0)
    f.second = W[u];
  else
    f.first = -W[u];
  push(r,f);
  return r;
}

int main()
{
  int TT,n;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d %d",&n,&target);
    for(int i=1; i<=n; i++)
      scanf("%d",&W[i]);
    for(int i=1; i<=n-1; i++)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    SP* res = go(1,-1);
    LL hp = 0;
    int c = 0;
    for(spt t = res->begin(); t!=res->end(); t++)
    {
      c++;
      assert(t->first<=t->second);
      if (t->first>hp)
        break;
      hp += t->second-t->first;
      if (hp>infty/2)
        break;
    }
    printf(hp>infty/2 ? "escaped\n" : "trapped\n");
    for(int i=1; i<=n; i++)
      G[i].clear();
    delete res;
  }
}
