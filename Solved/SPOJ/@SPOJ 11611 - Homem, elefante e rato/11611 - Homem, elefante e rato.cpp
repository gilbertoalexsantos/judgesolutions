//Author:	Gilberto A. dos Santos
//Website:	http://br.spoj.com/problems/HOMEM/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct TYPE {
	int a, b, c;

	TYPE() { a = b = c = 0; }
	TYPE(int a, int b, int c) { this->a = a, this->b = b, this->c = c; }
	TYPE operator +(TYPE x) { return TYPE(a+x.a,b+x.b,c+x.c); }
};

class SegmentedTree {
	private:
		int size;
		vector<TYPE> st;
		vector<int> flag;

		int left(int p) { return p << 1; }
		int right(int p) { return (p << 1) + 1; }
		int mid(int a, int b) { return (a+b)/2; }

		void build(int p, int l, int r) {
			if(l == r) {
				st[p] = TYPE(1,0,0);
				return;
			}
			build(left(p),l,mid(l,r));
			build(right(p),mid(l,r)+1,r);
			st[p] = st[left(p)] + st[right(p)];
		}

		void propagate(int p, int l, int r) {	
			int factor = flag[p]%3;
			if(factor != 0) {
				if(factor == 1) swap(st[p].a,st[p].b), swap(st[p].a,st[p].c);
				else swap(st[p].a,st[p].c), swap(st[p].a,st[p].b);
			}
			if(l != r) {
				flag[left(p)] += flag[p];
				flag[right(p)] += flag[p];
			}
			flag[p] = 0;
		}

		TYPE update(int p, int l, int r, int i, int j, int inc) {
			propagate(p,l,r);
			if(i > r || j < l) return TYPE();
			if(i <= l && j >= r) {
				flag[p] += inc;
				propagate(p,l,r);
				return st[p];
			}
			TYPE ans = update(left(p),l,mid(l,r),i,j,inc) + update(right(p),mid(l,r)+1,r,i,j,inc);
			st[p] = st[left(p)] + st[right(p)];
			return ans;
		}

	public:
		SegmentedTree(int n) {
			size = n;
			st.resize(size*4);
			flag.resize(size*4);
			build(1,0,size-1);
		}

		void update(int i, int j) { update(1,0,size-1,i,j,1); }
		TYPE query(int i, int j) { return update(1,0,size-1,i,j,0); }
};

int main() {
	int qt_player, query;
	while(scanf("%d %d",&qt_player,&query) != EOF) {
		SegmentedTree st(qt_player);
		while(query--) {
			char t;
			int l, r;
			scanf(" %c %d %d",&t,&l,&r);
			l--; r--;
			if(t == 'C') {
				TYPE ans;
				ans = st.query(l,r);
				printf("%d %d %d\n",ans.a,ans.b,ans.c);
			} else st.update(l,r);
		}
		printf("\n");
	}
}
