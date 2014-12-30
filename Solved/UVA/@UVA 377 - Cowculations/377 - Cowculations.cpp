#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;

typedef pair<char,char> cc;
typedef list<char>::iterator IT;

void pr(list<char> &l) {
  for(IT it = l.begin(); it != l.end(); it++)
    printf("%c",*it);
  puts("");
}

const int MAX = 1000;
const char SUM = 'A', SHIFT_RIGHT = 'R', SHIFT_LEFT = 'L';
const char VOID = 'Q';

char sum[120][120][2];

list<char> num1, num2, num3;
char word[MAX];

void init() {
  sum['V']['V'][0] = 'V'; sum['V']['V'][1] = VOID; 
  sum['V']['U'][0] = 'U'; sum['V']['U'][1] = VOID; 
  sum['V']['C'][0] = 'C'; sum['V']['C'][1] = VOID; 
  sum['V']['D'][0] = 'D'; sum['V']['D'][1] = VOID;
  sum['U']['V'][0] = 'U'; sum['U']['V'][1] = VOID; 
  sum['U']['U'][0] = 'C'; sum['U']['U'][1] = VOID; 
  sum['U']['C'][0] = 'D'; sum['U']['C'][1] = VOID; 
  sum['U']['D'][0] = 'V'; sum['U']['D'][1] = 'U';
  sum['C']['V'][0] = 'C'; sum['C']['V'][1] = VOID; 
  sum['C']['U'][0] = 'D'; sum['C']['U'][1] = VOID; 
  sum['C']['C'][0] = 'V'; sum['C']['C'][1] = 'U'; 
  sum['C']['D'][0] = 'U'; sum['C']['D'][1] = 'U';
  sum['D']['V'][0] = 'D'; sum['D']['V'][1] = VOID; 
  sum['D']['U'][0] = 'V'; sum['D']['U'][1] = 'U'; 
  sum['D']['C'][0] = 'U'; sum['D']['C'][1] = 'U'; 
  sum['D']['D'][0] = 'C'; sum['D']['D'][1] = 'U';
  sum['V'][VOID][0] = 'V'; sum['V'][VOID][1] = VOID;
  sum['U'][VOID][0] = 'U'; sum['U'][VOID][1] = VOID;
  sum['C'][VOID][0] = 'C'; sum['C'][VOID][1] = VOID;
  sum['D'][VOID][0] = 'D'; sum['D'][VOID][1] = VOID;
  sum[VOID]['V'][0] = 'V'; sum[VOID]['V'][1] = VOID;
  sum[VOID]['U'][0] = 'U'; sum[VOID]['U'][1] = VOID;
  sum[VOID]['C'][0] = 'C'; sum[VOID]['C'][1] = VOID;
  sum[VOID]['D'][0] = 'D'; sum[VOID]['D'][1] = VOID;
  sum[VOID][VOID][0] = sum[VOID][VOID][1] = VOID;
}

cc get_sum(char a, char b, char c) {
  char carry1 = sum[a][b][1];
  char carry2 = sum[sum[a][b][0]][c][1];
  char to_ret = sum[sum[a][b][0]][c][0];
  char to_car = sum[carry1][carry2][0];
  return cc(to_ret,to_car);
}

void operator_sum(list<char> &l1, list<char> &l2) {
  list<char> ret;
  IT it1 = l1.begin(), it2 = l2.begin();
  char carry = VOID;
  while(it1 != l1.end() || it2 != l2.end()) {
    char a, b;
    a = it1 == l1.end() ? VOID : *it1;
    b = it2 == l2.end() ? VOID : *it2;
    cc s = get_sum(a,b,carry);
    ret.push_back(s.first);
    carry = s.second;
    if(it1 != l1.end()) it1++;
    if(it2 != l2.end()) it2++;
  }
  if(carry != VOID)
    ret.push_back(carry);
  l2 = ret;
}

void operator_shift_right(list<char> &l) {
  IT it1 = l.begin();
  IT it2 = l.begin(); it2++;
  while(it2 != l.end()) {
    *it1 = *it2;
    it1++, it2++;
  }
  *it1 = 'V';
}

void operator_shift_left(list<char> &l) {
  l.push_front('V');
}

inline bool solve() { 
  for(int i = num2.size(); i < 8; i++)
    num2.push_back('V');
  return num2 == num3; 
}

void read(list<char> &l) {
  char c;
  while(scanf("%c",&c)) {
    if(c == '\n')
      break;
    l.push_front(c);
  }
}

int main() {
  init();
  printf("COWCULATIONS OUTPUT\n");
  int T; scanf("%d\n",&T);
  for(int i = 0; i < T; i++) {
    num1.clear(), num2.clear(), num3.clear();
    read(num1); read(num2);
    for(int i = 0; i < 3; i++) {
      char c; scanf("%c\n",&c);
      if(c == SUM)
        operator_sum(num1,num2);
      else if(c == SHIFT_RIGHT)
        operator_shift_right(num2);
      else if(c == SHIFT_LEFT)
        operator_shift_left(num2);
    }
    read(num3);
    printf("%s\n",solve() ? "YES" : "NO");
  }
  printf("END OF OUTPUT\n");
}
