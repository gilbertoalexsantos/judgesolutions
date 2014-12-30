//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=676

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int comb, permu;
bool visited[61];
vector<int> value;

void preComp() {
	memset(visited,0,sizeof visited);
	value.push_back(0);
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 3; j++) {
			int t = i*j;
			if(!visited[t]) {
				visited[t] = 1;
				value.push_back(t);
			}
		}
	value.push_back(50);
}

void getPermutation(int n) {
	comb = 0; permu = 0;
	set<string> m;
	set<string>::iterator it;
	for(int a = 0; a < value.size(); a++) {
		for(int b = 0; b < value.size(); b++) {
			for(int c = 0; c < value.size(); c++) {
				if(value[a]+value[b]+value[c] == n) {
					int arr[3];
					arr[0] = value[a];
					arr[1] = value[b];
					arr[2] = value[c];
					sort(arr+0,arr+3);
					stringstream ss;
					ss << arr[0] << arr[1] << arr[2];
					string word = ss.str();
					it = m.find(word);
					if(it == m.end()) {
						m.insert(word);
						comb++;
					}
					permu++;
				}
			}
		}
	}
}

int main() {
	int n;
	preComp();
	while(scanf("%d",&n) && n > 0) {
		getPermutation(n);
		if(n > 180)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
		else if(comb <= 0 || permu <= 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
		else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,permu);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
}
