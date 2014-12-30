//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=97

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_LIGHT = 100;
const int GREEN = -1, RED = 0, ORANGE = 2;
const int LIMIT = 18000;

int light[MAX_LIGHT], tm[MAX_LIGHT];
int shine[MAX_LIGHT];
int size;

void clear() {
	size = 1;
	memset(shine,GREEN,sizeof shine);
	memset(tm,0,sizeof tm);
}

void pr(int seconds) {
	int hours = seconds / 3600;
	seconds -= hours * 3600;

	int minutes = seconds / 60;
	seconds -= minutes * 60;

	printf("%02d:%02d:%02d\n",hours,minutes,seconds);
}

bool allOn() {
	for(int i = 0; i < size; i++)
		if(shine[i] != GREEN)
			return false;
	return true;
}

// Snow Patrol - Run
void lightUp() {
	for(int i = 0; i < size; i++) {
		tm[i]++;
		if(shine[i] == RED && tm[i] == light[i]) {
			tm[i] = 0;
			shine[i] = GREEN;
		} else if(shine[i] == GREEN && tm[i] == light[i] - 5) {
			shine[i] = ORANGE;
		} else if(tm[i] == light[i]) {
			tm[i] = 0;
			shine[i] = RED;
		}
	}
}

int lightOrange() {
	int ret = 0;
	while(shine[0] != ORANGE)
		ret++, lightUp();
	return ret;
}

int calcTime() {
	for(int i = 0; i <= LIMIT; i++) {
		if(allOn())
			return i;
		lightUp();
	}
	return LIMIT;
}

int main() {
	int x;
	while(scanf("%d",&x) && x != 0) {
		clear();
		light[0] = x;
		while(scanf("%d",&x) && x != 0)
			light[size++] = x;
		sort(light,light + size);
		int s1 = lightOrange();
		int s2 = calcTime();
		if(s1 + s2 > LIMIT)
			printf("Signals fail to synchronise in 5 hours\n");
		else {
			pr(s1+s2);
		}
	}
}
