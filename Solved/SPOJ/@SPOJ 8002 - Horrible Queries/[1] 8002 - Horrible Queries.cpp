//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/HORRIBLE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

class SegmentedTree {
private:
	int size;
    vi st;
    vi flag;
    
    int left(int  p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }
    int mid (int a, int b) { return (a+b)/2; }

	void propagate(int p, int l, int r) {
		st[p] += (ll) (r - l + 1) * flag[p];
		if(l != r) {
			flag[left(p)] += flag[p];
			flag[right(p)] += flag[p];
		}
		flag[p] = 0;
	}
    
    ll range(int p, int l, int r, int i, int j) {
		propagate(p,l,r);
        if (i > r || j < l) return 0;
        if (i <= l && j >= r) return st[p];
		ll p1 = range(left(p),l,mid(l,r),i,j);
		ll p2 = range(right(p),mid(l,r)+1,r,i,j);
		return p1 + p2;
    }

	void update(ll p, ll l, ll r, ll i, ll j, ll value) {
		propagate(p,l,r);
		if (i > r || j < l) return;
		if (i <= l && j >= r) {
			flag[p] += value;
			propagate(p,l,r);
			return;
		}
		update(left(p),l,mid(l,r),i,j,value);
		update(right(p),mid(l,r)+1,r,i,j,value);
		st[p] = st[left(p)] + st[right(p)];
	}
    
public:
	SegmentedTree(int n) {
		size = n;
		st.assign(size*4,0);
		flag.assign(size*4,0);
	}

	ll range(int i, int j) { return range(1,0,size-1,i,j); }
	void update(int i, int j, ll value) { update(1,0,size-1,i,j,value); }
};

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x, c;
		scanf("%d %d",&x,&c);
		SegmentedTree st(x+1);
		while(c--) {
			int op;
			scanf("%d",&op);
			if(op) {
				int a, b;
				scanf("%d %d",&a,&b);
				a--; b--;
				printf("%lld\n",st.range(a,b));
			} else {
				int a, b;
				ll z;
				scanf("%d %d %lld",&a,&b,&z);
				a--; b--;
				st.update(a,b,z);
			}
		}
	}
}
