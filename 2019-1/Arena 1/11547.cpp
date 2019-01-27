#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

int main(){
    int cas;
    scanf("%d",&cas);
    loop(i,0,cas){
        long long n;
        scanf("%lld",&n);
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        printf("%d\n",abs(n)%100/10);
    }
}
