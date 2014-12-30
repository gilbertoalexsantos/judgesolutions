//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3154

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> pint;

int n, m, p, u, L, R, v;
pint bucket[300000];
int arr[300000];

int bb(int l, int r, int MAX, int value) {
	int old_l = l;
	while(l <= r) {
		int mid = (l+r)/2;
		if(bucket[mid].first >= value) r = mid-1;
		else l = mid+1;
	}
	return l - old_l;
}

int out_bucket(int l, int r, int cl, int cr, int value) {
	int sum = 0;
	while(l <= r) {
		if(bucket[l].first < value && bucket[l].second >= cl && bucket[l].second <= cr)
			sum++;
		l++;
	}
	return sum;
}

void change(int l, int r, int pos) {
	int old_l = l;
	while(l <= r) {
		if(bucket[l].second == pos) {
			bucket[l].first = arr[pos];
			break;
		}
		l++;
	}
	sort(bucket+old_l,bucket+r+1);
}

int main() { 
	scanf("%d %d %d",&n, &m, &u);

	const int MAX = (int) sqrt(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		bucket[i].first = arr[i];
		bucket[i].second = i;
	}

	int cont;
	for(cont = 0; cont+(2*MAX) <= n; cont += MAX) {
		int left = cont;
		int right = left + MAX - 1;
		sort(bucket+left,bucket+right+1);
	}
	sort(bucket+cont,bucket+n);

	while(m--) {
		scanf("%d %d %d %d",&L, &R, &v, &p);
		L--; R--; p--;
		int left, right;
		int sum = 0;
		for(left = 0; left+(2*MAX) <= n; left += MAX) {
			right = left + MAX - 1;
			if(left > R || right < L) continue;
			else if(L <= left && R >= right) sum += bb(left,right,MAX,v);
			else sum += out_bucket(left,right,L,R,v);
		}
		right = n - 1;

		if(left > R || right < L) {}
		else if(L <= left && R >= right) sum += bb(left,right,MAX,v);
		else sum += out_bucket(left,right,L,R,v);

		R++; L++;
		arr[p] = (long long) u * sum / (R - L + 1);

		for(left = 0; left+(2*MAX) <= n; left += MAX) {
			right = left + MAX - 1;
			if(p >= left && p <= right) change(left,right,p);
		}
		right = n - 1;
		if(p >= left && p <= right) change(left,right,p);
	}
	for(int i = 0; i < n; i++) printf("%d\n",arr[i]);
}
