#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

large dp[45];

large f(int n){
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1)+f(n-2)*4+f(n-3)*2;
}

int main(){
    int cas, n;
    scanf("%d",&cas);
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    loop(ca,0,cas){
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
