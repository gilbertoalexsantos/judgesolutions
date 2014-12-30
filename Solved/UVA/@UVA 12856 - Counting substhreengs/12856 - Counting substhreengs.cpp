//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4721

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1e6 + 10;
char word[MAX];
vector<string> strs;
int memo[MAX][4];

inline bool isNumber(char c) { return c >= '0' && c <= '9'; }
inline int getNumber(char c) { return c - '0'; }

void breakString() {
  int i = 0;
  int size = strlen(word);
  while(i < size && !isNumber(word[i])) i++;      
  while(i < size) {
    int right = i+1;
    string toAppend = ""; toAppend += word[i];
    while(right < size && isNumber(word[right])) toAppend += word[right++];
    strs.push_back(toAppend);
    i = right;
    while(i < size && !isNumber(word[i])) i++;
  }
}

void upd(int pos, int value) {
  memo[pos][3] = (memo[pos-1][3] + value)%3;
  memo[pos][0] = memo[pos-1][0] + (memo[pos][3] == 0);
  memo[pos][1] = memo[pos-1][1] + (memo[pos][3] == 1);
  memo[pos][2] = memo[pos-1][2] + (memo[pos][3] == 2);
}

void clearMemo() {
  for(int i = 0; i < 4; i++)
    memo[0][i] = 0;
}

int getSum(int pos, string &s) {
  int my_previous_value = memo[pos-1][3];

  int ret = memo[s.size()][my_previous_value] - memo[pos-1][my_previous_value];
  
  return ret;
}

int main() {
  while(scanf("%s",word) != EOF) {
    strs.clear();
    breakString();
    long long sum = 0;
    for(int i = 0; i < strs.size(); i++) {
      string s = strs[i];

      clearMemo();
      upd(1,getNumber(s[0]));
      for(int i = 1; i < s.size(); i++)
        upd(i+1,s[i]);

      for(int i = 1; i <= s.size(); i++)
        sum += getSum(i,s);
    }
    printf("%lld\n",sum);
  }
}
