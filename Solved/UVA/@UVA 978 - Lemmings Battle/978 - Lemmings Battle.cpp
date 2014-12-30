//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=919

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef priority_queue<int> pq;

int n;
int b;
pq sg, sb;

void battle() {
	vector<int> temp_sg, temp_sb;
	int m = min(sg.size(),sb.size());
	int field = 0;
	while(!sg.empty() && !sb.empty() && field < b) {
		int tgreen = sg.top();
		int tblue = sb.top();
		if(tgreen > tblue) temp_sg.push_back(tgreen-tblue);
		else if(tgreen < tblue) temp_sb.push_back(tblue-tgreen);
		sg.pop(); sb.pop();
		field++;
	}
	for(int i = 0; i < temp_sg.size(); i++)
		sg.push(temp_sg[i]);
	for(int i = 0; i < temp_sb.size(); i++)
		sb.push(temp_sb[i]);
}

int main() {
	bool first = true;
	scanf("%d",&n);
	while(n--) {
		if(first) first ^= first;
		else cout << "\n";
		int nsg, nsb;
		scanf("%d %d %d", &b, &nsg, &nsb);
		while(nsg--) {
			int temp;
			scanf("%d",&temp);
			sg.push(temp);
		}
		while(nsb--) {
			int temp;
			scanf("%d",&temp);
			sb.push(temp);
		}
		while(!(sg.empty() || sb.empty())) battle();
		if(!sg.empty()) {
			cout << "green wins\n";
			while(!sg.empty()) {
				cout << sg.top() << endl;
				sg.pop();
			}
		} else if(!sb.empty()) {
			cout << "blue wins\n";
			while(!sb.empty()) {
				cout << sb.top() << endl;
				sb.pop();
			}
		} else cout << "green and blue died\n";
	}
}
