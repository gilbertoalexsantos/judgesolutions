//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397

#include <iostream>
#include <ios>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

static const int SET = 1, CLEAR = 2, FLIP = 3;

class SegmentTree {
	private:
		int size;
		vector<int> st;
		vector<int> flag;
		
		int left(int p) { return p << 1; }
		int right(int p) { return (p << 1) + 1; }
		int mid(int a, int b) { return (a+b)/2; }

		void build(int p, int l, int r, string &w) {
			if(l == r) {
				st[p] = w[l] - '0';
				return;
			}

			build(left(p),l,mid(l,r),w);
			build(right(p),mid(l,r)+1,r,w);
			st[p] = st[left(p)] + st[right(p)];
		}

		int invert(int type) {
			if(type == SET) return CLEAR;
			if(type == CLEAR) return SET;
			if(type == FLIP) return 0;
			return FLIP;
		}

		void propagate(int p, int l, int r) {
			if(flag[p] == SET) st[p] = r - l + 1;
			else if(flag[p] == CLEAR) st[p] = 0;
			else if(flag[p] == FLIP) st[p] = (r - l + 1) - st[p];
			if(l != r) {
				if(flag[p] == SET || flag[p] == CLEAR) {
					flag[left(p)] = flag[right(p)] = flag[p];
				} else if(flag[p] == FLIP) {
					flag[left(p)] = invert(flag[left(p)]);
					flag[right(p)] = invert(flag[right(p)]);
				}
			}
			flag[p] = 0;
		}

		int query(int p, int l, int r, int i, int j) {
			propagate(p,l,r);
			if(i > r || j < l) return 0;
			if(i <= l && j >= r) return st[p];
			int p1 = query(left(p),l,mid(l,r),i,j);
			int p2 = query(right(p),mid(l,r)+1,r,i,j);
			return p1 + p2;
		}

		void update(int p, int l, int r, int i, int j, int type) {
			propagate(p,l,r);
			if(i > r || j < l) return;
			if(i <= l && j >= r) {
				flag[p] = type;
				propagate(p,l,r);
				return;
			}
			update(left(p),l,mid(l,r),i,j,type);
			update(right(p),mid(l,r)+1,r,i,j,type);
			st[p] = st[left(p)] + st[right(p)];
		}

	public:
		SegmentTree(string &w) {
			size = w.size();
			st.assign(4*size,0);
			flag.assign(4*size,0);
			build(1,0,size-1,w);
		}

		int query(int i, int j) { return query(1,0,size-1,i,j); }
		void update(int i, int j, int type) { return update(1,0,size-1,i,j,type); }
};

int cases, n, m, z;

int main() {
	ios::sync_with_stdio(false);
	int test = 1;
	cin >> cases;
	while(cases--) {
		string word = "";
		cin >> n;
		while(n--) {
			string temp;
			cin >> m >> temp;	
			while(m--) word += temp;
		}
		SegmentTree st(word);
		cin >> z;
		cout << "Case " << test++ << ":" << endl;
		int cont = 1;
		while(z--) {
			char op;
			int l, r;
			cin >> op >> l >> r;
			if(op == 'F') st.update(l,r,SET);
			else if(op == 'E') st.update(l,r,CLEAR);
			else if(op == 'I') st.update(l,r,FLIP);
			else cout << "Q" << cont++ << ": " << st.query(l,r) << endl;
		}
	}
}
