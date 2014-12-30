//Author:   Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1117
#include <cstdio>

int decimal(char ch) { return ch == '1'; }

int main()
{
    char ch;
    int segredo=131071,mod=0;
		while(1){
		 if(scanf("%c",&ch) == EOF) return 0;
		 if (ch=='#'){
			 if(mod)
			  printf("NO\n");
			 else
			  printf("YES\n");
			 mod = 0;
			 continue;
		 }
		 mod = (mod*2 + decimal(ch)) % segredo;
	    }

    return 0;
}
