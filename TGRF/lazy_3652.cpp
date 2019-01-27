#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++)
#define ms(a,b) memset(a,b,sizeof a)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int inf = 1<<30;

int C,F;
ii ini;
ii tar;
vvii buckets;
int dis[1005][1005];
int vis[1005][1005];

int cal[24] = { 7, 6, 5, 6, 7,
                6, 3, 2, 3, 6,
                5, 2,    2, 5,
                6, 3, 2, 3, 6,
                7, 6, 5, 6, 7};

int dix[24] = { -2,-2,-2,-2,-2,
                -1,-1,-1,-1,-1,
                0, 0,    0, 0,
                1, 1, 1, 1, 1,
                2, 2, 2, 2, 2};

int diy[24] = { -2,-1, 0, 1, 2,
                -2,-1, 0, 1, 2,
                -2,-1,    1, 2,
                -2,-1, 0, 1, 2,
                -2,-1, 0, 1, 2};

int dij(){
    int w = 7+1;
    buckets.clear();
    buckets.resize(w);
    int ib = 0;
    buckets[ib].push_back(ini);
    dis[ini.X][ini.Y]=0;
    bool found = false;
    int cont = 0;
    while(cont < w && !found){
        while(!buckets[ib].empty() && !found){
            cont = 0;
            ii u = buckets[ib].back(); buckets[ib].pop_back();
            if(vis[u.X][u.Y])continue;
            vis[u.X][u.Y]=true;
            if(u.X == tar.X && u.Y == tar.Y){
                found = true;
                break;
            }
            loop(i,0,24){
                ii v(u.X+dix[i],u.Y+diy[i]);
                if(0 <= v.X && v.X < F && 0 <= v.Y && v.Y < C && !vis[v.X][v.Y]){
                    if(dis[u.X][u.Y]+cal[i] < dis[v.X][v.Y]){
                        dis[v.X][v.Y] = dis[u.X][u.Y]+cal[i];
                        buckets[(ib+cal[i])%w].push_back(v);
                    }
                }
            }
        }
        ib=(ib+1)%w;
        cont++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(scanf("%d %d",&C,&F)==2 && (C|F)){
        scanf("%d %d %d %d",&ini.Y,&ini.X,&tar.Y,&tar.X);
        --ini.Y;--ini.X;--tar.Y;--tar.X;
        int w;
        scanf("%d",&w);
        loop(i,0,F)loop(j,0,C)dis[i][j]=inf;
        ms(vis,false);
        loop(k,0,w){
            int dx,dy,ix,iy;
            scanf("%d %d %d %d",&iy,&ix,&dy,&dx);
            loop(i,ix,dx+1)loop(j,iy,dy+1)vis[i-1][j-1]=true;
        }
        dij();
        if(dis[tar.X][tar.Y] == inf)puts("impossible");
        else printf("%d\n",dis[tar.X][tar.Y]);
    }
    return 0;
}
