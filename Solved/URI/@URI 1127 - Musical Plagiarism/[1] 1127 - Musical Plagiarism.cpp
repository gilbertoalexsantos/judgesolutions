//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/en/problems/view/1127

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

const int MAX_SONG = 100000;
const int MAX_SNIPPET = 10000;

struct cmp { bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

int size_song, size_snippet;
int cnt;
int song[MAX_SONG], snippet[MAX_SNIPPET];
int back[MAX_SONG];
map<char*, int, cmp> MAP;
char note[5];

inline bool equal(int a, int b, int count) { return ((a + count) % 12) == b; }

void ins(const char *c, int cnt) {
	char *w = new char[5];
	strcpy(w,c);
	MAP.insert(make_pair(w,cnt));
}

void init() {
	cnt = 0;
	ins("C",cnt); ins("B#",cnt++);
	ins("Db",cnt); ins("C#",cnt++);
	ins("D",cnt++); 
	ins("Eb",cnt); ins("D#",cnt++);
	ins("E",cnt); ins("Fb",cnt++);
	ins("F",cnt); ins("E#",cnt++);
	ins("Gb",cnt); ins("F#",cnt++);
	ins("G",cnt++);
	ins("Ab",cnt); ins("G#",cnt++);
	ins("A",cnt++); 
	ins("Bb",cnt); ins("A#",cnt++);
	ins("B",cnt); ins("Cb",cnt++);
}

void kmpPreprocess() {
	int i = 0, j = -1; back[0] = -1;
	while(i < size_snippet) {
		while(j >= 0 && snippet[i] != snippet[j])
			j = back[j];
		back[++i] = ++j;
	}
}

bool kmpSearch(int count) {
	int i = 0, j = 0;
	while(i < size_song) {
		while(j >= 0 && !equal(snippet[j],song[i],count))
			j = back[j];
		i++, j++;
		if(j == size_snippet)
			return true;
	}
	return false;
}

bool solve() {
	for(int i = 0; i <= 12; i++)
		if(kmpSearch(i))
			return true;
	return false;
}

int main() {
	init();
	while(scanf("%d %d",&size_song,&size_snippet) && size_song+size_snippet) {
		for(int i = 0; i < size_song; i++) {
			scanf("%s",note);
			song[i] = MAP.find(note)->second;
		}
		for(int i = 0; i < size_snippet; i++) {
			scanf("%s",note);
			snippet[i] = MAP.find(note)->second;
		}
		kmpPreprocess();
		bool ans = solve();
		printf("%c\n",ans ? 'S' : 'N');
	}
}
