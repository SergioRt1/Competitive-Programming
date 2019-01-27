#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

vector<int> par;

int main(){
//    freopen("A.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,val;
    while(scanf("%d",&n)==1 && (n)){
        par.clear();
        par.push_back(0);
        loop(i,0,n){
            scanf("%d",&val);
            par.push_back(val);
        }
        par.push_back(1522);
        sort(par.begin(),par.end());
        bool ans = true;
        loop(i,1,par.size()){
            if(!ans)break;
            ans &= ( (par[i]-par[i-1])<=200);
        }
        if(ans)puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
    return 0;
}
