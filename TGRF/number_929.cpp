#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++)
#define ms(a,b) memset(a,b,sizeof a)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef deque<ii> qii;
typedef vector<qii> vqii;

const int inf = 1<<30;

int C,F;
ii ini;
ii tar;
vqii buckets;
int dis[1005][1005];
int vis[1005][1005];
int maze[1005][1005];

int dix[4] = {-1,0,0,1};

int diy[4] = {0,-1,1,0};

int dij(){
    int w = 9+1;
    buckets.clear();
    buckets.resize(w);
    int ib = 0;
    buckets[ib].push_back(ini);
    dis[ini.X][ini.Y]=maze[ini.X][ini.Y];
    bool found = false;
    while(!found){
        while(!buckets[ib].empty() && !found){
            ii u = buckets[ib].front(); buckets[ib].pop_front();
            if(vis[u.X][u.Y])continue;
            vis[u.X][u.Y]=true;
            if(u.X == tar.X && u.Y == tar.Y){
                found = true;
                break;
            }
            loop(i,0,4){
                ii v(u.X+dix[i],u.Y+diy[i]);
                if(0 <= v.X && v.X < F && 0 <= v.Y && v.Y < C && !vis[v.X][v.Y]){
                    if(dis[u.X][u.Y]+maze[v.X][v.Y] < dis[v.X][v.Y]){
                        dis[v.X][v.Y] = dis[u.X][u.Y]+maze[v.X][v.Y];
                        buckets[(ib+maze[v.X][v.Y])%w].push_back(v);
                    }
                }
            }
        }
        ib=(ib+1)%w;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cast;
    scanf("%d",&cast);
    loop(cas,0,cast){
        scanf("%d %d",&F,&C);
        loop(i,0,F)loop(j,0,C){
            scanf("%d",&maze[i][j]);
            dis[i][j]=inf;
            vis[i][j]=false;
        }
        ini = ii(0,0);
        tar = ii(F-1,C-1);
        dij();
        printf("%d\n",dis[F-1][C-1]);
    }
    return 0;
}
