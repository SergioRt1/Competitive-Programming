#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define X first
#define Y second
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef deque<ii> di;

const int inf = 1<<30;

int h,w,xi,yi,xf,yf,len;
char mp[51][51];
int dxn[] = {-1,-1,-1,0,0,1,1,1};
int dyn[] = {-1,0,1,-1,1,-1,0,1,};
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int ts[12];
int disb[51][51];
int dis[11][11];
int dp[11][11];

int bfs(ii u){
    di Q;
    Q.push_back(u);
    int x,y;
    while(!Q.empty()){
        u = Q.front();
        Q.pop_front();
        loop(k,0,4){
            x = u.X+dx[k];
            y = u.Y+dy[k];
            if(0 <= x && x < h && 0 <= y && y < w && (mp[x][y] == '.' || mp[x][y] == '!' || mp[x][y] == '@') && disb[x][y] == -1){
                disb[x][y] = disb[u.X][u.Y]+1;
                if(x == xf && y == yf){
                    return disb[x][y];
                }
                Q.push_back(ii(x,y));
            }
        }
    }
    return inf;
}

int f(int bit){
    if(dp[bit] != -1)return dp[bit];
    int mi = inf;
    int ini = bit>>10&15;
    loop(i,0,len){
        if((bit>>i)&1){
            bit ^= bit&(1<<i);
            if(bit&( (1<<len)-1 )== 0)return dis[i][11];
            mi = min(mi,f(bit)+dis[ini][i]);
            bit |= 1<<i;
        }
    }
    return 0;
}

int main(){
    while(scanf("%d %d",&h,&w) == 2 && h+w != 0){
        loop(i,0,h)loop(j,0,w)cin>>mp[i][j];
        int x,y,ans = 0,k=0;
        loop(i,0,h)loop(j,0,w){
            if(mp[i][j] == '*'){
                loop(k,0,8){
                    x = i+dxn[k];
                    y = j+dyn[k];
                    if(0 <= x && x < h && 0 <= y && y < w){
                        if(mp[x][y] == '.')mp[x][y] = '#';
                        else if(mp[x][y] == '!')ans = -1;
                    }
                }
            }
            if(mp[i][j]=='!') ts[k++] = ii(i,j));
            if(mp[i][j]=='@'){
                xi = i;
                yi = j;
                ts[11] = ii(i,j);
            }
        }
        if(ans == -1){
            puts("-1");
        }else{
            memset(dis,-1,sizeof dis);
            len = 11;
            loop(i,0,len)loop(j,0,len){
                if(i == j) dis[i][j] = 0;
                else if(dis[j][i] != -1) dis[i][j] = dis[j][i];
                else{
                    memset(disb,-1,sizeof disb);
                    disb[ts[i].X][ts[i].Y] = 0;
                    xf = ts[j].X;
                    yf = ts[j].Y;
                    dis[i][j] = bfs(ts[i]);
                }
            }
            int bit = (1<<len)-1;
            bit |= 11<<10;
            memset(dp,-1,sizeof dp);
            printf("%d\n",f(bit));
        }


    }
    return 0;
}
