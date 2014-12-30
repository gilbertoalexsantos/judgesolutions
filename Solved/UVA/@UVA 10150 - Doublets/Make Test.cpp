#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int MAX = 21543;
const int QT_PAIR = 100;
const int QT_LETTER = 5;
const int SIZE = 10;

struct TYPE {
	char *w;

	TYPE(const char *a) { w = new char[50]; strcpy(w,a); }
};

struct cmp { bool operator()(const char *a, const char *b) const { return strcmp(a,b) < 0; } };

set<char*,cmp> s;
vector<TYPE> v;

char getC() { return abs(rand()%QT_LETTER); }
int getN() { return abs(rand()%SIZE); }
int getI() { return abs(rand()%MAX); }

void putDic() {
	int i = 0;
	while(i < MAX) {
		int qt_char = getN();
		if(qt_char == 0) continue;
		char *w = new char[50];
		for(int j = 0; j < qt_char; j++) w[j] = getC()+'a';
		if(s.count(w) > 0) continue;
		s.insert(w);
		v.push_back(TYPE(w));
		i++;
		printf("%s\n",w);
		free(w);
		w = NULL;
	}
}

void putPair() {
	int i = 0;
	while(i < QT_PAIR) {
		int a = getI(), b = getI();
		char w1[50], w2[50];
		for(int i = 0; i < MAX; i++) {
			if(a == i) strcpy(w1,v[i].w);
			if(b == i) strcpy(w2,v[i].w);
		}
		printf("%s %s\n",w1,w2);
		i++;
	}
}

int main() {
	srand(time(NULL));
	putDic();	
	printf("\n");
	putPair();
}
