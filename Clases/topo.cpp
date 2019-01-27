#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

typedef vector<int> vi;

unordered_map<int,string> intst;
unordered_map<string,int> stint;

const int maxv = 1001;

vi graf[maxv];
vi topo;
bool vis[maxv];

int n,e;

int dfs(int u){
    vis[u] = true;
    loop(v,0,graf[u].size()){
        if(!vis[graf[u][v]]){
            dfs(graf[u][v]);
        }
    }
    printf("vis %d\n",u);
    topo.push_back(u);

}

int main(){
    freopen("in.txt","r",stdin);
    int cas = 0;
    while(scanf("%d",&n)==1){
        intst.clear();
        stint.clear();
        topo.clear();
        memset(graf,0,sizeof graf);
        memset(vis,false,sizeof vis);
        int curr = 0;
        string tmp;
        loop(i,0,n){
            cin>>tmp;
            intst[curr]=tmp;
            stint[tmp]=curr++;
        }
        scanf("%d",&e);
        string tmp2;
        loop(i,0,e){
            cin>>tmp;
            cin>>tmp2;
            graf[stint[tmp]].push_back(stint[tmp2]);
        }
        loop(i,0,n){
            if(!vis[i]){
                dfs(i);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",++cas);
        reverse(topo.begin(),topo.end());
        loop(i,0,topo.size()){
            printf(" %s",intst[topo[i]].c_str());
        }
        puts(".");
        puts("");
    }
    return 0;
}
