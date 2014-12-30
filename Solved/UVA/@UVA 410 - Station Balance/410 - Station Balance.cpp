//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define trace(x...) x

void solve(int qt_chamber, int qt_specime, vector<int> &arr, double AM) {
	while(arr.size() < qt_chamber*2) arr.push_back(0);
	sort(arr.begin(),arr.end());
	int left = 0, right = qt_chamber*2-1;
	double imbalance = 0;
	for(int i = 0; i < qt_chamber; i++,left++,right--) {
		printf(" %d:",i);
		if(arr[left]) printf(" %d",arr[left]);
		if(arr[right]) printf(" %d",arr[right]);
		imbalance += fabs((arr[left]+arr[right])-AM);
		printf("\n");
	}
	printf("IMBALANCE = %.5f\n\n",imbalance);
}

int main() {
	int cases = 1, qt_chamber, qt_specime;
	while(scanf("%d %d",&qt_chamber,&qt_specime) != EOF) {
		vector<int> arr(qt_specime);
		int sum = 0;
		double AM;
		for(int i = 0; i < qt_specime; i++) {
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		AM = (double) sum/qt_chamber;
		printf("Set #%d\n",cases++);
		solve(qt_chamber,qt_specime,arr,AM);
	}
}
