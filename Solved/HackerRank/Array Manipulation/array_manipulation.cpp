//Author: Gilberto A. dos Santos
//Website: https://www.hackerrank.com/challenges/crush/problem
//Took a few ideas about Dynamic Segment Tree from http://codeforces.com/blog/entry/19080

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

struct node {
    int lv, rv;
    ll v;
    node *left, *right;

    void init(int l, int r) {
        v = 0;
        left = right = NULL;
        lv = l;
        rv = r;
    }

    void lazy() {
        if (lv == rv) {
            return;
        }

        extend();
        left->v += v;
        right->v += v;
        v = 0;
    }

    void extend() {
        if (!left) {
            int m = (lv + rv) / 2;
            left = (node*)malloc(sizeof(node));
            right = (node*)malloc(sizeof(node));
            left->init(lv, m);
            right->init(m+1, rv);
        }
    }

    void update(int i, int j, ll add) {
        if (lv > j || rv < i)
            return;

        if (lv >= i && rv <= j) {
            v += add;
            lazy();
            return;
        }

        extend();
        left->update(i, j, add);
        right->update(i, j, add);
    }

    ll best() {
        if (!left) {
            return v;
        }

        lazy();
        return max(left->best(), right->best());
    }

};

int n, m;
node st;

int main() {
    scanf("%d %d", &n, &m);
    st.init(1, n);
    for (int i = 0; i < m; i++) {
        int l, r;
        ll v;
        scanf("%d %d %lld", &l, &r, &v);
        st.update(l, r, v);
    }
    printf("%lld\n", st.best());
}
