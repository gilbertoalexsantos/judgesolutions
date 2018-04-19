//Author: Gilberto A. dos Santos
//Website: https://www.hackerrank.com/challenges/array-pairs/problem

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;


typedef pair<int, int> ii;


inline int ll(int p) { return p * 2; }
inline int rr(int p) { return p * 2 + 1; }
inline int mid(int l, int r) { return (l + r) / 2; }
inline int size_st(int n) { return 2 * (pow(2, ceil(log2(n)))) - 1; }

struct node_st_maximum {
	int size;
	vector<ii> st;

	ii build(int p, int l, int r, int v[]) {
		if (l > r) {
			return ii(-1e9, -1e9);
		} else if (l == r) {
			return st[p] = ii(v[l], l);
		}

		ii lv = build(ll(p), l, mid(l, r), v);
		ii rv = build(rr(p), mid(l, r) + 1, r, v);
		return st[p] = max(lv, rv);
	}

	void init(int n, int v[]) {
		size = n;
		st.assign(size_st(size) + 1, ii(-1e9, -1e9));
		build(1, 0, size - 1, v);
	}

	ii _query(int p, int l, int r, int i, int j) {
		if (i > r || j < l) {
			return ii(-1e9, -1e9);
		} else if (l >= i && r <= j) {
			return st[p];
		}

		ii lv = _query(ll(p), l, mid(l, r), i, j);
		ii rv = _query(rr(p), mid(l, r) + 1, r, i, j);
		return max(lv, rv);
	}

	ii query(int i, int j) {
		return _query(1, 0, size - 1, i, j);
	}

};

struct node_st_query {
	int size;
	vector<vector<int>*> st;

	vector<int>* build(int p, int l, int r, int v[]) {
		if (l > r) {
			return new vector<int>();
		} else if (l == r) {
			vector<int>* s = new vector<int>(); 
			s->push_back(v[l]); 
			return st[p] = s;
		}

		vector<int>* lv = build(ll(p), l, mid(l, r), v);
		vector<int>* rv = build(rr(p), mid(l, r) + 1, r, v);

		vector<int>* mv = new vector<int>();
        merge(lv->begin(), lv->end(), rv->begin(), rv->end(), back_inserter(*mv));
        
		return st[p] = mv;
	}

	void init(int n, int v[]) {
		size = n;
		st.assign(size_st(size) + 1, NULL);
		build(1, 0, size - 1, v);
	}

	long long qt(vector<int>* s, int v) {
		if (s == NULL) {
			return 0;
		}

		auto it = upper_bound(s->begin(), s->end(), v);
		if (it == s->end()) {
			return s->size();
		} else {
			return it - s->begin();
		}
	}

	long long _query(int p, int l, int r, int i, int j, int v) {
		if (i > r || j < l) {
			return 0;
		} else if (l >= i && r <= j) {
			return qt(st[p], v);
		}

		long long lv = _query(ll(p), l, mid(l, r), i, j, v);
		long long rv = _query(rr(p), mid(l, r) + 1, r, i, j, v);
		return lv + rv;
	}

	long long query(int i, int j, int v) {
		return _query(1, 0, size - 1, i, j, v);
	}

};

int n;
int arr[(int)5e5 + 10];
node_st_maximum st_max;
node_st_query st_query;

long long solve() {
    long long ans = 0;

    stack<ii> ranges;
    ranges.push(ii(0, n-1));

    while (ranges.size() > 0) {
        ii range = ranges.top(); ranges.pop();
        int l = range.first, r = range.second;
        if (l >= r) {
            continue;
        }

        ii m = st_max.query(l, r);
        int qt_left = m.second - l;
        int qt_right = r - m.second;

        ii rangeToSearch, rangeToQuery;
        if (qt_left < qt_right) {
            rangeToSearch = ii(l, m.second - 1);
            rangeToQuery = ii(m.second + 1, r);
        } else {
            rangeToSearch = ii(m.second + 1, r);
            rangeToQuery = ii(l, m.second - 1);
        }

        for (int i = rangeToSearch.first; i <= rangeToSearch.second; i++) {
            int v = m.first / arr[i];
            ans += st_query.query(rangeToQuery.first, rangeToQuery.second, v);
        }

        ans += st_query.query(m.second + 1, r, 1);
        ans += st_query.query(l, m.second - 1, 1);

        ranges.push(rangeToSearch);
        ranges.push(rangeToQuery);
    }

    return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	st_max.init(n, arr);
	st_query.init(n, arr);

	long long ans = solve();
	printf("%lld\n", ans);
}
