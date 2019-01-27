#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,act,nHijos;
int low[101],num[101],pad[101];
bool graf[101][101],isArt[101];

void tarjan(int u){
    num[u] = low[u] = act++;
    loop(v,1,n+1){
        if(graf[u][v]){
            if(num[v]==-1){
                pad[v] = u;
                tarjan(v);
                if(pad[u]==u)nHijos++;
                else if(num[u]<=low[v]){
                    isArt[u] = true;
                }
                if(low[u]>low[v])low[u]=low[v];
            }else if(pad[u]!=v){
                if(low[u]>num[v])low[u]=num[v];
            }
        }
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int u,v;
    string line;
    stringstream ss;
    while(scanf("%d",&n)==1 && n!=0){
        memset(graf,false,sizeof graf);
        memset(pad,-1,sizeof pad);
        memset(low,-1,sizeof low);
        memset(num,-1,sizeof num);
        memset(isArt,false,sizeof isArt);
        getline(cin,line);
//        cout<<"line0: ->"<<line<<"<-"<<endl;
        while(true){
            ss.clear();
            getline(cin,line);
//            cout<<"line n: ->"<<line<<"<-"<<endl;
            ss<<line;
            ss>>u;
            if(u==0)break;
            while(ss>>v){
                graf[u][v]=true;
                graf[v][u]=true;
            }
        }
        loop(i,1,n+1){
            if(pad[i]==-1){
                pad[i] = i;
                act = 1;
                nHijos = 0;
                tarjan(i);
                isArt[i]=(nHijos>1);
            }
        }
//        printf("P Art:");
        int ans = 0;
//        loop(i,0,n+1)if(isArt[i])printf(" %d",i);
//        puts("");
        loop(i,0,n+1)if(isArt[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
