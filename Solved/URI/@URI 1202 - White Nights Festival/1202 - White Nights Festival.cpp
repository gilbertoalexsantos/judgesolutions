#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int fib[1500];
char inst[10001];
int potencia[100001];

int getnum() {
  int ret = 0;
  for(int i = strlen(inst)-1, pos=0; i >= 0; i--, pos++) 
    if(inst[i] == '1')
      ret = (ret + potencia[pos]) % 1500;
  return ret;
}

int initPotencia(int v) {
  if(potencia[v] != -1)
    return potencia[v];

  int left = v / 2;
  int right = v / 2 + (v % 2 != 0);
  return potencia[v] = (initPotencia(left) * initPotencia(right)) % 1500;
}

void init() {
  memset(potencia,-1,sizeof potencia);
  fib[0] = 0; fib[1] = 1;
  for (int i = 2; i < 1500; i++)
    fib[i] = (fib[i-1] + fib[i-2]) % 1000;
  potencia[0] = 1; potencia[1] = 2;
  for(int i = 2; i < 100001; i++)
    initPotencia(i);
}

int main(){
  init();
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%s",inst);
    int n_term = getnum();
    printf("%03d\n",fib[n_term]);
  }
}
