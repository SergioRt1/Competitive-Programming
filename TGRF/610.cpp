#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
#define itloop(i,a) for(i = a.begin();i!=a.end();i++)
#define ms(a,b) memset(a,b,sizeof(a));
#define pb(a) push_back(a)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<ii> sii;
typedef sii::iterator it;

int n,m;
vvi graf;
sii ans;
int low[1001];
int disc[1001];
int act;

void dfs(int u, int pad){
    disc[u] = low[u] = act++;
    loop(i,0,graf[u].size()){
        int v = graf[u][i];
        if(pad == v)continue;
        if(disc[v] == -1){
            ans.insert(ii(u,v));
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(disc[u]<low[v]){
                ans.insert(ii(v,u));
            }
        }else{
            low[u] = min(low[u],disc[v]);
            if(ans.find(ii(v,u)) == ans.end()){
                ans.insert(ii(u,v));
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int u,v,cas = 0;
    while(scanf("%d %d",&n,&m) && n*m !=0){
        cas++;
        act = 0;
        graf.clear();
        graf.resize(n);
        ans.clear();
        ms(disc,-1);
        loop(i,0,m){
            scanf("%d %d",&u,&v);
            graf[u-1].pb(v-1);
            graf[v-1].pb(u-1);
        }
        loop(i,0,n){
            if(disc[i] == -1){
                dfs(i,-1);
            }
        }
        printf("%d\n\n",cas);
        it iter;
        itloop(iter,ans)printf("%d %d\n",iter->X+1,iter->Y+1);
        puts("#");
    }
    return 0;
}
