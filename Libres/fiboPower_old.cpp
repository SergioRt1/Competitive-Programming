#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long large;

const int km = 101;

int f1[km][km];
int k;

void mmult(int a[km][km], int b[km][km]){ //a=a*b
    int ans[km][km],r;
    loop(i,0,km)loop(j,0,km){
        r = 0;
        loop(k,0,km)r+=(large)a[i][k]*b[k][j]%1000000009;
        ans[i][j]=r%1000000009;
    }
    loop(i,0,km)loop(j,0,km)a[i][j]=ans[i][j];
}

void power(int a[km][km],large n){//a=a^n
    if(n<=1)return;
    power(a,n>>1);
    mmult(a,a);
    if(n&1)mmult(a,f1);
}

int fib(large n){
    int fn[km][km],base[km][km];
    memset(fn,0,sizeof fn);
    memset(base,0,sizeof base);
    loop(i,0,k)fn[0][i]=1;
    loop(i,0,k-1)fn[i+1][i]=1;
    loop(i,0,k)loop(j,0,k)f1[i][j]=fn[i][j];
    base[k-1][0]=1;
    rev(i,k-2,0)rev(j,k-1,i+1)base[i][0]+=base[j][0];
//    loop(i,0,k){loop(j,0,k)printf("%d ",fn[i][j]);puts("");}
//    loop(i,0,k){loop(j,0,k)printf("%d ",base[i][j]);puts("");}
    if(n < k)return base[k-n-1][0];
    power(fn,n-k+1);
    mmult(fn,base);
    return fn[0][0];
}

int main(){
    freopen("fibo.txt","r",stdin);
    freopen("out.txt","w",stdout);
    large n;
    while(scanf("%d %lld",&k,&n)==2 && (n|k)){
        cout<<fib(n)<<endl;
    }
    return 0;
}
