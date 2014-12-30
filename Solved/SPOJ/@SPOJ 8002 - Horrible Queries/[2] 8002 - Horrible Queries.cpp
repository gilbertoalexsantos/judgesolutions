//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/HORRIBLE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

class BIT {
  private:
    vl b1, b2;
    int n;

    inline int lsone(int a) { return a & -a; }

    void update(int a, ll v, vl &bit) {
      for(; a <= n; a += lsone(a))
        bit[a] += v;
    }

    ll query(int a, vl &bit) {
      ll sum = 0;
      for(; a > 0; a -= lsone(a))
        sum += bit[a];
      return sum;
    }

    ll query(int a) {
      return query(a,b1) * a + query(a,b2);
    }

  public:
    BIT(int size) {
      n = size;
      b1.assign(n+1,0); 
      b2.assign(n+1,0);
    }

    void update(int a, int b, ll v) {
      update(a,v,b1);
      update(b+1,-v,b1);

      update(a,-v*(a-1),b2);
      update(b+1,v*b,b2);
    }

    ll query(int a, int b) {
      return query(b) - query(a-1);
    }

};

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x, c;
		scanf("%d %d",&x,&c);
    BIT bit(x);
		while(c--) {
			int op;
			scanf("%d",&op);
			if(op) {
				int a, b;
				scanf("%d %d",&a,&b);
				printf("%lld\n",bit.query(a,b));
			} else {
				int a, b;
				ll z;
				scanf("%d %d %lld",&a,&b,&z);
        bit.update(a,b,z);
			}
		}
	}
}
