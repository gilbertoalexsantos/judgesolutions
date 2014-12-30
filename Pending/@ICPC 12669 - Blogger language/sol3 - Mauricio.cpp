#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char post[100001];
char text[6];
int bit[100001], plen, tlen, l, r;

int bit_query(int pos) {
    int ret = 0;
    for(pos++; pos > 0; pos &= pos-1)
        ret += bit[pos];
    return ret;
}

void bit_add(int pos, int val) {
    for(pos++; pos <= plen; pos += pos&-pos)
        bit[pos] += val;
}

struct seg_node { int max, min; bool lazy; };
seg_node segtree[262144];

void propagate(int root, int l, int r) {
    if(segtree[root].lazy) {
        int temp = tlen - segtree[root].max;
        segtree[root].max = tlen - segtree[root].min;
        segtree[root].min = temp;

        if(l != r) {
            segtree[2*root+1].lazy = !segtree[2*root+1].lazy;
            segtree[2*root+2].lazy = !segtree[2*root+2].lazy;
        }

        segtree[root].lazy = false;
    }
}

int seg_query(int root, int l, int r, int a, int b) {
    if(a > r || b < l)
        return -1;

    propagate(root, l, r);
    if(l >= a && r <= b)
        return segtree[root].max;

    int mid = (l+r)/2;
    return max(seg_query(2*root+1, l, mid, a, b),
               seg_query(2*root+2, mid+1, r, a, b));
}

void seg_flip(int root, int l, int r, int a, int b) {
    if(a > r || b < l)
        return;

    if(l >= a && r <= b) {
        segtree[root].lazy = !segtree[root].lazy;
        return;
    }

    int mid = (l+r)/2;
    seg_flip(2*root+1, l, mid, a, b);
    seg_flip(2*root+2, mid+1, r, a, b);
}

void seg_update(int root, int l, int r, int pos, int val) {
    if(l == r) {
        segtree[root].max = val;
        segtree[root].min = val == -1 ? tlen+1 : val;
        segtree[root].lazy = false;
        return;
    }

    propagate(root, l, r);
    int mid = (l+r)/2;

    if(pos <= mid) {
        seg_update(2*root+1, l, mid, pos, val);
        propagate(2*root+2, mid+1, r);
    } else {
        propagate(2*root+1, l, mid);
        seg_update(2*root+2, mid+1, r, pos, val);
    }

    segtree[root].max = max(segtree[2*root+1].max, segtree[2*root+2].max);
    segtree[root].min = min(segtree[2*root+1].min, segtree[2*root+2].min);
    segtree[root].lazy = false;
}

void fix_segtree(int i) {
    int cnt = 0;

    for(int j = 0; j < tlen; j++) {
        if(tolower(post[i+j]) != tolower(text[j])) {
            cnt = -1;
            break;
        }

        if(post[i+j] != text[j])
            cnt++;
    }

    seg_update(0, 0, plen - tlen, i, cnt);
}

int main() {
    int n;

    while(scanf("%d %s", &n, text) != EOF) {
        tlen = strlen(text);
        scanf("%s", post);
        plen = strlen(post);

        memset(bit, 0, sizeof bit);
        for(int i = 0; i < plen; i++)
            if(isupper(post[i])) {
                bit_add(i, 1);
                bit_add(i+1, 1);
            }

        memset(segtree, 0, sizeof segtree);
        for(int i = 0; i < plen - tlen + 1; i++)
            fix_segtree(i);

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &l, &r);
            l--; r--;

            if(r-l+1 >= tlen) {
                printf("%d\n", seg_query(0, 0, plen-tlen, l, r-tlen+1));
                seg_flip(0, 0, plen-tlen, l, r-tlen+1);
            } else
                printf("-1\n");

            bit_add(l, 1);
            bit_add(r+1, 1);

            for(int j = max(0, l-tlen+1); j < l+tlen-1; j++) {
                int parity = bit_query(j) % 2;
                post[j] = parity ? toupper(post[j]) : tolower(post[j]);
            }

            for(int j = r-tlen+2; j < min(r+tlen, plen); j++) {
                int parity = bit_query(j) % 2;
                post[j] = parity ? toupper(post[j]) : tolower(post[j]);
            }

            for(int j = max(0, l-tlen+1); j < l; j++)
                fix_segtree(j);

            for(int j = max(0, r-tlen+2); j < min(r+1, plen-tlen+1); j++)
                fix_segtree(j);
        }
    }
}
