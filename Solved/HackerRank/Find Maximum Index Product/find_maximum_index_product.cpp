//Author: Gilberto A. dos Santos
//Website: https://www.hackerrank.com/challenges/find-maximum-index-product/problem

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 10;
pair<long long, int> arr[MAX_N];
set<int> positive_indexes, negative_indexes;
set<int>::iterator it;
long long ll[MAX_N], rr[MAX_N];
int n;

long long calculate_left(int i) {
    it = negative_indexes.upper_bound(-arr[i].second);
    return it != negative_indexes.end() ? -*it : 0;
}

long long calculate_right(int i) {
    it = positive_indexes.upper_bound(arr[i].second);
    return it != positive_indexes.end() ? *it : 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long v; scanf("%lld", &v);
        arr[i] = pair<long long, int>(v, i+1);
    }

    sort(arr, arr + n);

    int i = n-1;
    while (i >= 0) {
        long long l = calculate_left(i);
        long long r = calculate_right(i);

        long long v = arr[i].first;
        while (i >= 0 && arr[i].first == v) {
            ll[arr[i].second] = l;
            rr[arr[i].second] = r;
            positive_indexes.insert(arr[i].second);
            negative_indexes.insert(-arr[i].second);
            i--;
        }
    }

    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, ll[i] * rr[i]);

    printf("%lld\n", answer);
}
