//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/PT07Y/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int N,M,u,v;
list<int> array[10000 + 1];

void DFS(int vertice)
{
  array[vertice].pop_back();
  array[vertice].push_back(1);
  list<int>::iterator it;
  for(it = array[vertice].begin(); it != array[vertice].end(); it++)
  {
    if(array[*it].back() != 1)
    {DFS(*it);}
  }   
}

int main()
{   
    scanf("%d%d",&N,&M);
    if( (N-1) != M )
    {cout << "NO"; return 0;}
    else
    {
      for(int i = 1; i <= M; i++)
      {
        scanf("%d%d",&u,&v);
        array[u].push_back(v);
        array[v].push_back(u);       
      }
      //Marcando "0" nos vértices          
      for(int i = 1; i <= M+1; i++)
      {array[i].push_back(0);}
    }
    DFS(1);
    for(int i = 1; i <= M; i++)
    {
      if(array[i].back() == 0)
      {cout << "NO"; return 0;}
    }
    cout << "YES";
    return 0;
}