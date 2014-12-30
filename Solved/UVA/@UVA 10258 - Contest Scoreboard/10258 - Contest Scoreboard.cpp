//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1199

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct d {
	int problems;
	int time;
	int pos;
};

bool comp(d x, d y) {
	if(x.problems > y.problems) return 1;
	else if(x.problems < y.problems) return 0;

	if(x.time < y.time) return 1;
	else if(x.time > y.time) return 0;

	if(x.pos < y.pos) return 1;
	else return 0;
}

int n;
vector<d> contestant;
int submited[100 + 1][10] = {0};
bool made[100 + 1][10] = {0};
bool cont[100 + 1] = {0};

int main() {
	scanf("%d\n",&n);
	while(n--) {
		string line;
		getline(cin,line);
		while(line != "") {
			stringstream pl(line);
			int c, p, t;
			char l;
			pl >> c >> p >> t >> l;
			if(l == 'C') {
				cont[c] = 1;
				if(!made[c][p]) {
					made[c][p] = 1;
					submited[c][p] = t + submited[c][p] * 20;
				}
			} else if(l == 'I') { 
				if(!made[c][p]) {
					cont[c] = 1; 
					submited[c][p] += 1; 
				}
			}
			else cont[c] = 1;
			getline(cin,line);
		}
		for(int i = 1; i <= 100; i++) {
			d temp;
			temp.problems = 0;
			temp.time = 0;
			temp.pos = i;
			for(int j = 1; j <= 9; j++) {
				if(made[i][j]) {
					temp.problems += 1;
					temp.time += submited[i][j];
				}
			}
			if(cont[i]) contestant.push_back(temp);
		}
		sort(contestant.begin(), contestant.end(), comp);
		for(int i = 0; i < contestant.size(); i++)
			printf("%d %d %d\n",contestant[i].pos,contestant[i].problems,contestant[i].time);
		if(n) cout << endl;
		memset(cont, 0, sizeof cont);
		memset(submited,0,sizeof submited);
		memset(made,0,sizeof made);
		contestant.clear();
	}
}
