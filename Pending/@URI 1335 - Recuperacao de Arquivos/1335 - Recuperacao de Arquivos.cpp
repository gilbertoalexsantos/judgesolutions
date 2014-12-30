//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1335

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 10005;

int f;

int main() {
  while(scanf("%d",&f) && f) {
    char **word;    
    word = new char*[f+1];
    for(int i = 0; i < f; i++) {
      word[i] = new char[sizeof(char) * MAX];
      scanf("%s",word[i]);
    }
  } 
} 
