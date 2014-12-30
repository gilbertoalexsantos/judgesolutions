//Author:	Gilberto A. dos Santos
//Website:	http://br.spoj.com/problems/CAMPSMS/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int debug;

struct point {
	int x, y;

	point(int x, int y) { this->x = x, this->y = y; }
};

const int vel = 30.00;
const double t_press = 0.20;
const char ini_left = 'g', ini_right = 'm';
const char letter[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','#','\0'};
const int size_letter = strlen(letter);

double dist[123][123], memo[123][288];
bool same[123][123];
int qt_press2[123];

point transform(char c) {
	if(c == 'a' || c == 'b' || c == 'c') return point(0,1);
	if(c == 'd' || c == 'e' || c == 'f') return point(0,2);
	if(c == 'g' || c == 'h' || c == 'i') return point(1,0);
	if(c == 'j' || c == 'k' || c == 'l') return point(1,1);
	if(c == 'm' || c == 'n' || c == 'o') return point(1,2);
	if(c == 'p' || c == 'q' || c == 'r' || c == 's') return point(2,0);
	if(c == 't' || c == 'u' || c == 'v') return point(2,1);
	if(c == 'w' || c == 'x' || c == 'y' || c == 'z') return point(2,2);
	if(c == '0') return point(3,1);
	if(c == '#') return point(3,2);
	return point(-1,-1);
}

bool same_key(char a, char b) {
	if(a == '#') return b == '#';
	if(a == '0') return b == '0';
	if(a == 'a' || a == 'b' || a == 'c') return (b == 'a' || b == 'b' || b == 'c');
	if(a == 'd' || a == 'e' || a == 'f') return (b == 'd' || b == 'e' || b == 'f');
	if(a == 'g' || a == 'h' || a == 'i') return (b == 'g' || b == 'h' || b == 'i');
	if(a == 'j' || a == 'k' || a == 'l') return (b == 'j' || b == 'k' || b == 'l');
	if(a == 'm' || a == 'n' || a == 'o') return (b == 'm' || b == 'n' || b == 'o');
	if(a == 'p' || a == 'q' || a == 'r' || a == 's') return (b == 'p' || b == 'q' || b == 'r' || b == 's');
	if(a == 't' || a == 'u' || a == 'v') return (b == 't' || b == 'u' || b == 'v');
	if(a == 'w' || a == 'x' || a == 'y' || a == 'z') return (b == 'w' || b == 'x' || b == 'y' || b == 'z');
	return false;
}

int qt_press(char c) {
	if(c == '#' || c == '0') return 1;
	if(c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' || c == 't' || c == 'w') return 1;
	if(c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' || c == 'u' || c == 'x') return 2;
	if(c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' || c == 'v' || c == 'y') return 3;
	if(c == 's' || c == 'z') return 4;
	return -1;
}

double euclides_dist(point a, point b) { return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2)); }

void init_dist() {
	for(int i = 0; i < size_letter; i++) {
		qt_press2[letter[i]] = qt_press(letter[i]);
		for(int j = 0; j < size_letter; j++) {
			same[letter[i]][letter[j]] = same_key(letter[i],letter[j]);
			double &ret1 = dist[letter[i]][letter[j]];
			double &ret2 = dist[letter[j]][letter[i]];
			if(i == j) {
				ret1 = ret2 = 0;
				continue;
			}
			ret1 = ret2 = euclides_dist(transform(letter[i]),transform(letter[j]))/vel;
		}
	}
}

inline double value(char c) { return t_press * qt_press2[c]; }

double dp(char word[], int size_word, char finger = ini_right, int pos = 0) {
	double &ret = memo[finger][pos];
	if(ret != 0) { return ret; }

	double r_not = 0, r_in = 0, ans = 0;
	char c = word[pos];
	char prev = (pos != 0) ? word[pos-1] : ini_left;
	ans += value(c);

	if(pos+1 == size_word) { 
		r_not = dist[prev][c];
		r_in = dist[finger][c];
		return ret = min(ans + r_not,ans + r_in);
	}
	
	if(same[prev][c] || same[finger][c]) {
		return ret = ans + ((same[prev][c]) ? dp(word,size_word,finger,pos+1) : dp(word,size_word,prev,pos+1));
	}

	r_not = dist[prev][c] + dp(word,size_word,finger,pos+1);
	r_in = dist[finger][c] + dp(word,size_word,prev,pos+1);
	ans += min(r_not,r_in);

	return ret = ans;
}

int change_word(char old[], char nnew[], int size_old) {
	nnew[0] = old[0];
	int cont = 1;
	for(int i = 1; i < size_old; i++) {
		if(same[old[i]][old[i-1]]) { nnew[cont++] = '#'; }
		nnew[cont] = old[i];
		if(nnew[cont] == ' ') nnew[cont] = '0';
		cont++;
	}
	return cont;
}

int main() {
	init_dist();
	char word[141];
	while(scanf("%[^\n]",word) != EOF) {
		memset(memo,0,sizeof memo);
		getchar();
		int size_word = strlen(word);
		char new_word[288];
		int new_size = change_word(word,new_word,size_word);
		printf("%.2f\n",dp(new_word,new_size));
	}
}
