#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

const int inf = 1<<30;

int dis[12][12];
int dp[12][2050];
int N,M,n;
vii nod;

int f(int i, int mask){
    if(mask == (1<<n)-1){
        return dis[i][0];
    }
    if(dp[i][mask] != -1)return dp[i][mask];
    int ans = inf;
    loop(k,1,n)if(k!=i && !(mask>>k&1) ){
        ans = min(ans,f(k,mask|(1<<k))+dis[i][k]);
    }
    return dp[i][mask] = ans;
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int cas,ix,iy;
    scanf("%d",&cas);
    loop(ca,0,cas){
        nod.clear();
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&N,&M);
        scanf("%d %d",&ix,&iy);
        nod.push_back(ii(ix,iy));
        scanf("%d",&n);
        loop(i,0,n){
            scanf("%d %d",&ix,&iy);
            nod.push_back(ii(ix,iy));
        }
        n++;
        loop(i,0,n)loop(j,0,n){
            dis[i][j] = abs(nod[i].X-nod[j].X)+abs(nod[i].Y-nod[j].Y);
        }
        printf("The shortest path has length %d\n",f(0,1));

    }
    return 0;
}
