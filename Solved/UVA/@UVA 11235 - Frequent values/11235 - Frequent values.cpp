//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2176

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
	private:
		int size;
		vi st;

		int left(int p) { return p << 1; }
		int right(int p) { return (p << 1) + 1; }
		int mid(int a, int b) { return (a + b) / 2; }

		void build(int p, int l, int r, vi &v) {
			if(l == r) st[p] = v[l];
			else {
				build(left(p),l,mid(l,r),v);
				build(right(p),mid(l,r)+1,r,v);
				st[p] = max(st[left(p)],st[right(p)]);
			}
		}

		int rmq(int p, int l, int r, int i, int j) {
			if(i > r || j < l) return -1;
			if(l >= i && r <= j) return st[p];
			int p1 = rmq(left(p),l,mid(l,r),i,j);
			int p2 = rmq(right(p),mid(l,r)+1,r,i,j);
			if(p1 == -1) return p2;
			if(p2 == -1) return p1;
			return max(p1,p2);
		}
		
	public:
		SegmentTree(vi &v) {
			size = v.size();
			st.assign(size * 4,0);
			build(1,0,size-1,v);
		}

		int rmq(int i, int j) { return rmq(1,0,size-1,i,j); }
};

void change(int x, int y, int value, vi &cnt) {
	for(int i = x; i <= y; i++) cnt[i] = value;
}

int n, m;

int main() {
	while(scanf("%d",&n) && n) {
		scanf("%d",&m);
		vi arr(n), cnt(n), start(n);
		for(int i = 0; i < n; i++) {
			scanf("%d",&arr[i]);
			if(!i) {
				start[i] = i;
				cnt[i] = 1;
			} else if(arr[i] == arr[i-1]) {
				start[i] = start[i-1];
				cnt[i] = cnt[i-1] + 1;
			}
			else {
				change(start[i-1],i-1,cnt[i-1],cnt);
				cnt[i] = 1;
				start[i] = i;
			}
		}
		change(start[n-1],n-1,cnt[n-1],cnt);
    // puts("");
    // for(int i = 0; i < n; i++) {
    //   printf("CNT[%d] => %d\nSTART[%d] => %d\n\n",i,cnt[i],i,start[i]);
    // }
    // exit(0);
		SegmentTree st(cnt);
		while(m--) {
			int i, j;
			scanf("%d %d",&i, &j);
			i--; j--;
			if(arr[i] == arr[j]) printf("%d\n",j - i + 1);
			else {
				int ans;
				int v1 = cnt[i] - (i - start[i]);
				int v2 = j - start[j] + 1;
				int v3 = 0;
				int qr1 = i + v1;
				int qr2 = start[j] - 1;
				if(qr1 < qr2) v3 = st.rmq(qr1,qr2);
				ans = max(v1,max(v2,v3));
				printf("%d\n",ans);
			}
		}
	}
}

