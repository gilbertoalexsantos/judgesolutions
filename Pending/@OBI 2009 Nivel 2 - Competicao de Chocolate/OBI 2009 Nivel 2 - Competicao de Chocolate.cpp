//Author: Gilberto A. dos Santos
//Website:  http://olimpiada.ic.unicamp.br/pratique/programacao/nivel2/2009f2p2_chocolate

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_BOLINHA = 1000005;
const char *WIN[2] = {"Paula","Carlos"};

inline bool even(int n) { return n % 2 == 0; }

bool add(int v, int qt=0) {
  if(even(v))
    return qt % 2 != 0;
  return add(v/2 + (v % 2 == 0),qt+1); 
}

int qt_bolinha, bolinha;

int main() {
  scanf("%d %d",&qt_bolinha,&bolinha);

  bool ans;

  if(bolinha >= qt_bolinha)
    ans = false;
  else if(qt_bolinha == bolinha + 1)
    ans = true;
  else {
    if(add(bolinha))
      qt_bolinha++, bolinha++;
    ans = qt_bolinha % (bolinha + 1) == 0;
  }

  printf("%s\n",WIN[ans]);
}
