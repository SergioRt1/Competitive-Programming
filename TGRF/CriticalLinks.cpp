#include <bits/stdc++.h>

#define loop(i,a,b) for(int i = a; i <b; i++)
#define X first
#define Y second
#define pb push_back
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef unordered_set<int> ui;
typedef unordered_map<int,int> mi;
typedef vector<ui> vui;
typedef ui::const_iterator itui;
typedef mi::const_iterator itmi;

const int inf = 1<<30;

int n,actDesc,numRoot;
vi low,disc;
mi pad;
vui graf;
vii ans;

int tarjan(int u){
    disc[u] = low[u] = actDesc++;
    loop(v,0,n){
        itui it = graf[u].find(v);
        itmi itu = pad.find(u);
        if(it != graf[u].end()){
            if(itu == pad.end()){
                pad[v] = u;
                tarjan(v);
                if(pad[u] == u)numRoot++;
                else if(disc[u] < low[v])ans.pb(ii(u,v));
                low[u] = min(low[u],low[v]);
            }else if(itu->Y != v){
                low[u] = min(low[u],disc[v]);
            }
        }
    }
}

int main(){
    while(scanf("%d",&n) == 1){
        graf.clear();
        pad.clear();
        actDesc = 0;
        loop(i,0,n){
            ui t;
            disc.pb(-1);
            low.pb(inf);
            graf.pb(t);
        }
        loop(i,0,n){
            int u,v,nnod;
            scanf("%d%d",u,nnod);
            loop(j,0,nnod) {
                scanf("%d",&v);
                graf[u].insert(v);
                graf[v].insert(u);
            }
            if(n > 0)tarjan(0);
            printf("%d critical links\n",ans.size());
            loop(j, 0, ans.size())printf("%d - %d\n",ans[j].X,ans[j].Y);
        }

    }
    return 0;
}
