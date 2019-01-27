#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define ms(a,b) memset(a,b,sizeof a)

using namespace std;

vector<int> st;
int n;
int dp[60][60];


int f(int i, int j){
    if(i+1==j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 1<<30;
    loop(k,i+1,j)ans = min(ans,f(i,k)+f(k,j));
    ans=ans+st[j]-st[i];
    return dp[i][j] = ans;
}

void solve(){
    loop(i,0,n+1)dp[i][i+1]=0;
    loop(d,2,n+1)loop(i,0,n+1d-d){
        int j = i+d;
        int ans = 1<<30;
        loop(k,i+1,j)ans = min(ans,dp[i][k]+dp[k][j]);
        ans=ans+st[j]-st[i];
        dp[i][j]=ans;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int l;
    while(scanf("%d",&l)==1 & (l!=0)){
        st.clear();
        st.push_back(0);
        ms(dp,-1);
        scanf("%d",&n);
        int val;
        loop(i,0,n){
            scanf("%d",&val);
            st.push_back(val);
        }
        st.push_back(l);
        n++;
        solve();
        int ans = dp[0][n];
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
