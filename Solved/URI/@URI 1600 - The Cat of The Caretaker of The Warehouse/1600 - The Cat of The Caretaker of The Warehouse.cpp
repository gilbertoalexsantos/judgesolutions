//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1600

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;

struct STATE {
  ii pc, pb;
  int mask, dist;

  STATE(ii pc=ii(0,0), ii pb=ii(0,0), int mask=0, int dist=0)
    :  pc(pc),pb(pb),mask(mask),dist(dist) {}
  bool operator< (const STATE &other) const { return dist < other.dist; }
};

typedef pair<int, STATE> is;

const int MAX = 26;
const int INF = 1e9;
const char WALL = '*', EMPTY = '.', CAT = 'j', BLOCK = 'b', SINK = 'x', DOOR = '#';
const int dr[] = {0, 1,  0, -1};
const int dc[] = {1, 0, -1,  0};

int memo[MAX][MAX][MAX][MAX][1 << 5];
char grid[MAX][MAX];
int n, m;
map<ii, int> MAP;
ii source, sink, block;

inline int getDist(ii a, ii b, int mask) { return memo[a.first][a.second][b.first][b.second][mask]; }
inline void setDist(ii a, ii b, int mask, int w) { memo[a.first][a.second][b.first][b.second][mask] = w; }

inline bool can(ii p) { return p.first >= 0 & p.first < n && p.second >= 0 && p.second < m; }
inline char what(ii p) { return grid[p.first][p.second]; }
inline int getIndDoor(ii p) { return MAP.find(p)->second; }
inline bool doorOpen(ii p, int mask) { return mask & 1 << getIndDoor(p); }
inline bool isBlock(ii p, ii b) { return p == b; }

int getQtDoor(int mask) {
  int ret = 0;
  for(int i = 0; i < 5; i++)
    ret += (mask & (1 << i) ? 1 : 0);
  return ret;
}

ii bfs() {
  memset(memo,-1,sizeof memo);
  priority_queue<is> pq;
  pq.push(is(0,STATE(source,block,0,0)));
  setDist(source,block,0,0);
  while(!pq.empty()) {
    ii pc = pq.top().second.pc, pb = pq.top().second.pb;
    int mask = pq.top().second.mask, ds = -pq.top().second.dist; pq.pop();
    int qtDoor = getQtDoor(mask);

    // printf("(%d,%d) (%d,%d) => (%d,%d)\n",pc.first,pc.second,
    //     pb.first,pb.second,qtDoor,ds);


    if(pb == sink)
      return ii(qtDoor, ds);


    for(int i = 0; i < 4; i++) {
      ii npc = ii(pc.first+dr[i],pc.second+dc[i]);
      if(!can(npc)) continue;
      char c = what(npc);
      // BLOCK
      if(isBlock(npc,pb)) {
        ii npb = ii(pb.first+dr[i],pb.second+dc[i]);
        if(!can(npb)) continue;
        char new_c = what(npb);
        if(new_c != WALL) {
          if((new_c == DOOR && !doorOpen(npb,mask)))
            continue;
          if(getDist(npc,npb,mask) == -1) {
            setDist(npc,npb,mask,ds+1);
            pq.push(is(-qtDoor,STATE(npc,npb,mask,-(ds+1))));
          } else if(getDist(npc,npb,mask) > ds+1) {
            setDist(npc,npb,mask,ds+1);
            pq.push(is(-qtDoor,STATE(npc,npb,mask,-(ds+1))));
          }
        }
      }
      // EMPTY
      else if(c != WALL) {
        int new_mask = mask, offset = 0;
        if(c == DOOR) {
          int indDoor = getIndDoor(npc);
          new_mask = mask | (1 << indDoor);
          offset = !(mask & (1 << indDoor));
        }
        int newQtDoor = qtDoor + offset;
        if(getDist(npc,pb,new_mask) == -1) {
          setDist(npc,pb,new_mask,ds+1);
          pq.push(is(-newQtDoor,STATE(npc,pb,new_mask,-(ds+1))));
        } else if(getDist(npc,pb,new_mask) > ds+1) {
          setDist(npc,pb,new_mask,ds+1);
          pq.push(is(-newQtDoor,STATE(npc,pb,new_mask,-(ds+1))));
        }
      }
    }
  }

  return ii(-1,-1);
}

int main() {
  while(scanf("%d %d",&n,&m) != EOF) {
    MAP.clear();
    for(int i = 0; i < n; i++)
      scanf("%s",grid[i]);
    int cnt = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
      ii p = ii(i,j);
      if(grid[i][j] == CAT)
        source = p;
      else if(grid[i][j] == SINK)
        sink = p;
      else if(grid[i][j] == DOOR)
        MAP.insert(make_pair(p,cnt++));
      else if(grid[i][j] == BLOCK)
        block = p;
    }
    ii ans = bfs();
    ans.first == -1 ? printf("-1\n") : printf("%d %d\n",ans.first,ans.second);
  }
}
