//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=342

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 25;
const char NOT = '.';

char word[MAX_LENGTH];
int size;
char rev[150];

void init() {
	memset(rev,NOT,sizeof rev);
	rev['A'] = 'A'; rev['E'] = '3';
	rev['H'] = 'H'; rev['I'] = 'I';
	rev['J'] = 'L'; rev['L'] = 'J';
	rev['M'] = 'M'; rev['O'] = 'O';
	rev['S'] = '2'; rev['T'] = 'T';
	rev['U'] = 'U'; rev['V'] = 'V';
	rev['W'] = 'W'; rev['X'] = 'X';
	rev['Y'] = 'Y'; rev['Z'] = '5';
	rev['1'] = '1'; rev['2'] = 'S';
	rev['3'] = 'E'; rev['5'] = 'Z';
	rev['8'] = '8';
}

bool isPalindrome() {
	int left = 0, right = size - 1;
	while(left <= right) {
		if(word[left] != word[right])
			return false;
		left++, right--;
	}
	return true;
}

bool isMirroed() {
	int left = 0, right = size - 1;
	while(left <= right) {
		char before_l = word[left], before_r = word[right];
		if(rev[word[left]] == NOT || rev[word[right]] == NOT)
			return false;
		char after_l = rev[word[left]], after_r = rev[word[right]];
		if(before_l != after_r || before_r != after_l)
			return false;
		left++, right--;
	}
	return true;
}

int main() {
	init();
	while(scanf("%s",word) != EOF) {
		size = strlen(word);
		bool pal = isPalindrome(), mir = isMirroed();
		printf("%s -- ",word);
		if(pal && mir)
			printf("is a mirrored palindrome.");
		else if(mir && !pal)
			printf("is a mirrored string.");
		else if(pal && !mir)
			printf("is a regular palindrome.");
		else
			printf("is not a palindrome.");
		printf("\n\n");
	}
}
