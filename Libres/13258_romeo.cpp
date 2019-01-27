#include <bits/stdc++.h>
#define loop(i,a,b) for(int i= a;i<b;i++)
#define revp(i,a,b) for(int i=b-1;i>=a;i--)

using namespace std;

const int MAX = 100005;

string P,T;
int b[MAX],br[MAX];
int err1[MAX],err2[MAX];
bool vis[MAX];
int m,n,k;

void kmpError(){
    int j = -1;
    loop(i,0,m){
        if(j>=0 && P[i]==P[j])b[i] = b[j];
        else b[i] = j;
        while(j>=0 && P[i] != P[j]) j = b[j];
        j++;
    }
}

int rev(int i,int b){
    return (b-i-1)%(b+1);
}

void kmpErrorRev(){
    int j = -1;
    loop(i,0,m){
        if(j>=0 && P[rev(i,m)]==P[rev(j,m)])br[i] = br[j];
        else br[i] = j;
        while(j>=0 && P[rev(i,m)]!=P[rev(j,m)]) j = br[j];
        j++;
    }
}

void kmp(){
    int j = 0;
    loop(i,0,n){
        while(j>=0 && T[i]!=P[j])j = b[j];
        j++;
        err1[i] = j;
        if(j == m)j = b[j];
    }
}

void kmpRev(){
    int j = 0;
    revp(i,0,n){
        while(j>=0 && T[i]!=P[rev(j,m)])j = br[j];
        j++;
        err2[i] = j;
        if(j == m)j = br[j];
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int ca;
    scanf("%d",&ca);
    loop(cas,0,ca){
        cin>>T>>P;
        cin>>k;
        memset(b,0,sizeof b);
        memset(br,0,sizeof br);
        memset(vis,false,sizeof vis);
        memset(err1,0,sizeof err1);
        memset(err2,0,sizeof err2);
        m = P.size();
        n = T.size();
        kmpError();
        kmp();
        kmpErrorRev();
        kmpRev();
        int ans = 0;
        int tes;
        loop(i,0,n){
            if(i+k < n && err1[i]+k == m && !vis[i-err1[i]+1]){
                ans++;
                vis[i-err1[i]+1] = true;
                tes = i-err1[i]+1;

            }
            if(i+k+1 < n && err1[i]+err2[i+k+1]+k == m && !vis[i-err1[i]+1]){
                ans++;
                vis[i-err1[i]+1] = true;
                tes = i-err1[i]+1;
            }
            if(i-k >= 0 && err2[i]+k == m && !vis[i-k]){
                ans++;
                vis[i-k] = true;
                tes = i-k;
            }
            if(k == m && i <= n-k && !vis[i]){
                ans++;
                vis[i]=true;
                tes = i;
            }

        }

        printf("%d\n",ans);
//        loop(i,0,n)printf("%d",err1[i]);puts("");
//        loop(i,0,n)printf("%d",err2[i]);puts("");
//        loop(i,0,n)printf("%d",vis[i]);puts("");
    }
    string s;

    return 0;
}
