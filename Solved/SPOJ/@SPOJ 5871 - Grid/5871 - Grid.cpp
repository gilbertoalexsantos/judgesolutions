//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/GRID/

#include <stdio.h>
#include <string.h>
int dp[1001][1001];

int main(){
   int t,a,b,k,i,j;
   scanf("%d",&t);
   while(t--){
   scanf("%d %d %d", &a, &b, &k);
   memset( dp , 0, sizeof dp );
   dp[0][0] = 1;

  for (i = 0 ; i <= a ; i++)
   for (j = 0 ; j <= b ; j++) {
     if ( i > 0 )
      dp[i][j] += dp[i-1][j];
     if ( j > 0 )
      dp[i][j] += dp[i][j-1];

     dp[i][j] %= k;
   }

  printf("%d\n", dp[a][b]);
 }
 return 0;
}
