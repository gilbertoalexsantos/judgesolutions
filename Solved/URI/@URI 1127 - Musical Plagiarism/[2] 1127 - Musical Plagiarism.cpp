//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/en/problems/view/1127

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int MAX_SONG = 100000;
const int MAX_SNIPPET = 10000;

struct cmp { bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

int size_song, size_snippet, cnt;
int song[MAX_SONG], snippet[MAX_SNIPPET];
vector<int> new_song, new_snippet;
int back[MAX_SONG];
map<char*, int, cmp> MAP;
int value[20];
int dist[20][20];
char note[5];

void ins(const char *c, int cnt) {
	char *w = new char[5];
	strcpy(w,c);
	MAP.insert(make_pair(w,cnt));
	value[cnt] = cnt;
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
	for(int i = 0; i < cnt; i++) {
		for(int j = 0; j < cnt; j++) {
			if(value[i] > value[j])
				dist[i][j] = 12 + value[j] - value[i];
			else
				dist[i][j] = value[j] - value[i];
		}
	}
}

void buildNew() {
	for(int i = 0; i < size_song - 1; i++)
		new_song.push_back(dist[song[i]][song[i+1]]);
	for(int i = 0; i < size_snippet - 1; i++)
		new_snippet.push_back(dist[snippet[i]][snippet[i+1]]);
}

void kmpPreprocess() {
	int i = 0, j = -1; back[0] = -1;
	while(i < new_snippet.size()) {
		while(j >= 0 && new_snippet[i] != new_snippet[j])
			j = back[j];
		back[++i] = ++j;
	}
}

bool kmpSearch() {
	int i = 0, j = 0;
	while(i < new_song.size()) {
		while(j >= 0 && new_snippet[j] != new_song[i])
			j = back[j];
		i++, j++;
		if(j == new_snippet.size())
			return true;
	}
	return false;
}

bool solve() {
	kmpPreprocess();
	return kmpSearch();
}

int main() {
	init();
	while(scanf("%d %d",&size_song,&size_snippet) && size_song+size_snippet) {
		new_song.clear(); new_snippet.clear();
		for(int i = 0; i < size_song; i++) {
			scanf("%s",note);
			song[i] = MAP.find(note)->second;
		}
		for(int i = 0; i < size_snippet; i++) {
			scanf("%s",note);
			snippet[i] = MAP.find(note)->second;
		}
		if(size_snippet == 1) {
			printf("S\n");
		} else if(size_song == 1) {
			printf("N\n");
		} else {
			buildNew();
			kmpPreprocess();
			bool ans = solve();
			printf("%c\n",ans ? 'S' : 'N');
		}
	}
}

