#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)

using namespace std;

typedef long long large;

int b;
large f(int i){
    if(i<2)return i;
    int f0 = 0;
    int f1 = 1;
    int f2 ;
    loop(k,1,i){
        f2 = (f1+f0)%b;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d %d",&n,&b)==2){
        b = 1<<b;
        printf("%lld\n",f(n));
    }
    return 0;
}
