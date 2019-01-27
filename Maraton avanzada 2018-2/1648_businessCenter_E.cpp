#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

const int inf = 1<<30;

int n,m,up,down;

int eval(int x){
    return up*x-down*n+down*x;
}
int bina(int lo, int hi){
    //printf("Bina (%d, %d)\n",lo,hi);
    if(lo+1 >= hi)return hi;
    int x = (lo+hi)>>1;
    int ans = eval(x);
    if(ans == 0) return x+1;
    if(ans < 0) return bina(x,hi);
    if(ans > 0) return bina(lo,x);
}

int main(){
    //freopen("E.txt","r",stdin);
    //freopen("eo.txt","w",stdout);
    int cas = 0;
    while(scanf("%d %d",&n,&m)==2){
        int minv = inf;
        loop(i,0,m){
            scanf("%d %d",&up,&down);
            int b = bina(0,n);
            //printf("b: %d\n",b);
            minv = min(minv,eval(b));
        }
        printf("%d\n",minv);
    }
    return 0;
}
