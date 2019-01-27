#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)

using namespace std;

const int inf = 1<<30;

int n,x;
int val[105];

int dp[105][10000];

int f(int i, int por, bool isValid){
    if(i == x)return f(i+1,por+val[i],true)+val[i];
    if(por > 5000)return 0;
    if(i >= n)return inf;
    if(dp[i][por] != -1)return dp[i][por];
    return dp[i][por] = min(f(i+1,por+val[i],isValid)+val[i],f(i+1,por,isValid));
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    float tm;
    while(scanf("%d %d",&n,&x) == 2 && (n|x)){
        memset(dp,-1,sizeof dp);
        x--;
        loop(i,0,n) {
            scanf("%f",&tm);
            val[i] = tm*100.0+0.5;
        }
        int tot = f(0,0,false);
        double ans = val[x]*100.0/(double)tot;
        printf("%.2f\n",ans);
    }
    return 0;
}
